/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 Pullupp-switch

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.

 This example code is in the public domain.
 */

// constants won't change. They're used here to
// set pin numbers:
const int addButtonPin = 2;     // the number of the pushbutton pin
const int deButtonPin = 3;
const int ledPin =  5;      // the number of the LED pin

boolean addButtonValue = true;   //Current add button value
boolean deButtonValue = true; //Current decrease button value
int ledBlinkTime = 1; //Current time to wait before next led blink

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(addButtonPin, INPUT_PULLUP);
  pinMode(deButtonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value, write the opposite value to ledPin:
  addButtonValue = digitalRead(addButtonPin); //Copy button value to the variable
  deButtonValue = digitalRead(deButtonPin); //Copy button value to the variable
  if (!addButtonValue) { //Check if the button is pressed
      ledBlinkTime += 16; //add pwm value
    }
  if (!deButtonValue) { //Check if the button is pressed
      ledBlinkTime -= 16; //de pwm value
    }
  ledBlinkTime = constrain(ledBlinkTime, 1, 100000);
  digitalWrite(ledPin, HIGH); //Write the values
  delay(ledBlinkTime);  //Pause the program for ledBlinkTime
  digitalWrite(ledPin, LOW); //Write the values
  delay(ledBlinkTime);  //Pauses for the time ledBlinkTime
  Serial.println(ledBlinkTime); //Pause the program for ledBlinkTime
}
