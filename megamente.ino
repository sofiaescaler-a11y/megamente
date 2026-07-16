
//QTR-8A
int d1 = A1;
int d2 = A2;
int d3 = A3;
int d4 = A4;
int d5 = A5;
int d6 = A6;
int d7 = A7;
int d8 = A8;
const int ledControlPin = 2;
const int led = 30;

//MOTORES
int motor1pin1 = 22;
int motor1pin2 = 24;

int motor2pin1 = 26;
int  motor2pin2 = 28;


void setup() {
  Serial.begin(9600);
  // MOTORES
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,  OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  //VELOCIDADE
  pinMode(9,  OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(led, OUTPUT);

  //SENSOR
  pinMode(ledControlPin, OUTPUT);
  digitalWrite(ledControlPin, HIGH);

  
}

void loop() {
  analogWrite(9, 90); //ENA  pin
  analogWrite(10, 90); //ENB pin
  
  seguelinha();
  leitura();
 
 

}
