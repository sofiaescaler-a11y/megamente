
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

int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;
int sensor4 = 0;
int sensor5 = 0;
int sensor6 = 0;
int sensor7 = 0;
int sensor8 = 0;

//MOTORES
int motor1pin1 = 26;
int motor1pin2 = 28;

int motor2pin1 = 24;
int  motor2pin2 = 22;

int velocidade_base = 0;


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

  //calibracao();

  analogWrite(9, 100); //ENA  pin
  analogWrite(10, 100); //ENB pin
}

void loop() {

  //leitura sensores  --------------------------
  sensor1 = analogRead(d1);
  sensor2 = analogRead(d2);
  sensor3 = analogRead(d3);
  sensor4 = analogRead(d4);
  sensor5 = analogRead(d5);
  sensor6 = analogRead(d6);
  sensor7 = analogRead(d7);
  sensor8 = analogRead(d8);

  //funções -------------------------------------
  //leitura();
  PID();
  //parar();
 

}
