#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#define FPSerial Serial1
DFRobotDFPlayerMini myDFPlayer;

const int button1 = 28;
const int button2 = 29;
const int button3 = 30;
const int button4 = 25;
const int button5 = 26;
const int button6 = 27;
const int button7 = 22;
const int button8 = 23;
const int button9 = 24;

void setup() {
  FPSerial.begin(9600);
  Serial.begin(115200);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);
  pinMode(button9, INPUT_PULLUP);




  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
}

void loop() {
  int button1State = digitalRead(button1);
  int button2State = digitalRead(button2);
  int button3State = digitalRead(button3);
  int button4State = digitalRead(button4);
  int button5State = digitalRead(button5);
  int button6State = digitalRead(button6);
  int button7State = digitalRead(button7);
  int button8State = digitalRead(button8);
  int button9State = digitalRead(button9);

  if (button1State == LOW) {
    Serial.println("btn1");
    myDFPlayer.stop();
    delay(200);
    myDFPlayer.enableLoop();
    delay(500);
    myDFPlayer.play(1); 
    
  }

  if (button2State == LOW) {
    Serial.println("btn2");
    myDFPlayer.stop();
    delay(200);
    myDFPlayer.enableLoop();
    delay(500);
    myDFPlayer.play(2); 
  }

  if (button3State == LOW) {
    Serial.println("btn3");
    myDFPlayer.stop();
    delay(200);
    myDFPlayer.enableLoop();
    delay(500);
    myDFPlayer.play(3); 
  }

  if (button4State == LOW) {
    Serial.println("btn4");
    myDFPlayer.stop();
    delay(500);
    myDFPlayer.play(4); 
  }
  
  if (button5State == LOW) {
    Serial.println("btn5");
    myDFPlayer.stop();
    delay(500);
    myDFPlayer.play(5); 
  }
  
  if (button6State == LOW) {
     Serial.println("btn6");
  }

  if (button7State == LOW) {
     Serial.println("btn7");
  }

  if (button8State == LOW) {
     Serial.println("btn8");
  }

  if (button9State == LOW) {
     Serial.println("btn9");
     myDFPlayer.stop();
  }

  delay(200);
}
