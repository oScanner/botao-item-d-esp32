const int led = 26;
const int btn = 27; 
bool ledStatus = HIGH;
unsigned long contaClick = 0;
unsigned long tempoAnterior = 0;
unsigned long lastDebounceTime = 0; 
unsigned long previousMillis = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
}
 
void loop() {
  if (digitalRead(btn) == HIGH) {
    if ((millis() - lastDebounceTime) > 70) {
      contaClick = contaClick + 2;
      tempoAnterior = millis();
    }
    lastDebounceTime = millis();
  }
  if (millis() - tempoAnterior > 3000) {
    while (contaClick > 0) {
      if (millis() - previousMillis >= 500) {
      loopLed();
      ledStatus = !ledStatus;
      contaClick = contaClick - 1;
      tempoAnterior = millis();
      }
   } 
  }
 
}


void loopLed() {
  digitalWrite(led, ledStatus);
  previousMillis = millis();
}
  


