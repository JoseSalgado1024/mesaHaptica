#include "Arduino.h"
#include <Thread.h>
#include <Wtv020sd16p.h>
#include <ThreadController.h>
#include "config.h"
#include "interaction.h"
ThreadController controll = ThreadController();


void setup() {
  logs("-----------| Mesa haptica |-----------");
  logs("Starting up...", true);
  pinMode(keypadPin, INPUT_PULLUP); 
  pinMode(usPinTrig, OUTPUT);
  pinMode(usPinEcho, INPUT);
  Thread* myThread = new Thread();
  myThread->onRun(generalClock);
  myThread->setInterval(eventIt);
  controll.add(myThread);

  logs("All Threads are done!... at: " + String(eventIt) + "ms", true);
  prepareClockThreads();//CREATE AND START CLOCK THREAD
  prepareVias();//INIT LED STRIP VIAS
  wtv020sd16p.reset();//START AUDIO DEVICE
}

void generalClock() {
  for(int i = 0; i < maxVias; i++){
    if(viasTime[i] > 0){
      viasTime[i] =  viasTime[i]-eventIt ; 
    }
   } 
  if(soundRunTime > 0 & playing == true){
    soundRunTime -= eventIt;
  }else{
    playing = false;
//    wtv020sd16p.stopVoice();
  }
  
  if(bTime > 0){
    bTime -= eventIt; 
  } else {
    blockKeyboard = false;
    lsVal = -1;
  }
  
  //hi ext
  if(uSonicInt > 1){
    //DEC TIME
    uSonicInt-= eventIt;
  } else{
   //READ SENSOR & CREATE DELAY TIME
  // Serial.println("HAVE USER?");
   uSonicInt = defaultTimeUSonic;
  digitalWrite(usPinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(usPinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(usPinTrig, LOW);
  duration = pulseIn(usPinEcho, HIGH);
  distance = duration / 58.2; 
   if (distance <= maximumRange & distance >= minimumRange & distance < 15 ) {
        goAway = false; 
       //logs("USER AT: "+String(distance)+"cms.");
    } else {goAway = true;}
    if(goAway == false & iSaidHello == false & distance < minUserDist & wcTime < 1){
        //So.. say hi!
        iSaidHello = true; 
        wtv020sd16p.playVoice(helloSound);
        logs("HELLO USER!");
        uSonicInt = defaultTimeUSonic;
        wcTime = wellcomeTime;
    }else {
      wcTime -= eventIt;
    }
   if(goAway == true & iSaidHello == true){
        iSaidHello = false;
   }
  }
}

void loop() {
  /* REMOVEME! */
  controll.run();
  if (havePublic() == true) {
    botonera();
    for(int i = 0; i < maxVias; i++){
      if(viasAct[i] == lightOn){if(viasValues[i] < 255) {viasValues[i] += lsFadeMod;} else{viasAct[i] = lightHold;viasValues[i] = 255;} ledStripsControll(vias[i], viasValues[i]); 
        for(int j = 0 ; j < maxVias; j++){
          if(j != i){
            if(viasAct[j]==lightOn || viasAct[j] == lightHold){
              viasAct[j]  = lightOff;

            }
           }
        }
      }
      else if(viasAct[i] == lightHold){ if((viasTime[i]-eventIt*12) <= 0) {viasAct[i] = lightOff;} }
      else if(viasAct[i]==lightOff){if(viasValues[i] > 0){viasValues[i] -= lsFadeMod;}
                                      else{viasAct[i] = lightIdle;
                                      viasTime[i]=0;
                                      viasValues[i]=0;} 
                                      ledStripsControll(vias[i], viasValues[i]);  
                                    }
      else{ledStripsControll(vias[i], 0); }
       
    }
  }

  /* FOO TEST */
}


void logs(String msg) {
  logs(msg, false);
}


void logs(String msg, boolean dl) {
  if(logEnable == true){
    if (serialReady == false ) {
      Serial.begin(9600);
      serialReady = !serialReady;
    }
    Serial.print(">> \"");
    Serial.print(msg);
    dl == true ? Serial.print("\"\n") : Serial.print("\"");
    Serial.println();
  }
}


void ledStripsControll(int via, int value ) {
  analogWrite(via, value);
}

void prepareVias() {
  logs("Setting up vias LS");
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
  logs("All vias are ready!", true);

}

void sayHiCallBack()
{

  
}


long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

void prepareClockThreads(){

}
