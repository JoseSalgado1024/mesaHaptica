
//LOGS CONF
boolean logEnable   = true;
boolean serialReady = false;

//THREADS CONF


//EVENT CONFS
#define eventIt 100
#define defaultEventTime 4000//4 SECONDS!
#define noEvent   -1
#define lightOn    1
#define lightHold  0
#define lightOff  -1
#define lightIdle -2



//LEDS CONF
#define maxVias 7
#define lsFadeMod 5
int vias[maxVias]       = { 2, 3, 4, 5, 6, 7,8};
int viasAct[maxVias]    = { lightIdle, lightIdle, lightIdle, lightIdle, lightIdle, lightIdle, lightIdle};
int viasTime[maxVias]   = { 0, 0, 0, 0, 0, 0,0};
int viasValues[maxVias] = { 0, 0, 0, 0, 0, 0,0};



//ARRAY BUTTONS
const byte keypadPin = A0;
int val = -1;
int lsVal =-1;
boolean blockKeyboard = false;
#define blockTime 700;
int bTime;  

char customKey = 0xff;


//SOUND CONFIGS
int resetPin = 22;  // The pin number of the reset pin.
int clockPin = 24;  // The pin number of the clock pin.
int dataPin = 26;  // The pin number of the data pin.
int busyPin = 28;  // The pin number of the busy pin.
Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);
#define audioDefaultTime 4000;
int soundRunTime = 0;
boolean playing = false;

//PUBLIC CONFS
const int usPinEcho = 10;
const int usPinTrig = 9;
#define helloSound 11
#define wellcomeTime 2000
#define minUserDist  30
#define defaultTimeUSonic 1000
boolean iSaidHello = false;
int wcTime = 0;
boolean goAway = true;
int uSonicInt = 0;
long duration, distance;
int maximumRange = 100; // Maximum range needed
int minimumRange = 0;
