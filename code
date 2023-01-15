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


