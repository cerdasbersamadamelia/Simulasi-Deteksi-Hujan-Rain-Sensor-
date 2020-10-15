#define rainSensorPin 2
#define rainSensorPower 7
#define relayPin 10
#include "pitches.h"

int speaker = 11;
int rainVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(speaker,OUTPUT); 
  pinMode(rainSensorPower, OUTPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(rainSensorPower, LOW); // initially keep the sensor
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  rainVal = readSensor(); // get reading from the function below and print
  Serial.print("Digital Output: ");
  Serial.println(rainVal);

  //Determine status of rain
  if(rainVal)
  {
    Serial.println("Status: Hujan..Hujan...Turun Lagi");
    digitalWrite(relayPin, HIGH);
    song();
  }
  else
  {
    Serial.println("Status: Aman Bray");
    digitalWrite(relayPin, LOW);
  }
  delay(1000);
  Serial.println();
}

// this function returns the sensor output
int readSensor()
{
  digitalWrite(rainSensorPower, HIGH); //turn the sensor On
  delay(10);
  int val = digitalRead(rainSensorPin);
  digitalWrite(rainSensorPower, LOW);
  return val;
}

void song(){
  tone(speaker, 262); delay(100);
  tone(speaker, 294); delay(100);
  tone(speaker, 330); delay(100);
  tone(speaker, 349); delay(100);
  tone(speaker, 395); delay(100);
  tone(speaker, 440); delay(100);
  tone(speaker, 494); delay(100);
  tone(speaker, 523); delay(100);
}
