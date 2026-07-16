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

  vel_motor_A = constrain(vel_motor_A, -255, 255);
  vel_motor_B = constrain(vel_motor_B, -255, 255);

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

void lerposicaosensores(){
  float peso1 = 1.0;
  float peso2 = 0.6;
  float peso3 = 0.3;
  float peso4 = 0.1;
  float peso5 = 0.1;
  float peso6 = 0.3;
  float peso7 = 0.6;
  float peso8 = 1.0;
  float sensores_esquerda = sensor1 * peso1 + sensor2 * peso2 + sensor3 * peso3 + sensor4 * peso4;
  float Mp_esquerda = sensores_esquerda / (peso1 + peso2 + peso3 + peso4);
  float sensores_direita = sensor8 * peso8 + sensor7 * peso7 + sensor6 * peso6 + sensor5 * peso5;
  float Mp_direita = sensores_direita / (peso5 + peso6 + peso7 + peso8);
  erro = Mp_direita - Mp_esquerda;
}