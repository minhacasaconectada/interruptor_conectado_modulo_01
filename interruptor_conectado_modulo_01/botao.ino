void verifica_botao(){
  long now = millis();  

  if(digitalRead(pinBotao1) != botao1OldState){
    botao1Cont = true;
    debounceTimeBotao1 = now;
    botao1OldState = digitalRead(pinBotao1);
  } else if(botao1Cont && now - debounceTimeBotao1 > 200){
    if(digitalRead(pinBotao1) == LOW){
      digitalWrite(pinRele1, LOW);
      client.publish(rele1_state_topic, on_cmd);
    } else {
      digitalWrite(pinRele1, HIGH);
      client.publish(rele1_state_topic, off_cmd);
    }
    botao1Cont = false;
  }
  
  if(digitalRead(pinBotao2) != botao2OldState){
    botao2Cont = true;
    debounceTimeBotao2 = now;
    botao2OldState = digitalRead(pinBotao2);
  } else if(botao2Cont && now - debounceTimeBotao2 > 200){
    if(digitalRead(pinBotao2) == LOW){
      digitalWrite(pinRele2, LOW);
      client.publish(rele2_state_topic, on_cmd);
    } else {
      digitalWrite(pinRele2, HIGH);
      client.publish(rele2_state_topic, off_cmd);
    }
    botao2Cont = false;
  }
  
  if(digitalRead(pinBotao3) != botao3OldState){
    botao3Cont = true;
    debounceTimeBotao3 = now;
    botao3OldState = digitalRead(pinBotao3);
  } else if(botao3Cont && now - debounceTimeBotao3 > 200){
    if(digitalRead(pinBotao3) == LOW){
      digitalWrite(pinRele3, LOW);
      client.publish(rele3_state_topic, on_cmd);
    } else {
      digitalWrite(pinRele3, HIGH);
      client.publish(rele3_state_topic, off_cmd);
    }
    botao3Cont = false;
  }
  
  if(digitalRead(pinBotao4) != botao4OldState){
    botao4Cont = true;
    debounceTimeBotao4 = now;
    botao4OldState = digitalRead(pinBotao4);
  } else if(botao4Cont && now - debounceTimeBotao4 > 200){
    if(digitalRead(pinBotao4) == LOW){
      digitalWrite(pinRele4, LOW);
      client.publish(rele4_state_topic, on_cmd);
    } else {
      digitalWrite(pinRele4, HIGH);
      client.publish(rele4_state_topic, off_cmd);
    }
    botao4Cont = false;
  }
  
}



