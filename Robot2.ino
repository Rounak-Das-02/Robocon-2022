int relay1 = 25;
int relay2 = 27;

int IN1 = 51;
int IN2 = 53;
int IN3 = 45;
int IN4 = 47;

int IN5 = 31;
int IN6 = 33;
int IN7 = 37;
int IN8 = 39;

int r = -1;
int flag = -1;

void setup() {
  Serial.begin(9600);

  //conveyor belt
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, HIGH);

  //intake motor
  pinMode(relay2, OUTPUT);

  // Chassis Control
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

}

void loop() {
//  Serial.println("HIGH");
//  digitalWrite(relay1, LOW);
//  delay(2000);
//  digitalWrite(relay1, HIGH);
//  delay(2000);
//
//  digitalWrite(relay2, HIGH);
//  delay(5000);
//  digitalWrite(relay2, LOW);
//  delay(1000);

  r = Serial.read();
  if(r!=-1)
    flag = r;
  
  Serial.println(r);
  if (r == 130 || r == 48)
  {
    Serial.println("STOP");
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);

    
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, HIGH);
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, HIGH);

    
    flag = -1;
  }

  
  if (r == 49)
  {
    Serial.println(r);
    digitalWrite(relay1, LOW);
  }

  if(r == 51)
  {
//    digitalWrite(IN1, LOW);
//    digitalWrite(IN2, HIGH);
      digitalWrite(relay2, HIGH);
  }


  if(flag == 55){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
  }

  if(flag == 56){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
  }

}