# Ambient_ESP8266_lib

[Ambient](https://ambidata.io)はIoT用のクラウドサービスです。 マイコンから送られたデーターを受信し、蓄積し、可視化(グラフ化)します。ここではArduino ESP8266用のライブラリーとサンプルを示しています。サンプルには次のプログラムがあります。

* 環境モニター: ESP8266と温度・湿度センサーのHDC1000を使い、温度、湿度を測定し、Ambientに送信してモニターします。
* 心拍モニター: ESP8266と心拍センサーを使い、心拍波形をグラフ化します。
* 消費電流モニター: ESP8266と電流値モジュールINA226PRCを使い、マイコンの消費電流をモニターします。

## 材料

* Ambient.h: Ambient用のヘッダーファイル
* Ambient.cpp: Ambientライブラリーのソースファイル
* examples/Ambient_ESP8266: 環境モニターのソースファイル
* examples/Ambient_HeartBeat: 心拍モニターのソースファイル
* examples/Ambient_CurrentLogger: 消費電流モニターのソースファイル

ライブラリーのインポート方法、サンプルプログラムの動かし方は[Ambientサイト](https://ambidata.io/docs/esp8266/)に書きましたので、ご参照ください。
