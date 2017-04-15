void setup() {
 // Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }

  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);
  // Hostname defaults to esp8266-[ChipID]
  ArduinoOTA.setHostname("nodemcu-icm01");
  // No authentication by default
  ArduinoOTA.setPassword(senha_ota);
  ArduinoOTA.onStart([]() {
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  //Serial.println("Ready");
  //Serial.print("IP address: ");
  //Serial.println(WiFi.localIP());
  
  //// Sensor Temperatura ////
  pinMode(pinTemp, INPUT);


    //// PIR ////
  pinMode(pinPir, INPUT_PULLUP);

  //// Atuadores Relay ////
  pinMode(pinRele1, OUTPUT);
  digitalWrite(pinRele1, LOW);
  pinMode(pinRele2, OUTPUT);
  digitalWrite(pinRele2, LOW);
  pinMode(pinRele3, OUTPUT);
  digitalWrite(pinRele3, LOW);
  pinMode(pinRele4, OUTPUT);
  digitalWrite(pinRele4, LOW);  

  //// Botão ////
  pinMode(pinBotao1, INPUT_PULLUP);
  pinMode(pinBotao2, INPUT_PULLUP);
  pinMode(pinBotao3, INPUT_PULLUP);
  pinMode(pinBotao4, INPUT_PULLUP);

    
  //// MQTT ////
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop() {
  ArduinoOTA.handle();
  mqtt_loop();
  pir_loop();
  verifica_botao();
  temperatura_loop();
}
