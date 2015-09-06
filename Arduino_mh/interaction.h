
boolean havePublic() {
 return true;
}

int getKeyValue()
{
    int pinVal;
    pinVal = analogRead(keypadPin);
    return pinVal;
}



void botonera()
{
    if(blockKeyboard != true ){
      
    val = getKeyValue();
      //Serial.println("value: "+String(val));
        if(val >= 221 & val < 235){ val = 1;}else
        if(val >= 200 & val < 220){ val = 2;}else
        if(val >= 187 & val < 200){ val = 3;}else
        if(val >= 170 & val < 185){ val = 4;}else
        if(val >= 151 & val < 162){ val = 5;}else
        if(val >= 130 & val < 141){ val = 6;}else
        if(val >= 100 & val < 125){ val = 7;}else
        if(val >= 87 & val < 95)  { val = 8;}else
        if(val >= 60 & val < 70)  { val = 9;}else
        if(val >= 38 & val < 50)  { val = 10;}else
        if(val >= 10 & val < 20)  { val = 11;}
        if(val != lsVal & val < 12){
          switch(val){
            case 1:  { viasAct[0] = 1; viasTime[0]=defaultEventTime; viasValues[0] = 0; wtv020sd16p.playVoice(0); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 1");bTime = blockTime; blockKeyboard = true; break;}
            case 2:  { viasAct[1] = 1; viasTime[1]=defaultEventTime; viasValues[1] = 0; wtv020sd16p.playVoice(1); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 2");bTime = blockTime; blockKeyboard = true; break;}
            case 3:  { viasAct[2] = 1; viasTime[2]=defaultEventTime; viasValues[2] = 0; wtv020sd16p.playVoice(2); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 3");bTime = blockTime; blockKeyboard = true; break;}
            case 5:  { viasAct[3] = 1; viasTime[3]=defaultEventTime; viasValues[3] = 0; wtv020sd16p.playVoice(3); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 4");bTime = blockTime; blockKeyboard = true; break;}
            case 4:  { viasAct[4] = 1; viasTime[4]=defaultEventTime; viasValues[4] = 0; wtv020sd16p.playVoice(4); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 5");bTime = blockTime; blockKeyboard = true; break;}
            case 6:  { viasAct[5] = 1; viasTime[5]=defaultEventTime; viasValues[5] = 0; wtv020sd16p.playVoice(5); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 6");bTime = blockTime; blockKeyboard = true; break;}
            case 7:  { viasAct[6] = 1; viasTime[6]=defaultEventTime; viasValues[6] = 0; wtv020sd16p.playVoice(6); soundRunTime = audioDefaultTime; playing=true; Serial.println(">>CMD: LS 7");bTime = blockTime; blockKeyboard = true; break;}
            case 8:  { wtv020sd16p.playVoice(7);  soundRunTime = audioDefaultTime; playing=true; Serial.println("JUST SOUND SAMPLE 1");bTime = blockTime; blockKeyboard = true; break;}
            case 9:  { wtv020sd16p.playVoice(8);  soundRunTime = audioDefaultTime; playing=true; Serial.println("JUST SOUND SAMPLE 2");bTime = blockTime; blockKeyboard = true; break;}
            case 10: { wtv020sd16p.playVoice(9);  soundRunTime = audioDefaultTime; playing=true; Serial.println("JUST SOUND SAMPLE 3");bTime = blockTime; blockKeyboard = true; break;}
            case 11: { wtv020sd16p.playVoice(10); soundRunTime = audioDefaultTime; playing=true; Serial.println("JUST SOUND SAMPLE 4");bTime = blockTime; blockKeyboard = true; break;}
          }
          lsVal = val;
        }

    }
   char r;
  if (Serial.available() > 0 ){
    r = Serial.read();
  }
  if(r == '1'){viasAct[0] = 1; viasTime[0]=defaultEventTime; Serial.println(">>CMD: LS 1");}
  if(r == '2'){viasAct[1] = 1; viasTime[1]=defaultEventTime; Serial.println(">>CMD: LS 2");}
  if(r == '3'){viasAct[2] = 1; viasTime[2]=defaultEventTime; Serial.println(">>CMD: LS 3");}
  if(r == '4'){viasAct[3] = 1; viasTime[3]=defaultEventTime; Serial.println(">>CMD: LS 4");}
  if(r == '5'){viasAct[4] = 1; viasTime[4]=defaultEventTime; Serial.println(">>CMD: LS 5");}
  if(r == '6'){viasAct[5] = 1; viasTime[5]=defaultEventTime; Serial.println(">>CMD: LS 6");}
  if(r == '7'){viasAct[6] = 1; viasTime[6]=defaultEventTime; Serial.println(">>CMD: LS 7");} 
  if(r == 'l' || r == 'L'){logEnable = !logEnable;}
    
}







