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

const int shutterButtonPin = 2;    // shutter button pin
const int focusButtonPin = 12; // focus button pin
const int statusLEDPin = 8;        // status led pin
const int infraredLEDPin = 9; // infrared led pin
int shutterButtonState = 0;         // current state of the shutter button
int lastShutterButtonState = 0;     // previous state of the shutter button
int focusButtonState = 0; // current state of the focus button
int lastFocusButtonState = 0; // previous state of the focus button

Pentax K5(infraredLEDPin); // instantiate Pentax object

void setup(){
  pinMode(shutterButtonPin, INPUT);
  pinMode(focusButtonPin, INPUT);
  pinMode(statusLEDPin, OUTPUT); // mode of infrared led pin set during Pentax object instantiation
  //Serial.begin(9600);
}

void loop(){
  // turn off busy LED
  digitalWrite(statusLEDPin, LOW);
  
  // read the focus button input pin:
  focusButtonState = digitalRead(focusButtonPin);
  
  // read the shutter button input pin:
  shutterButtonState = digitalRead(shutterButtonPin);
  
  // compare the buttonState to its previous state
  if (focusButtonState == HIGH && lastFocusButtonState == LOW){
    K5.toggleFocus();
    digitalWrite(statusLEDPin,HIGH);
    delay(50); // turn on busy LED for 50 ms
  }
  if (shutterButtonState == HIGH && lastShutterButtonState == LOW){
    K5.shutterNow();
    digitalWrite(statusLEDPin,HIGH);
    delay(500); // turn on busy LED for 500 ms
  }

  // save currentbuttonState for next iteration
  lastFocusButtonState = focusButtonState;
  lastShutterButtonState = shutterButtonState;
}




