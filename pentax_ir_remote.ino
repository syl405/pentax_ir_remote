/*******************************************
 *
 * Name.......:  multiCameraIrControl Library - Pentax Example
 * Description:  A small example sketch how to use multiCameraIrControl library. Please check the project page for wiring and leave a comment.
 * Author.....:  Sebastian Setz
 * Version....:  1.3
 * Date.......:  2013-02-11
 * Project....:  http://sebastian.setz.name/arduino/my-libraries/multi-Camera-IR-Control
 * Contact....:  http://Sebastian.Setz.name
 * License....:  This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 *               To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/ or send a letter to
 *               Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.
 * Keywords...:  arduino, library, camera, ir, control, canon, nikon, olympus, minolta, sony, pentax, interval, timelapse
 * History....:  2010-12-08 V1.0 - release
 *               2011-01-04 V1.1
 *               2011-01-25 V1.2 - changing pin number, because the wiring at the homepage was different
 *               			V1.2 - adding toggleFocus
 *
 ********************************************/

#include <multiCameraIrControl.h>

Pentax K5(9);
const int buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 8;        // status led pin
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup(){
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}

void loop(){
  // light up ready LED
  digitalWrite(ledPin, HIGH);

  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState == HIGH && lastButtonState == LOW){
    K5.shutterNow();
    digitalWrite(ledPin,LOW);
    delay(500); // extinguish ready LED for 500 ms
  }

  // save currentbuttonState for next iteration
  lastButtonState = buttonState;
}




