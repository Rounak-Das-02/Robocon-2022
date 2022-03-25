int r = 1;
void setup(){
  Serial.begin(9600);
}
void loop(){
  if(Serial.available()){         //From RPi to Arduino
    r = Serial.read() - '0';  //conveting the value of chars to integer
//    Serial.println(Serial.read());
Serial.println(r);
  }
  
  delay(1000);
}
  
//  switch (r = Serial.read()) {
//    case -1: break; // there was nothing to read
//    case '2': case 31: Serial.println(F("TILT DOWN")); break;
//    case '4': case 28: Serial.println(F("PAN LEFT"));  break;
//    case '6': case 29: Serial.println(F("PAN RIGHT")); break;
//    case '8': case 30: Serial.println(F("TILT UP"));   break;
//    default: Serial.println((uint8_t) r); break; // ignore anything else but print the code
//  }
//}
