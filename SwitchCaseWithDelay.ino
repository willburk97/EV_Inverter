//Switch Case Design matching https://www.youtube.com/watch?v=Gj7qAlsq_m8

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(115200);
  #define AH 2
  #define AL 3
  #define BH 4
  #define BL 5
  #define CH 6
  #define CL 7
  
  pinMode(AH,OUTPUT);
  pinMode(AL,OUTPUT);
  pinMode(BH,OUTPUT);
  pinMode(BL,OUTPUT);
  pinMode(CH,OUTPUT);
  pinMode(CL,OUTPUT);
  analogRead(A1);

  digitalWrite(AH,LOW);
  digitalWrite(AL,LOW);
  digitalWrite(BH,LOW);
  digitalWrite(BL,LOW);
  digitalWrite(CH,LOW);
  digitalWrite(CL,LOW);
}

int currentState = 1;
uint16_t speedDesired = 1;
//unsigned long currentTime;
unsigned long previousTime;
void loop() {
  // put your main code here, to run repeatedly:

//  Serial.println(currentState);
  
  switch (currentState) {
    case 1: //V1[100]
//      digitalWrite(AL, LOW);
//      delayMicroseconds(1);
//      digitalWrite(AH,HIGH);
//      digitalWrite(BH, LOW);
//      delayMicroseconds(1);
//      digitalWrite(BL, HIGH);
      digitalWrite(CH, LOW);
      delayMicroseconds(1);
      digitalWrite(CL, HIGH);
      break;
      
    case 2: //V2[110]
//      digitalWrite(AH,LOW);
//      delayMicroseconds(1);
//      digitalWrite(AL, HIGH);
      digitalWrite(BL, LOW);
      delayMicroseconds(1);
      digitalWrite(BH, HIGH);
//      digitalWrite(CH, LOW);
//      delayMicroseconds(1);
//      digitalWrite(CL, HIGH);
      break;
      
    case 3: //v3[010]
      digitalWrite(AH,LOW);
      delayMicroseconds(1);
      digitalWrite(AL, HIGH);
//      digitalWrite(BH, LOW);
//      delayMicroseconds(1);
//      digitalWrite(BL, HIGH);
//      digitalWrite(CH, LOW);
//      delayMicroseconds(1);
//      digitalWrite(CL, HIGH);
      break;
      
    case 4: //V4[011]
//      digitalWrite(AH,LOW);
//      delayMicroseconds(1);
//      digitalWrite(AL, HIGH);
//      digitalWrite(BH, LOW);
//      delayMicroseconds(1);
//      digitalWrite(BL, HIGH);
      digitalWrite(CL, LOW);
      delayMicroseconds(1);
      digitalWrite(CH, HIGH);
      break;
      
    case 5: //V5[001]
//      digitalWrite(AH,LOW);
//      delayMicroseconds(1);
//      digitalWrite(AL, HIGH);
      digitalWrite(BH, LOW);
      delayMicroseconds(1);
      digitalWrite(BL, HIGH);
//      digitalWrite(CH, LOW);
//      delayMicroseconds(1);
//      digitalWrite(CL, HIGH);
      break;
      
    case 6: //V6[101]
      digitalWrite(AL,LOW);
      delayMicroseconds(1);
      digitalWrite(AH, HIGH);
//      digitalWrite(BH, LOW);
//      delayMicroseconds(1);
//      digitalWrite(BL, HIGH);
//      digitalWrite(CH, LOW);
//      delayMicroseconds(1);
//      digitalWrite(CL, HIGH);
      break;
  }

  currentState++;
  if(currentState>6) { currentState = 1; }
  speedDesired = analogRead(A1);

//More reliable timing between cycles:
  while((micros()-previousTime) < (speedDesired*10)){}
  previousTime = micros();
//Versus:  
//  delayMicroseconds(speedDesired*10);

//  Serial.println(speedDesired);
  

}
