/*
 * modified from http://playground.arduino.cc/Code/NewPing
*/

#include <NewPing.h>

#define GREEN_LED 10
#define YELLOW_LED 9
#define RED_LED 8
#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 
void setup() {
   Serial.begin(9600);
}
 
void loop() {
   delay(50);
   unsigned int dis = sonar.ping_cm();
   Serial.print(dis);
   Serial.println("cm");
   if(dis > 10) {
    digitalWrite(GREEN_LED,HIGH);
    digitalWrite(YELLOW_LED,LOW);
    digitalWrite(RED_LED,LOW);
   } else if(dis > 5) {
    digitalWrite(GREEN_LED,LOW);
    digitalWrite(YELLOW_LED,HIGH);
    digitalWrite(RED_LED,LOW);
   } else {
    digitalWrite(GREEN_LED,LOW);
    digitalWrite(YELLOW_LED,LOW);
    digitalWrite(RED_LED,HIGH);
   }
}
