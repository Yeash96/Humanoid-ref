
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

typedef struct {
	int pin;
	int pos;
} Servo_t;


class leg {
	public:
		Servo_t Hip;
		Servo_t Uthy;
		Servo_t Lthy;
		Servo_t Uank;
		Servo_t Lank;
		
		
		void configPins(int HipPos,int UthyPos,int LthyPos,int UankPos,int LankPos){
			Hip.pin = HipPos;
			Uthy.pin = UthyPos;
			Lthy.pin = LthyPos;
			Uank.pin = UankPos;
			Lank.pin = LankPos;
		}
		
		void setPos1(){
			Hip.pos  = 130;
			Uthy.pos = 130;
			Lthy.pos = 130;
			Uank.pos = 130;
			Lank.pos = 130;
			MoveNow();
		}
		void setPos2(){
			Hip.pos  = 300;
			Uthy.pos = 300;
			Lthy.pos = 300;
			Uank.pos = 300;
			Lank.pos = 300;
			MoveNow();
		}
	private:
		void MoveNow(){
			pwm.setPWM(Hip.pin, 0, Hip.pos);
			pwm.setPWM(Uthy.pin, 0, Uthy.pos);
			pwm.setPWM(Lthy.pin, 0, Lthy.pos);
			pwm.setPWM(Uank.pin, 0, Uank.pos);
			pwm.setPWM(Lank.pin, 0, Lank.pos);
		}
};

void setup(){
	pwm.begin();
	
	pwm.setPWMFreq(60);
}

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

void loop(){
	leg LeftLeg;
	
	LeftLeg.configPins(0,1,2,3,4);
	
	LeftLeg.setPos1();
	delay(1000);
	//LeftLeg.setPos2();
	//delay(1000);
}
