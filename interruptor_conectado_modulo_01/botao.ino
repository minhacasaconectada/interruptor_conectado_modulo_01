void verifica_botao(){
  long now = millis();  
  
  if(now - debounceTimeBotao1 > 50 && digitalRead(pinBotao1) != botao1OldState) {
    if(digitalRead(pinBotao1) == LOW){
      digitalWrite(pinRele1, LOW);
      
      client.publish(rele1_state_topic, on_cmd);
    } else {
      digitalWrite(pinRele1, HIGH);
      client.publish(rele1_state_topic, off_cmd);
    }
    botao1OldState = !botao1OldState;
  }

  if(now - debounceTimeBotao2 > 50 && digitalRead(pinBotao2) != botao2OldState) {
    if(digitalRead(pinBotao2) == LOW){
      digitalWrite(pinRele2, LOW);
      client.publish(rele2_state_topic, on_cmd);
    } else {
      digitalWrite(pinRele2, HIGH);
      client.publish(rele2_state_topic, off_cmd);
    }
    botao2OldState = !botao2OldState;
  }

  if(now - debounceTimeBotao3 > 50 && digitalRead(pinBotao3) != botao3OldState) {
    if(digitalRead(pinBotao3) == LOW){
      digitalWrite(pinRele3, LOW);
      client.publish(rele3_state_topic, on_cmd);
    } else {
      digitalWrite(pinRele3, HIGH);
      client.publish(rele3_state_topic, off_cmd);
    }
    botao3OldState = !botao3OldState;
  }

  if(now - debounceTimeBotao4 > 50 && digitalRead(pinBotao4) != botao4OldState) {
    if(digitalRead(pinBotao4) == LOW){
      digitalWrite(pinRele4, LOW);
      client.publish(rele4_state_topic, on_cmd);
    } else {
      digitalWrite(pinRele4, HIGH);
      client.publish(rele4_state_topic, off_cmd);
    }
    botao4OldState = !botao4OldState;
  }
  
}



