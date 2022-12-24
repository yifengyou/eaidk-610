#include <unistd.h>
#include <iostream>
#include <fstream>
#include <alsa/asoundlib.h>
#include <sys/time.h>

static char* device=NULL;


int capture_task()
{
        snd_pcm_t *handle;
        snd_pcm_hw_params_t *params;
        char *buffer;
        int ret, size, dir;
        unsigned int sample_rate = 16000;
        snd_pcm_uframes_t frames = 320;
        snd_pcm_uframes_t buffer_size = frames*4;
        struct timeval t1,t2;
        std::ofstream pcm_file("save.pcm", std::ios::binary);
        if(!pcm_file.is_open())
        {
                std::cout << "failed to open " << "save.pcm\n";
        }
        ret = snd_pcm_open(&handle, device,SND_PCM_STREAM_CAPTURE, 0);
        if(ret < 0)
        {
                std::cout << "Capture unable to open pcm device: " << device<< " " << snd_strerror(ret) << std::endl;
                return -1;
        }
        /* Allocate a hardware parameters object. */
        snd_pcm_hw_params_alloca(&params);

        /* Fill it in with default values. */
        snd_pcm_hw_params_any(handle, params);


        /* Set the desired hardware parameters. */

        /* Interleaved mode */
        snd_pcm_hw_params_set_access(handle, params,SND_PCM_ACCESS_RW_INTERLEAVED);

        /* Signed 16-bit little-endian format */
        snd_pcm_hw_params_set_format(handle, params,SND_PCM_FORMAT_S16_LE);
        snd_pcm_hw_params_set_channels(handle, params, 2);

        snd_pcm_hw_params_set_rate_near(handle, params, &sample_rate, &dir);


        snd_pcm_hw_params_set_period_size_near(handle, params, &frames, &dir);

        snd_pcm_hw_params_set_buffer_size_near(handle, params,&buffer_size);
        ret = snd_pcm_hw_params(handle, params);
        if(ret < 0)
        {
                std::cout << "unable to set hw parameters: " << snd_strerror(ret) << std::endl;
                return -2;
        }
		unsigned int rate_setted = 0;
		snd_pcm_hw_params_get_rate(params,&rate_setted, &dir);
        printf("rate:%d\n",rate_setted);
		
		unsigned int channels_setted = 0;
		snd_pcm_hw_params_get_channels(params,&channels_setted);
        printf("channels:%d\n",channels_setted);
		
		snd_pcm_format_t format_setted = SND_PCM_FORMAT_UNKNOWN;
		snd_pcm_hw_params_get_format(params,&format_setted);
        printf("format:%d\n",format_setted);
		
		snd_pcm_uframes_t buffer_size_setted = 0;
		snd_pcm_hw_params_get_buffer_size(params,&buffer_size_setted);
        printf("buffer_size:%d\n",buffer_size_setted);
		
        snd_pcm_hw_params_get_period_size(params,&frames, &dir);
		printf("frames:%d\n",frames);
        size = frames*4;
        buffer = new char[size];

        gettimeofday(&t1, NULL);
        while (1)
        {
                gettimeofday(&t2, NULL);
                if (((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec)) / 1000 > 5*1000)
                {
                    break;
                }

                ret = snd_pcm_readi(handle, buffer, frames);
                if (ret == -EPIPE)
                {
                        std::cout << "overrun occurred\n";
                        snd_pcm_prepare(handle);
                }
                else if (ret == -ESTRPIPE)
                {
                        while ((ret = snd_pcm_resume(handle)) == -EAGAIN)
                                sleep(1);
                        if(ret < 0)
                        {
                                if ((ret = snd_pcm_prepare(handle)) < 0) 
                                {
                                        std::cout << "snd_pcm_prepare error\n";
                                }
                        }
                }
                else if (ret < 0)
                {
                        std::cout << "error from snd_pcm_readi: " << snd_strerror(ret) << std::endl;
                }
                else if (ret != (int)frames) {
                        std::cout << "snd_pcm_readi error, only read ret=" <<ret <<" vs " << frames << " frame\n";
                }

                if(ret > 0)
                {
                    pcm_file.write(buffer, ret*2*channels_setted);
                    pcm_file.flush();
                }
        }
        pcm_file.close();
        snd_pcm_drain(handle);
        snd_pcm_close(handle);
        delete [] buffer;
        return 0;
}
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("usage: %s device\n like %s MainMicCapture\n", argv[0],argv[0]);
		return -1;
	}
	
	device = argv[1];
    capture_task();
    return 0;
}