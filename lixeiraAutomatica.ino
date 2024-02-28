#include <Ultrasonic.h>
#include <Servo.h>
#define pino_trigger 7
#define pino_echo 6

int pos = 0;

Servo servo_9;

Ultrasonic ultrasonic(pino_trigger, pino_echo);
const int Buzzer = 13;
int tom = 0;
float cmMsec;
bool abrir = true;
int posServo = 57;
void setup() {
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
  servo_9.attach(A1);
  
}


void loop() {

  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  if (cmMsec <= 55) {
    if(abrir == true){
      for(posServo;posServo < 120;posServo++){
      servo_9.write(posServo);
      delay(7);
      
      }
    }

  } else {
    
      if(posServo == 120){
        for(posServo;posServo > 50;posServo--){
      servo_9.write(posServo);
      delay(7);
      if(posServo == 51){
        abrir=true;
      }
      }
      
      }else{
        servo_9.write(50);
      }
  }
  
  delay(400);

}


