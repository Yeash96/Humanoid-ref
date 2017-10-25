

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

// you can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  Serial.println("enter servo number:");
  while(1){
  while (Serial.available() < 1){
  }
  int servonum = Serial.read() - 48; 
    Serial.println(servonum);

    Serial.println("Enter position number:");
    while (Serial.available() < 3){
      // Do nothing until there are 3 charaters in serial buffer
    }
    
    int a = Serial.read() - 48;
    int b = Serial.read() - 48;
    int c = Serial.read() - 48;
    int x = (a*100) + (b*10) + c;

    Serial.println(x);

    pwm.setPWM(servonum, 0, x);
  }

}
