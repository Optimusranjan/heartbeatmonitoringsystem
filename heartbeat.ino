//for heartbeat
#include <LiquidCrystal.h>

int heartBeat = A0;
double alpha = 0.75;
int period = 100;
double change = 0.0;
double oldValue = 0.0;

//for lcd Display
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  pinMode(heartBeat, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
//    lcd.print("hello, world!");
}

void loop() {
  // put your main cod76e here, to run repeatedly for heaertBeat:

  int rawValue = analogRead (heartBeat);                                         // Reading the sensors values

  double value = alpha * oldValue + (1 - alpha) * rawValue;         // calculating values using the formula
  //  Serial.print (rawValue);              // printing the sensor output value on the screen
  //  Serial.print (",");
  //  Serial.println (value);             // printing the heart beat value on the screen
  oldValue = value;
  Serial.println(oldValue);
  delay (period);

  //LCD Display
  lcd.setCursor(0, 1);

}
