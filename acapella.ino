
/*
  Dimmer

  Demonstrates sending data from the computer to the Arduino board, in this case
  to control the brightness of an LED. The data is sent in individual bytes,
  each of which ranges from 0 to 255. Arduino reads these bytes and uses them to
  set the brightness of the LED.

  The circuit:
  - LED attached from digital pin 9 to ground.
  - Serial connection to Processing, Max/MSP, or another serial application

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Dimmer
*/

#include <Ultrasonic.h>
Ultrasonic ultrasonic(12);

//musical instrument for HC-SR04 (4 pin) Ultrasonic Sensor
void setup() {
  pinMode (9,OUTPUT);//attach pin 9 to vcc
  pinMode (5,OUTPUT);//attach pin 5 to GND
  // initialize serial communication:
  Serial.begin(9600);
}

void loop()
{
ultrasonic.MeasureInCentimeters();
if(ultrasonic.RangeInCentimeters < 30){
  Serial.println("Range is less than 30 cm");


digitalWrite(9, HIGH);
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(10, OUTPUT);// attach pin 10 to Trig
  digitalWrite(10, LOW);
  delayMicroseconds(2);
  digitalWrite(10, HIGH);
  delayMicroseconds(5);
  digitalWrite(10, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode (12, INPUT);//attach pin 12 to Echo
  duration = pulseIn(12, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

 
  Serial.println(ultrasonic.RangeInCentimeters);
  
//  Serial.print(inches);
//  Serial.print("in, ");
//  Serial.print(cm);
//  Serial.print("cm");
//  Serial.println();
 
  delay(100);
  
  int toneToPlay = 0;
  
 
  if(cm <= 10)
  {
     toneToPlay = 110; 
  }
  if(cm > 10)
  {
     toneToPlay = 261; 
  }
  if (toneToPlay == 0)
  {
    noTone(11);
  }
  else
  {
    tone(11, toneToPlay, 200);
  }
  
  //if you want the sound to just change based on distance, 
  //but not necessarily have frequencies that correspond 
  //to notes on a piano you can do this instead
  //tone(11, in*10, 200); 
  
  delay(100);
}

}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}


Doesn’t make sound????






/*
  Dimmer

  Demonstrates sending data from the computer to the Arduino board, in this case
  to control the brightness of an LED. The data is sent in individual bytes,
  each of which ranges from 0 to 255. Arduino reads these bytes and uses them to
  set the brightness of the LED.

  The circuit:
  - LED attached from digital pin 9 to ground.
  - Serial connection to Processing, Max/MSP, or another serial application

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Dimmer
*/

#include <Ultrasonic.h>
Ultrasonic ultrasonic(12);

//musical instrument for HC-SR04 (4 pin) Ultrasonic Sensor
void setup() {
  pinMode (9,OUTPUT);//attach pin 9 to vcc
  pinMode (5,OUTPUT);//attach pin 5 to GND
  // initialize serial communication:
  Serial.begin(9600);
}

void loop()
{
ultrasonic.MeasureInCentimeters();
if(ultrasonic.RangeInCentimeters < 30){
  Serial.println("Range is less than 30 cm");


digitalWrite(9, HIGH);
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(10, OUTPUT);// attach pin 10 to Trig
  digitalWrite(10, LOW);
  delayMicroseconds(2);
  digitalWrite(10, HIGH);
  delayMicroseconds(5);
  digitalWrite(10, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode (12, INPUT);//attach pin 12 to Echo
  duration = pulseIn(12, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

 
  Serial.println(ultrasonic.RangeInCentimeters);

  
  delay(100);
  
  int toneToPlay = 0;
  
 
  if(ultrasonic.RangeInCentimeters <= 10)
  {
     toneToPlay = 110; 
     Serial.println("tone 110");
  }
//  if(cm > 11 && cm < 30)
//  {
//     toneToPlay = 261; 
//     Serial.println("tone 261");
//  }
//  if (toneToPlay == 0)
//  {
//    noTone(11);
//     Serial.println("no tone");
//  }
  else
  {
    tone(11, toneToPlay, 200);
     Serial.println("tone 200");
    
  }
  
  //if you want the sound to just change based on distance, 
  //but not necessarily have frequencies that correspond 
  //to notes on a piano you can do this instead
  //tone(11, in*10, 200); 
  
  delay(100);
}

}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

Final code from class:


/*
  Dimmer

  Demonstrates sending data from the computer to the Arduino board, in this case
  to control the brightness of an LED. The data is sent in individual bytes,
  each of which ranges from 0 to 255. Arduino reads these bytes and uses them to
  set the brightness of the LED.

  The circuit:
  - LED attached from digital pin 9 to ground.
  - Serial connection to Processing, Max/MSP, or another serial application

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Dimmer
*/

#include <Ultrasonic.h>
Ultrasonic ultrasonic(12);

//musical instrument for HC-SR04 (4 pin) Ultrasonic Sensor
void setup() {
  pinMode (9,OUTPUT);//attach pin 9 to vcc
  pinMode (5,OUTPUT);//attach pin 5 to GND
  // initialize serial communication:
  Serial.begin(9600);
}

void loop()
{
ultrasonic.MeasureInCentimeters();
if(ultrasonic.RangeInCentimeters < 30){
  Serial.println("Range is less than 30 cm");


digitalWrite(9, HIGH);
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(10, OUTPUT);// attach pin 10 to Trig
  digitalWrite(10, LOW);
  delayMicroseconds(2);
  digitalWrite(10, HIGH);
  delayMicroseconds(5);
  digitalWrite(10, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode (12, INPUT);//attach pin 12 to Echo
  duration = pulseIn(12, HIGH);

  // convert the time into a distance
 // inches = microsecondsToInches(duration);
 // cm = microsecondsToCentimeters(duration);

 
  Serial.println(ultrasonic.RangeInCentimeters);

  
  delay(100);
  
  int toneToPlay = 0;
  
  if(ultrasonic.RangeInCentimeters < 10)
  {
     toneToPlay = 110; 
     Serial.println("tone 1100");
  } else if (ultrasonic.RangeInCentimeters < 30) {
      toneToPlay = 261; 
      Serial.println("tone 261");
  }

if (toneToPlay == 0)
{
     noTone(11);
     Serial.println("no tone");
     } else { 
     tone(11, toneToPlay, 200);
  
     };
} 
  
  
  //if you want the sound to just change based on distance, 
  //but not necessarily have frequencies that correspond 
  //to notes on a piano you can do this instead
  //tone(11, in*10, 200); 
  
  delay(100);
}



long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

4/19 Final Code

// Sherrie & Claire

#include <Ultrasonic.h>
Ultrasonic ultrasonic(12);
Ultrasonic ultrasonicSecond(6);

//musical instrument for HC-SR04 (4 pin) Ultrasonic Sensor
void setup() {
//  pinMode (9,OUTPUT);//attach pin 9 to vcc
//  pinMode (5,OUTPUT);//attach pin 5 to GND
  // initialize serial communication:
  pinMode(10, OUTPUT);// attach pin 10 to Trig
  pinMode (12, INPUT);//attach pin 12 to Echo
  pinMode(5, OUTPUT);// attach pin 10 to Trig
  pinMode (6, INPUT);//attach pin 12 to Echo
  Serial.begin(9600);
}

void loop()
{

ultrasonic.MeasureInCentimeters();
ultrasonicSecond.MeasureInCentimeters();
Serial.print("First");
Serial.println(ultrasonic.RangeInCentimeters);
Serial.print("Second");
Serial.println(ultrasonicSecond.RangeInCentimeters);

if(ultrasonic.RangeInCentimeters<20){
  
  tone(11, 110, 200);
  }else{
    tone(11, 261, 200);
    }
//Serial.println(ultrasonicSecond.MeasureInCentimeters());
  //if you want the sound to just change based on distance, 
  //but not necessarily have frequencies that correspond 
  //to notes on a piano you can do this instead
  //tone(11, in*10, 200); 
  
  delay(10);

if(ultrasonicSecond.RangeInCentimeters<20){
  
  tone(9, 110, 200);
  }else{
    tone(9, 261, 200);
    }
//Serial.println(ultrasonicSecond.MeasureInCentimeters());
  //if you want the sound to just change based on distance, 
  //but not necessarily have frequencies that correspond 
  //to notes on a piano you can do this instead
  //tone(11, in*10, 200); 
  
  delay(100);
  
}



long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}


Music in Processing:

import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;

/**
  * This sketch demonstrates how to use the <code>loop</code> method of a <code>Playable</code> class. 
  * The class used here is <code>AudioPlayer</code>, but you can also loop an <code>AudioSnippet</code>.
  * When you call <code>loop()</code> it will make the <code>Playable</code> playback in an infinite loop.
  * If you want to make it stop looping you can call <code>play()</code> and it will finish the current loop 
  * and then stop. Press 'l' to start the player looping.
  *
  */

import ddf.minim.*;
import ddf.minim.effects.*;

Minim minim;
AudioPlayer thinking;

void setup()
{
  size(512, 200, P3D);

  minim = new Minim(this);
  thinking = minim.loadFile("thinking.mp3", 2048);
}

void draw()
{
  background(0);
  
  stroke(255);
  
  for(int i = 0; i < thinking.bufferSize() - 1; i++)
  {
    line(i, 50  + thinking.left.get(i)*50,  i+1, 50  + thinking.left.get(i+1)*50);
    line(i, 150 + thinking.right.get(i)*50, i+1, 150 + thinking.right.get(i+1)*50);
  }
}

void keyPressed()
{
  if ( key == 'l' ) thinking.loop();
}


