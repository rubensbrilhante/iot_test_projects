//Definicao pinos leds
const int RED = 5;
const int GREEN = 6;
const int BLUE = 3;

const long DELAY_R = 5000l;
const long DELAY_G = 10000l;
const long DELAY_B = 15000l;

const int FADE_IN = 0;
const int FADE_OUT = 1;

long timeR = DELAY_R;
long timeG = DELAY_G;
long timeB = DELAY_B;

int stateR = FADE_IN;
int stateG = FADE_IN;
int stateB = FADE_IN;

float powerR = 0;
float powerG = 0;
float powerB = 0;

long timeOnStateR = 0;
long timeOnStateG = 0;
long timeOnStateB = 0;

void decideState(long delta, long &timeOnState, long delay, int &actualState)
{
  long totalTime = timeOnState + delta;
  Serial.print("total time ");
  Serial.println(totalTime, DEC);
  if (totalTime > delay)
  {
    actualState = (actualState + 1) % 2;
    timeOnState = totalTime - delay;
  }
  Serial.print("state ");
  Serial.println(actualState, DEC);
  Serial.print("timeonstate ");
  Serial.println(timeOnState, DEC);
}

void decidePower(float &power, int state, long delay, int delta)
{
  // float percent = (power/255.f) * delay;
  float deltaPercent = (((float)delta) / delay) * 255;

  // Serial.print("percent ");
  // Serial.println(percent);
  // Serial.print("deltaPercent ");
  // Serial.println(deltaPercent);
  //
  // if (state == FADE_OUT)
  // {
  //   deltaPercent *= -1;
  // }
  // power += deltaPercent;
  // if (power < 0)
  // {
  //   power = 0;
  // } else if (power > 255)
  // {
  //   power = 255;
  // }
  // Serial.print("power ");
  // Serial.println(power, DEC);
  if (state == FADE_OUT)
  {
    power = 255;
  }
  else
  {
    power = 0;
  }
}

long currentTime;
long newTime;
long delta;

void setup()
{
  Serial.begin(9600);
  //Define pinos led como saida
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  currentTime = millis();
}

void loop()
{
  newTime = millis();
  delta = newTime - currentTime;

  currentTime = newTime;

  Serial.print("delta ");
  Serial.println(delta, DEC);

  timeOnStateR += delta;
  timeOnStateG += delta;
  timeOnStateB += delta;

  Serial.println("RED");
  decideState(delta, timeOnStateR, DELAY_R, stateR);
  decidePower(powerR, stateR, DELAY_R, delta);
  analogWrite(RED, (int)powerR);
  Serial.println("GREEN");
  decideState(delta, timeOnStateG, DELAY_G, stateG);
  decidePower(powerG, stateG, DELAY_G, delta);
  analogWrite(GREEN, (int)powerG);
  Serial.println("BLUE");
  decideState(delta, timeOnStateB, DELAY_B, stateB);
  decidePower(powerB, stateB, DELAY_B, delta);
  analogWrite(BLUE, (int)powerB);

  // digitalWrite(13, HIGH);
  // index++;
  // Serial.print("Saida: ");
  // Serial.println(index, DEC);
  // //Intensidade baixa
  // if (index % 3 == 0)
  // {
  //   Serial.println("VERDE");
  //   digitalWrite(BLUE, HIGH);
  //   digitalWrite(VERM, HIGH);
  //   fadeIn(VERD);
  //   fadeOut(VERD);
  // } else if (index % 3 == 1)
  // {
  //   Serial.println("AZUL");
  //   digitalWrite(VERD, HIGH);
  //   digitalWrite(VERM, HIGH);
  //   fadeIn(BLUE);
  //   fadeOut(BLUE);
  // } else
  // {
  //   Serial.println("VERMELHO");
  //   digitalWrite(VERD, HIGH);
  //   digitalWrite(BLUE, HIGH);
  //   fadeIn(VERM);
  //   fadeOut(VERM);
  // }
  // delay(1000);
  // // //Apaga todos os leds
  // digitalWrite(VERD, HIGH);
  // digitalWrite(BLUE, HIGH);
  // digitalWrite(VERM, HIGH);
  // delay(1000);
}
