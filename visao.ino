int preto = 930;
int branco = 900;

void seguelinha(){
  int sensor1 = analogRead(d1);
  int sensor2 = analogRead(d2);
  int sensor3 = analogRead(d3);
  int sensor4 = analogRead(d4);
  int sensor5 = analogRead(d5);
  int sensor6 = analogRead(d6);
  int sensor7 = analogRead(d7);
  int sensor8 = analogRead(d8);

  if(sensor4 >= preto || sensor5 >= preto){
    analogWrite(9, 90); //ENA  pin
    analogWrite(10, 90); //ENB pin
    frente();
  }
else if(sensor8 >= preto || sensor7 >= preto){
    analogWrite(9, 200); //ENA  pin
    analogWrite(10, 200); //ENB pin
    esquerda();
    delay(100);
    esquerda();
  }else if(sensor3 >= preto){
    analogWrite(9, 200); //ENA  pin
    analogWrite(10, 0); //ENB pin
    digitalWrite()
    direita();
    delay(50);
    direita();
  }else if(sensor6 >= preto){
    analogWrite(9, 0); //ENA  pin
    analogWrite(10, 200); //ENB pin
    esquerda();
    delay(50);
    esquerda();
  }
  else if(sensor1 >= preto || sensor2 >= preto){
    analogWrite(9, 200); //ENA  pin
    analogWrite(10, 200); //ENB pin
    direita();
    delay(100);
    tras();
    delay(50);
    analogWrite(9, 220); //ENA  pin
    analogWrite(10, 220);
    direita();
    delay(50);

  } else if(sensor4 < branco || sensor5 < branco) {
    frente();
  }
  }else{

    parar();
  }

}