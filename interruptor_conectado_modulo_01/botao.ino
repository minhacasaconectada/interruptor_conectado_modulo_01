void verifica_botao(){
  long now = millis();  

  readingBotao1 = digitalRead(pinBotao1);
  if(readingBotao1 != botao1OldState){
      debounceTimeBotao1 = now;
  }
  if(now - debounceTimeBotao1 > 50){
    if(readingBotao1 != botao1State){
      botao1State = readingBotao1;
      if(botao1State == LOW){
        if(digitalRead(pinRele1) == LOW){
          digitalWrite(pinRele1, HIGH);
          client.publish(rele1_state_topic, off_cmd);
        } else {
          digitalWrite(pinRele1, LOW);
          client.publish(rele1_state_topic, on_cmd);
        }
      }
    }
  }
  botao1OldState = readingBotao1;

  readingBotao2 = digitalRead(pinBotao2);
  if(readingBotao2 != botao2OldState){
      debounceTimeBotao2 = now;
  }
  if(now - debounceTimeBotao2 > 50){
    if(readingBotao2 != botao2State){
      botao2State = readingBotao2;
      if(botao2State == LOW){
        if(digitalRead(pinRele2) == LOW){
          digitalWrite(pinRele2, HIGH);
          client.publish(rele2_state_topic, off_cmd);
        } else {
          digitalWrite(pinRele2, LOW);
          client.publish(rele2_state_topic, on_cmd);
        }
      }
    }
  }
  botao2OldState = readingBotao2;

  readingBotao3 = digitalRead(pinBotao3);
  if(readingBotao3 != botao3OldState){
      debounceTimeBotao3 = now;
  }
  if(now - debounceTimeBotao3 > 50){
    if(readingBotao3 != botao3State){
      botao3State = readingBotao3;
      if(botao3State == LOW){
        if(digitalRead(pinRele3) == LOW){
          digitalWrite(pinRele3, HIGH);
          client.publish(rele3_state_topic, off_cmd);
        } else {
          digitalWrite(pinRele3, LOW);
          client.publish(rele3_state_topic, on_cmd);
        }
      }
    }
  }
  botao3OldState = readingBotao3;

  readingBotao4 = digitalRead(pinBotao4);
  if(readingBotao4 != botao4OldState){
      debounceTimeBotao4 = now;
  }
  if(now - debounceTimeBotao4 > 50){
    if(readingBotao4 != botao4State){
      botao4State = readingBotao4;
      if(botao4State == LOW){
        if(digitalRead(pinRele4) == LOW){
          digitalWrite(pinRele4, HIGH);
          client.publish(rele4_state_topic, off_cmd);
        } else {
          digitalWrite(pinRele4, LOW);
          client.publish(rele4_state_topic, on_cmd);
        }
      }
    }
  }
  botao4OldState = readingBotao4;
   
  
}



