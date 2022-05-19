#include <Arduino.h>
#define numberOfCountries 5

const int onOffButton = 2;
const int minusButton = 3;
const int plusButton = 4;
const int confirmButton = 5;
const int connectedMapToggler = 6;

enum Country
{
  Poland,
  France,
  Switzerland,
  Spain,
  Estonia
};

enum CountryStatus
{
  available,
  obtained
};

struct CountryStruct
{
  Country country;
  CountryStatus status;
  int port;
};

// TODO: Read from EEPROM memory!
CountryStruct countries[numberOfCountries] =
    {{Poland, available, 7},
     {France, available, 8},
     {Switzerland, available, 9},
     {Spain, available, 10},
     {Estonia, available, 11}};

void setup()
{
  // Serial for debug
  Serial.begin(9600);

  // Buttons and potentiometer
  pinMode(onOffButton, INPUT);
  pinMode(minusButton, INPUT);
  pinMode(plusButton, INPUT);
  pinMode(confirmButton, INPUT);
  pinMode(connectedMapToggler, INPUT);

  // Country LEDs
  pinMode(countries[0].port, OUTPUT);
  pinMode(countries[1].port, OUTPUT);
  pinMode(countries[2].port, OUTPUT);
  pinMode(countries[3].port, OUTPUT);
  pinMode(countries[4].port, OUTPUT);
}

void loop()
{
  digitalWrite(countries[1].port, HIGH);
  digitalWrite(countries[2].port, HIGH);
  delay(1000);
  digitalWrite(countries[1].port, LOW);
  Serial.println("yooo");
  delay(1000);
}
