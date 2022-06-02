int trig = 6;
int echo = 5;
int relay = 3;
int tiempo;
int distancia;
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(relay, OUTPUT);
}
void loop() {
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo/58.2;
  Serial.print(distancia);
  Serial.println();
  if (10 < distancia){
    digitalWrite(relay, HIGH);
  }
  else{
    digitalWrite(relay, LOW);
  }
  delay(1000);
}
