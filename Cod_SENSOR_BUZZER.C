int TRIGGER_PIN = 11;
int ECHO_PIN = 12;

int BUZZER_PIN = 2;
int melody[] = {262,262,392,392,440,440,392, //Primeira Parte
                349,349,330,330,294,294,262, //Segunda Parte
                392,392,349,349,330,330,294, //Terceira Parte
                392,392,349,349,330,330,262}; //Quarta Parte

int durations[] = {500,500,500,500,500,500,1000,
                   500,500,500,500,500,500,1000,
                   500,500,500,500,500,500,1000,
                   500,500,500,500,500,500,1000};


void setup() {
  Serial.begin(9600);
  pinMode (TRIGGER_PIN, OUTPUT);
  pinMode (ECHO_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite (TRIGGER_PIN, LOW);
  delay(2);
  digitalWrite (TRIGGER_PIN, HIGH);
  delay(10);
  digitalWrite (TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <400 && distance >370){
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++){
      tone(BUZZER_PIN, melody[i], durations[i]);
    }
  }
  else{
    digitalWrite(BUZZER_PIN,LOW);
  }
}
