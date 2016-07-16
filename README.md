# Ambient_ESP8266_lib

[Ambient](https://ambidata.io)はIoT用のクラウドサービスです。 マイコンから送られたデーターを受信し、蓄積し、可視化(グラフ化)します。ここではArduino ESP8266用のライブラリーとサンプルを示しています。サンプルではESP8266と温度、湿度センサーのHDC1000を使い、温度、湿度を測定し、Ambientに送信しています。

## 材料

* Ambient.h: Ambient用のヘッダーファイル
* Ambient.cpp: Ambientライブラリーのソースファイル
* examples/Ambient_ESP8266: Arduino ESP8266と温度、湿度センサーHDC1000を使い、温度、湿度を測定し、Ambientに送信するサンプルプログラム
* examples/Ambient_HeartBeat: Arduino ESP8266と心拍センサーを使い、心拍データーをAmbientに送り、波形をグラフ化するサンプルプログラム

ライブラリーのインポート方法、サンプルプログラムの動かし方は[Ambientサイト](https://ambidata.io/docs/esp8266/)に書きましたので、ご参照ください。
