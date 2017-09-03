// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = D1;    // the number of the pushbutton pin

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
  Serial.print(D1);
  Serial.print(" reading ");
  Serial.println(reading);
  delay(80);
}
