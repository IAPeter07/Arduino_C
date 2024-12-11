int Trigger_PIN = 12;
int Echo_PIN = 11;
int LEDV_2 = 2;
int LEDA_3 = 3;
int LEDVR_4 = 4;
int VENT = 7;

void setup() {
  Serial.begin(9600);
  pinMode(Trigger_PIN, OUTPUT);
  pinMode(Echo_PIN,INPUT);
  pinMode(LEDV_2,OUTPUT);
  pinMode(LEDA_3,OUTPUT);
  pinMode(LEDVR_4,OUTPUT);
  pinMode(VENT,OUTPUT);
}

void loop() {
  digitalWrite(Trigger_PIN,LOW);
  delay(2);
  digitalWrite(Trigger_PIN,HIGH);
  delay(10);
  digitalWrite(Trigger_PIN,LOW);

  long duration = pulseIn(Echo_PIN,HIGH);
  float distance = duration * 0.034/2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < 10){
    digitalWrite(LEDA_3,LOW);
    digitalWrite(LEDVR_4,LOW);
    digitalWrite(LEDV_2,HIGH);
    digitalWrite(VENT,LOW);
  }
  else if(distance >= 10 && distance <= 20){
    digitalWrite(LEDV_2,LOW);
    digitalWrite(LEDVR_4,LOW);
    digitalWrite(LEDA_3,HIGH);
    digitalWrite(VENT,HIGH);
  }
  else{
    digitalWrite(LEDV_2,LOW);
    digitalWrite(LEDA_3,LOW);
    digitalWrite(LEDVR_4,HIGH);
    digitalWrite(VENT,LOW);
  }
}
