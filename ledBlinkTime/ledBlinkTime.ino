/*

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13. Change the amount of time the LED is on and off when you press a button.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 Pullupp-switch

 This code is in the public domain.
 */

// constants won't change.
// Seting pin numbers:
const int addButtonPin = 2;     // the number of the pushbutton pin for the increase blinktime button
const int deButtonPin = 3;    // the number of the pushbutton pin for the decrease blinktime button
const int ledPin =  13;      // the number of the LED pin

// these variables can change
boolean addButtonValue = true;   //Current add button value
boolean deButtonValue = true; //Current decrease button value
boolean ledState = true;
int ledBlinkTime = 0; //Current time to wait before next led blink

// Data type void has no return value
void setup() { // Setup runs a single time
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pins as an input_pullup (eliminates the need for a external resistor):
  pinMode(addButtonPin, INPUT_PULLUP);
  pinMode(deButtonPin, INPUT_PULLUP);
  Serial.begin(9600); // Initate serial communication at 9600 baud rate
}

void loop() { // loop runs forever, basically an infinite while loop
  // read the state of the pushbutton value, write the value to its respective variable:
  addButtonValue = digitalRead(addButtonPin); //Copy button value to the variable
  deButtonValue = digitalRead(deButtonPin); //Copy button value to the variable
  if (!addButtonValue) { //Check if the button is pressed
      ledBlinkTime += 10; //add delay value
    }
  if (!deButtonValue) { //Check if the button is pressed
      ledBlinkTime -= 10; //decrease delay value
    }
  ledState = !ledState; // assign the invertet value of ledState to ledState
  ledBlinkTime = constrain(ledBlinkTime, 0, 30000); // Constrain ledBlinkTime between 0 and 30000
  digitalWrite(ledPin, ledState); //Write the values
  delay(ledBlinkTime);  //Pause the program for ledBlinkTime milliSeconds
  Serial.println(ledBlinkTime); //Print the value of ledBlinkTime in the serial stream
}
