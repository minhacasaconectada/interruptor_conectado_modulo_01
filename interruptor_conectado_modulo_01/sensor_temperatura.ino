
void temperatura_loop(){
  long now = millis();
  
  if (now - lastTimeTemp > sleepTemp) {
    lastTimeTemp = now;
    temp = (analogRead(pinTemp) * 330.0f) / 1023.0f;
    //Serial.println(temp);
    if((temp > -20) && (temp <100)){
      client.publish(temperatura_state_topic, String(temp).c_str(),TRUE);
    }
  }
}

