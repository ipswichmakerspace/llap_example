#include <LLAPSerial.h>
#include <Wire.h>

#define DEVICEID "FC"  // this is the LLAP device ID

void setup() {
  Serial.begin(115200);
  pinMode(8,OUTPUT);    // switch on the radio
  digitalWrite(8,HIGH);
  pinMode(4,OUTPUT);    // switch on the radio
  digitalWrite(4,LOW);  // ensure the radio is not sleeping
  delay(1000);        // allow the radio to startup
  LLAP.init(DEVICEID);
  LLAP.sendMessage(F("STARTED"));
}

void loop(){
  delay(1000);  // Pause for 1 second.
  LLAP.sendMessage(F("PING"));
}

