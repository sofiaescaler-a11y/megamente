float kp = 0.3;
float ki = 0.001;
float kd = 0.001;

int erro = 0;
int preto = 930;
int branco = 900;

int erro_anterior = 0;
float integral = 0;

void PID() {

  lerposicaosensores();
  float erro_atual = erro;

  //calcular o P (proporcional)
  float P = kp * erro_atual;

  //calcular integral
  integral += erro_atual;
  float I = ki * integral;

  //calcular o d (derivativa)
  float D = kd * (erro_atual - erro_anterior);

  //correção final
  float correcao = P + I + D;

  //Atualizar o erro
  erro_anterior = erro_atual;

  Serial.println("erro:");
  Serial.println(erro_atual);

  int vel_motor_A = velocidade_base - correcao; //(direito)
  int vel_motor_B = velocidade_base + correcao; //(esquerdo)

  vel_motor_A = constrain(vel_motor_A,0,255);
  vel_motor_B = constrain(vel_motor_B,0,255);

  Serial.println("velocidade A:");
  Serial.println(vel_motor_A);
  Serial.println("Velocidade B:");
  Serial.println(vel_motor_B);

  if (vel_motor_A < 0 && vel_motor_B < 0){
    tras();
    int vel_final_B = vel_motor_B * -1;
    int vel_final_A = vel_motor_A * -1;
    analogWrite(9, vel_final_A); //ENA  pin
    analogWrite(10, vel_final_B); //ENB pin
  } else if(vel_motor_A > 0 && vel_motor_B > 0){
    frente();
    int vel_final_B = vel_motor_B;
    int vel_final_A = vel_motor_A;
    analogWrite(9, vel_final_A); //ENA  pin
    analogWrite(10, vel_final_B); //ENB pin

  } else if (vel_motor_A < 0 && vel_motor_B > 0){
    direita();
    int vel_final_B = vel_motor_B;
    int vel_final_A = vel_motor_A * -1;
    analogWrite(9, vel_final_A); //ENA  pin
    analogWrite(10, vel_final_B); //ENB pin
  } else if (vel_motor_A > 0 && vel_motor_B < 0){
    esquerda();
    int vel_final_B = vel_motor_B * -1;
    int vel_final_A = vel_motor_A;
    analogWrite(9, vel_final_A); //ENA  pin
    analogWrite(10, vel_final_B); //ENB pin
  }


  delay(1);


}
void lerposicaosensores()
{
  int sensores[8] = {
    sensor1, sensor2, sensor3, sensor4,
    sensor5, sensor6, sensor7, sensor8
  };

  long soma = 0;
  long peso = 0;

  for (int i = 0; i < 8; i++)
  {
    int valor;

    if (i == 0)
      valor = map(sensores[i], 660, 670, 0, 1000);
    else
      valor = map(sensores[i], 810, 900, 0, 1000);

    valor = constrain(valor, 0, 1000);

    soma += (long)valor * (i * 1000);
    peso += valor;
  }

  if (peso == 0)
  {
    erro = erro_anterior;
    return;
  }

  int posicao = soma / peso;

  erro = posicao - 3500;
}

