int r;
int relayShooter1 = 50;
int relayShooter2 = 52;
int PWM_shooter = 2;

int relayConveyor1 = 22;
int relayConveyor2 = 23;

int PWM = 7;


int IN1 = 53;
int IN2 = 49;

int IN3 = 40;
int IN4 = 38;

int IN5 = 34;
int IN6 = 32;

int IN7 = 28;
int IN8 = 26;


int dirPin = 4;
int stepPin = 5;

int shooter_speed = 55; // max of 255
int speed = 150; // max of 255

int flag = -1;

void setup() {
  pinMode(relayShooter1, OUTPUT);
  pinMode(relayShooter2, OUTPUT);
  pinMode(relayConveyor1, OUTPUT);
  pinMode(relayConveyor2, OUTPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  pinMode(PWM, OUTPUT);

  
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  mainLoop();
}

void mainLoop(){
  r = Serial.read();
  if(r!=-1)
    flag = r;
  
  Serial.println(r);
  if (r == 130 || r == 48)
  {
    Serial.println("STOP");
    motor_stop();    
    flag = -1;
  }

  
  if (r == 49)
  {
    analogWrite(PWM_shooter, shooter_speed);
    digitalWrite(relayShooter1, HIGH);
    digitalWrite(relayShooter2, LOW);
  }

  if(r == 51)
  {
//    digitalWrite(IN1, LOW);
//    digitalWrite(IN2, HIGH);
      analogWrite(PWM, 1023);
      digitalWrite(relayConveyor1, HIGH);
      digitalWrite(relayConveyor2, LOW);
  }

  if(flag == 53){
    digitalWrite(dirPin, HIGH);
    for(int i = 0; i < 15; i++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(150);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(150);
    }
    
  }

  if(flag == 54){
    digitalWrite(dirPin, LOW);
    for(int i = 0; i < 15; i++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(150);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(150);
    }
  }


  if(flag == 55){
    motor_cw();
  }

  if(flag == 56){
    motor_ccw();
  } 

  if(flag == 119){
    motor_fwd();
  }
  if(flag == 115){
    motor_bwd();
  }

    if(flag == 100){
      motor_cw();
  }

  if(flag == 97){
    motor_ccw();  
  }

  if(flag == 113){
    halt();
  }
}

void motor_cw(){
    analogWrite(PWM, speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
}

void motor_ccw(){
  analogWrite(PWM, speed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
}
void motor_fwd(){
    analogWrite(PWM, speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
}

void motor_bwd(){
    analogWrite(PWM, speed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);
}

void motor_stop(){
    analogWrite(PWM, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);

//    digitalWrite(relayShooter1, LOW);
//    digitalWrite(relayShooter2, LOW);
    digitalWrite(relayConveyor1, LOW);
    digitalWrite(relayConveyor2, LOW);
}

void halt(){
    analogWrite(PWM, 0);
    analogWrite(PWM_shooter, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);

    digitalWrite(relayShooter1, LOW);
    digitalWrite(relayShooter2, LOW);
    digitalWrite(relayConveyor1, LOW);
    digitalWrite(relayConveyor2, LOW);
  
}
