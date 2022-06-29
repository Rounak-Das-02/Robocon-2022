int r;
int relay = 27;
int relayConveyor = 25;

int v = 23;

int IN1 = 53; // Front Left
int IN2 = 51; // Front Left

int IN3 = 47; // Front Right
int IN4 = 45; // Front Right

int IN5 = 39; // Rear left
int IN6 = 37; // Rear left

int IN7 = 33; // Rear right
int IN8 = 31; // Rear right


int dirPin = 2;
int stepPin = 3;

int flag = -1;

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(relayConveyor, OUTPUT);
  digitalWrite(relay, HIGH);
  digitalWrite(relayConveyor, HIGH);

  pinMode(v, OUTPUT);
  digitalWrite(v, HIGH);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  r = Serial.read();
  if(r!=-1)
    flag = r;
  
  Serial.println(r);
  if (r == 130 || r == 48)
  {
    Serial.println("STOP");
    digitalWrite(relay, HIGH);
    digitalWrite(relayConveyor, HIGH);

    
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
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
}

  if(r == 51)
  {
    Serial.println(r);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
  }

  if(flag == 53){
    digitalWrite(dirPin, HIGH);
    for(int i = 0; i < 15; i++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
    }    
  }

  if(flag == 54){
        digitalWrite(dirPin, LOW);
    for(int i = 0; i < 15; i++){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
    }
  }


  if(r == 55){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
  }

  if(r == 56){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
  }

  if(flag == 99){
    digitalWrite(relay, LOW);
  }

  if(flag == 118){
    digitalWrite(relayConveyor, LOW);
  }

  if(r == 107){
    digitalWrite(v, LOW);
  }
  if(r == 108){
    digitalWrite(v, HIGH);
  }
}
