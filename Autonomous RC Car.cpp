#include <Wire.h> 
#include “LiquidCrystal_I2C.h”

const int driving_dc = 34; // Pc.7 use digital pin #34 of the MCU to
connect to BPHASE Pin of the DRV8835 const int driving_pwm = 38;
//pb.3 use PWM pin #40 of the MCU to connect to B ENBL Pin of the
DRV8835 const int trigPin = 24; //PD.1 uses pin to trigger the initial
signal const int echoPin = 23; //PD.0 uses pin to receive the return
signal const int steering_dc = 35; // Pc.6 use digital pin #34 of the
MCU to connect to BPHASE Pin of the DRV8835 const int steering_pwm =
39; //pf.3 use PWM pin #40 of the MCU to connect to B ENBL Pin of the
DRV8835 const int tempInput = A0; // (pin # 29), use A0 analog input
const int photocell = A11;// use pin # as analog input const int light
= 3 ; //use pin as digital output int analogread; float temperature;
byte address = 0x3f; // LCD I2C address can be 21, 38, or 27 int
columns = 16; // number of columns on LCD int rows = 2; // number of
rows on LCD LiquidCrystal_I2C lcd(address, columns, rows);

// ————————————————– Setup void setup() { Serial.begin(9600);
pinMode(driving_dc, OUTPUT); // Make pc.7 output pinMode(driving_pwm,
OUTPUT); // Make pf.2 output pinMode(steering_dc, OUTPUT); // Make
pc.7 output pinMode(steering_pwm, OUTPUT); // Make pf.2 output
pinMode(trigPin, OUTPUT); //Make Pd.1 output pinMode(photocell,
INPUT); pinMode(echoPin, INPUT); //Make Pd.0 input pinMode(tempInput,
INPUT); pinMode(light,OUTPUT); pinMode(8,OUTPUT); //Use pin#9 to turn
ON/OFF the fan lcd.init(); // initialize the lcd lcd.backlight();

}

// ———————————————– Loop

void loop() { int lightIntensity = analogRead(photocell);

analogread = analogRead(tempInput); temperature = (analogread/4096.0)
* 3.3/0.01; //for 3.3 V Microcontroller

// establish variables for duration of the ping, and the distance
// result in inches and centimeters:
long duration, inches, cm;

// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
digitalWrite(trigPin, LOW); delayMicroseconds(2);
digitalWrite(trigPin, HIGH); delayMicroseconds(8);
digitalWrite(trigPin, LOW);

//a HIGH pulse whose duration is the time (in microseconds) from the
//sending of the ping to the reception of its echo off of an object.
duration = pulseIn(echoPin, HIGH);

// convert the time into a distance inches =
microsecondsToInches(duration); cm =
microsecondsToCentimeters(duration);

// Clear everything
lcd.clear();

// Place cursor in first column, first row lcd.setCursor(0 ,0);
lcd.print(temperature); lcd.println(” F “);

// Place cursor in first column, third row lcd.setCursor(0,1);
lcd.print(“ECET 365”); // Use lcd.print to print a text

if(temperature < 81) { if(inches >= 13) { analogWrite(driving_pwm,
90); //Forward at PWM speed % digitalWrite(driving_dc, 0);
if(lightIntensity < 500) { digitalWrite(light, HIGH);// turn on light
} else { digitalWrite(light,LOW);// turn off light } } } else if
(inches < 12) { analogWrite(driving_pwm, 0); //stop
digitalWrite(driving_dc, 0); delay(1000); analogWrite(steering_pwm,
225); // turn wheels at pwm % digitalWrite(steering_dc, 1); //turn
right analogWrite(driving_pwm, 85); // reverse/brake at speed PWM %
digitalWrite(driving_dc, 1); //reverse delay(2000);
analogWrite(steering_pwm, 250); // turn wheels at pwm %
digitalWrite(steering_dc, 0); //turn left analogWrite(driving_pwm,
90); //forward digitalWrite(driving_dc, 0); delay(3000);
analogWrite(steering_pwm, 0); // turn wheels at pwm %
digitalWrite(steering_dc, 0); //set wheels analogWrite(driving_pwm,
90); //forward digitalWrite(driving_dc, 0); } } else {
analogWrite(driving_pwm,0); digitalWrite(driving_pwm,0);
digitalWrite(9,LOW);// turn on fan
 } } long microsecondsToInches(long
microseconds) { 
// According to Parallax's datasheet for the PING))),there are 
// 73.746 microseconds per inch (i.e. sound travels at 1130feet per 
// second). This gives the distance travelled by the ping, outbound 
// and return, so we divide by 2 to get the distance of the obstacle. 
// See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf 
return microseconds / 74 / 2; } long microsecondsToCentimeters(long
microseconds) { // The speed of sound is 340 m/s or 29 microseconds
per centimeter. // The ping travels out and back, so to find the
distance of the // object we take half of the distance travelled.
return microseconds / 29 / 2; }