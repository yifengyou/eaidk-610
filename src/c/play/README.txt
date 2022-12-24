案例运行方法：
1.进入ESP/platform，在控制台输入./compile.sh play编译平台
2.进入ESP/case/speech/play文件夹下，输入./compile.sh编译案例
3.进入ESP/case/speech/play/build文件夹，将你需要播放的pcm文件放入此文件夹内，用./play sample.pcm sample.wav运行此案例。
  sample.pcm是利用录音功能生成的pcm文件，sample.wav是由sample.pcm转化得来的.wav文件。
4.用ctrl+c结束运行