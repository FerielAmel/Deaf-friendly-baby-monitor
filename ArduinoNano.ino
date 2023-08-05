#include <SoftwareSerial.h>
#define ON_LED 2 //LED pin
#define VIBRATION 3 //Vibration motor pin

//This is the serial communication line between the Arduino Nano and the ESP8266
SoftwareSerial mySerial(10, 11); //RX, TX

void setup() {
  //Open serial communications and wait for port to open
  Serial.begin(9600);
  /*Set the data rate for the SoftwareSerial port*/
  mySerial.begin(9600);
  pinMode(ON_LED, OUTPUT); /*Define the LED pin as output*/
  pinMode(VIBRATION, OUTPUT); /*Define the vibration motor pin as output*/
  digitalWrite(ON_LED, HIGH); /*As long as the bracelet is on, the LED is on*/
}

void loop() { //Run over and over
  //If an element is on the serial line
  if (mySerial.available()) {
    char ser = mySerial.read();
    digitalWrite(VIBRATION, HIGH); //Produce a vibration
    delay(2000);
    digitalWrite(VIBRATION, LOW); //Stop the vibration
    } 
}
