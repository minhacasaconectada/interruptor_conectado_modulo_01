/*
 * Jonathas Eide Fujii
 * jonathasfujii@gmail.com
 * 01/01/2017
 * 
 * Arduino IDE v1.8.0
 */

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ArduinoJson.h> // https://github.com/bblanchon/ArduinoJson
#include <PubSubClient.h> // http://pubsubclient.knolleary.net/
#include <OneWire.h>
#include <DallasTemperature.h>

const byte pinLedEsp = 2;

//// WIFI ////
const char* ssid = "";
const char* password = "";
const char* senha_ota = "";

//// MQTT ////
const char* mqtt_server = "192.168.1.16";
const char* mqtt_username = "";
const char* mqtt_password = "";
const char* client_id = "nodemcu-icm01"; // Must be unique on the MQTT network
const char* start_state_topic = "casa/icm01/start";
const char* temperatura_state_topic = "casa/icm01/temperatura";
const char* pir_state_topic = "casa/icm01/pir";
const char* rele1_state_topic = "casa/icm01/rele1";
const char* rele1_set_topic = "casa/icm01/rele1/set";
const char* rele2_state_topic = "casa/icm01/rele2";
const char* rele2_set_topic = "casa/icm01/rele2/set";
const char* rele3_state_topic = "casa/icm01/rele3";
const char* rele3_set_topic = "casa/icm01/rele3/set";
const char* rele4_state_topic = "casa/icm01/rele4";
const char* rele4_set_topic = "casa/icm01/rele4/set";
const char* on_cmd = "ON";
const char* off_cmd = "OFF";

WiFiClient espClient;
PubSubClient client(espClient);

//// Sensor Temperatura ////
const byte pinTemp = A0;
long lastTimeTemp = 0;
float temp = 0;
long sleepTemp = 60000; // 1 minuto

//// Sensor PIR ////
const byte pinPir = 16;
byte pirOldState = LOW;
//const int sleepPir = 60;
//long lastTimerPir = 0;

//// Atuadores Relay ////
const byte pinRele1 = 14;
const byte pinRele2 = 12;
const byte pinRele3 = 13;
const byte pinRele4 = 3;

//// Botão ////
const byte pinBotao1 = 5;
const byte pinBotao2 = 4;
const byte pinBotao3 = 0;
const byte pinBotao4 = 2;

byte botao1OldState = HIGH;
byte botao2OldState = HIGH;
byte botao3OldState = HIGH;
byte botao4OldState = HIGH;

long debounceTimeBotao1 = 0;
long debounceTimeBotao2 = 0;
long debounceTimeBotao3 = 0;
long debounceTimeBotao4 = 0;


