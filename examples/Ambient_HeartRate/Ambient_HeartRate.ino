#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Ticker.h>
#include "Ambient.h"

extern "C" {
#include "user_interface.h"
}

#define _DEBUG 1
#if _DEBUG
#define DBG(...) { Serial.print(__VA_ARGS__); }
#define DBGLED(...) { digitalWrite(__VA_ARGS__); }
#else
#define DBG(...)
#define DBGLED(...)
#endif /* _DBG */

#define LED 4

#define PERIOD 5

const char* ssid = "・・・ssid・・・";
const char* password = "・・・パスワード・・・";
WiFiClient client;

#define SAMPLING 5  //  Sampling period in milliseconds
#define NSAMPLES 600  //  Number of Samples
#define BUFSIZE  17000

unsigned int channelId = 100;
const char* writeKey = "ライトキー";
Ambient ambient;

Ticker t2;
volatile int done = false;
unsigned int signal[NSAMPLES];
int sampleIndex = 0;
char buffer[BUFSIZE];

void sampling() {
    DBGLED(LED, HIGH);
    signal[sampleIndex++] = system_adc_read();
    if (sampleIndex >= NSAMPLES) {
        done = true;
        DBGLED(LED, LOW);
    }
}

void setup()
{
    wifi_set_sleep_type(LIGHT_SLEEP_T);

#ifdef _DEBUG
    Serial.begin(115200);
    delay(20);
#endif
    DBG("Start\r\n");
    pinMode(LED, OUTPUT);

    WiFi.begin(ssid, password);

    int i = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);

        DBGLED(LED, i++ % 2);
        DBG(".");
    }

    DBGLED(LED, LOW);
    DBG("WiFi connected\r\nIP address: ");
    DBG(WiFi.localIP());
    DBG("\r\n");

    ambient.begin(channelId, writeKey, &client);

    DBG("sampling start...");
    t2.attach_ms(SAMPLING, sampling);
    while (!done) {
        delay(0);
    }
    t2.detach();
    DBG("done\r\n");

    sprintf(buffer, "{\"writeKey\":\"%s\",\"data\":[", writeKey);
    for (int i = 0; i < NSAMPLES; i++) {
        sprintf(&buffer[strlen(buffer)], "{\"created\":%d,\"d%d\":%d},", SAMPLING * i, 1, signal[i]);
    }
    buffer[strlen(buffer)-1] = '\0';
    sprintf(&buffer[strlen(buffer)], "]}\r\n");
    
    DBG("buf: ");DBG(strlen(buffer));DBG(" bytes\r\n");
    
    int sent = ambient.bulk_send(buffer);
    DBG("sent: ");DBG(sent);DBG("\r\n");
}

void loop()
{
    delay(0);
}

