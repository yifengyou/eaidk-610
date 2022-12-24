语音相关代码

==================================================================================================================================================
package dependencies:
[PLAY, RECORD]--libalsa: sudo dnf install alsa-lib-devel-1.1.6-2.fc28.aarch64 -y
[PLAY]--sox: sudo dnf install sox -y  && pip3 install sox --user
[PLAY, RECORD]--pyalsaaudio: pip3 install pyalsaaudio --user
###[PLAY]--sudo dnf install ffmpeg-devel-3.3.7-2.rockchip.fc28.aarch64 -y
[PLAY, ENC]--ffmpeg with libmp3lame: 
	firstly, install libmp3lame: sudo dnf install lame lame-devel -y && sudo dnf install libvorbis-devel-1\:1.3.6-1.fc28.aarch64 -y
	then, sudo dnf install ffmpeg ffmpeg-devel
	Now install finished.
[DEC]--ffmpeg: sudo dnf install ffmpeg ffmpeg-devel
[PLAY, ENC, DEC]--pydub: pip3 install pydub --user
[PLAY]--portaudio: sudo dnf install portaudio-devel-19-27.fc28.aarch64  -y
[PLAY]--pyaudio: pip3 install pyaudio --user
[AEC]--speexdsp: sudo dnf install speexdsp-devel-1.2-0.13.rc3.fc28.aarch64
[AEC]--pyspeexdsp: pip3 install --user --use-wheel --no-index --find-links=/path/to/pyESP/tools/speexdsp-0.1.1-cp36-cp36m-linux_aarch64.whl speexdsp
	      OR 
	      pip3 install --user speexdsp
[AGC]--matplotlib: sudo dnf install libjpeg-turbo-devel -y && pip3 install --user matplotlib
[BEAMFORM, DENOISE]--scipy: sudo dnf install python3-scipy -y
[BEAMFORM, DENOISE]--pyroomacoustics: pip3 install --user pyroomacoustics
[BEAMFORM]--pybind11: pip3 install --user pybind11
[VAD]--py-webrtcvad: pip3 install --user webrtcvad
[VCS]--soundstretch: pip3 install soundstretch --user
[TTS]--espeak: sudo dnf install espeak -y
[TTS]--pyttsx3eaidk: pip3 install --user pyttsx3eaidk

==================================================================================================================================================

note:
1. ENCODE supported format: mp3  ac3  flac mp4 
