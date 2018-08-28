#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>

int main(int argc, char const *argv[]) {
  /* Code for the GPIO program for the
  vertical farm.
  Author: Karl Emil Jeppesen
  Date 28.8.2018.

  Inputs:
  Temperature sensor
  Humidity sensor
  Water level sensor
  pH meter
  EC meter

  Outputs:
  Water pump ON/OFF
  LED lights
  Drain pump
  Fan for temp/humidity
  */

  //Water pump timing: ON 4 mins. OFF 6 mins.
  //Logic is a delay in the program.

  //LED LIGHTS setup
  //LEDs are on all the time

  int ledNumber = 27;
  pinMode (ledNumber, OUTPUT);
  digitalWrite(ledNumber, HIGH);
  //maybe code an OFF button

for (;;) { //start of inf. loop
  //TODO: change this to exit by button press

  int programIteration = 1;

  wiringPiSetupGpio () ; //broadcom setup (17, 18, 27)

  //WATER PUMP SETUP

  int pumpNumber = 17;
  pinMode (pumpNumber, OUTPUT);

  if (programIteration <= 4) {
    digitalWrite (pumpNumber, HIGH) ;
  } else {
    digitalWrite (pumpNumber, LOW) ;
    if (programIteration == 10) {
      programIteration = 0;
    }
  }
  programIteration++;

  //Safety measure for water level
  int waterLevelNumber = 22;
  pinMode (waterLevelNumber, INPUT); //level should be 1 (true)
  if (digitalRead (waterLevelNumber == 0)) {
    digitalWrite(pumpNumber, LOW); //turns off pump
  }

  int temperatureNumber = 24;
  pinMode(temperatureNumber, INPUT);
  temperature = digitalRead(temperatureNumber);

  int fanNumber = 23;
  pinMode(fanNumber, OUTPUT);
  //temperature = 1 means it is too hot
  if (temperature = 1) {
    digitalWrite(fanNumber, HIGH);
  } else {
    digitalWrite(fanNumber, LOW);
  }

  //Program delay of one minute
  delay(1000*60); //1000ms x 60 sec. per min.

} //end of infinite loop
  //wiringPi cleanup
  pinMode(pumpNumber, INPUT);
  pinMode(ledNumber, INPUT);
  pinMode(fanNumber, INPUT);

  return EXIT_SUCCESS;
}
