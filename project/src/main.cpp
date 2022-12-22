#include <Arduino.h>
#define LED_BUILTIN 2

int ldrPin = 34; // LDR is connected to analog pin 34
int motorPin = 14; // DC motor is connected to digital pin 26

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(ldrPin, INPUT); // Set LDR pin as input
  pinMode(motorPin, OUTPUT); // Set motor pin as output
  pinMode(LED_BUILTIN, OUTPUT); // Set motor pin as output
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Read LDR value
  Serial.println(ldrValue); // Print LDR value to serial monitor
  delay(1000);
  if (ldrValue <= 500){
    analogWrite(motorPin, 0); // Turn motor on
    delay(10000); // Wait for 1 second
    analogWrite(motorPin, 255);
    //delay(1000);
  }
  else {
    analogWrite(motorPin, 255);
  }
  if (ldrValue <= 500){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(3000);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
