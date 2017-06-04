//Programa: Sensor de som KY-038
//Autor: Arduino e Cia

#define M_SIZE 4
int m_index = M_SIZE;
int measurement[M_SIZE] = {};


//Definicao pinos leds
int pinoled_ver = 3;
int pinoled_ama = 4;
int pinoled_verm = 5;

//Definicao pinos sensor
int pino_analogico = A5;
// int pino_digital = 7;

int valor_A0 = 0;
int valor_D = 0;


int measure() {
  int m = 0;
  for (int i = 0; i < M_SIZE; i++) {
    m = (m + measurement[i]) / 2;
  }
  return m;
}

void setup()
{
  Serial.begin(9600);
  //Define pinos led como saida
  pinMode(pinoled_ver, OUTPUT);
  pinMode(pinoled_ama, OUTPUT);
  pinMode(pinoled_verm, OUTPUT);
  //Define pinos sensor como entrada
  pinMode(pino_analogico, INPUT);
  // pinMode(pino_digital, INPUT);
}

void loop()
{
  // Serial.println("measurement: ");
  measurement[m_index % M_SIZE] =  analogRead(pino_analogico);
  // Serial.println(measurement);
  valor_A0 = measure();
  m_index++;
  // valor_D = digitalRead(pino_digital);
  Serial.print("Saida A0: ");
  Serial.println(valor_A0, DEC);
  // Serial.print(" Saida D0: ");
  // Serial.println(valor_D);
  //Intensidade baixa
  if (valor_A0 > 20 && valor_A0 < 300)
  {
    digitalWrite(pinoled_ver, HIGH);
    digitalWrite(pinoled_ama, LOW);
    digitalWrite(pinoled_verm, LOW);
  }
  //Intensidade media
  if (valor_A0 > 301 && valor_A0 < 700)
  {
    digitalWrite(pinoled_ver, HIGH);
    digitalWrite(pinoled_ama, HIGH);
    digitalWrite(pinoled_verm, LOW);
  }
  //Intensidade alta
  if (valor_A0 > 701)
  {
    digitalWrite(pinoled_ver, LOW);
    digitalWrite(pinoled_ama, LOW);
    digitalWrite(pinoled_verm, HIGH);
  }
  delay(1000);
  // //Apaga todos os leds
  digitalWrite(pinoled_ver, LOW);
  digitalWrite(pinoled_ama, LOW);
  digitalWrite(pinoled_verm, LOW);
  delay(1000);
}
