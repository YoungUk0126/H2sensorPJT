const int LED_RED_PIN = 13;
const int LED_YELLOW_PIN = 12;

void setup() {
  
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  for(int i=0; i<3; i++) {
    Serial.println("LED_ON");
    digitalWrite(LED_RED_PIN, HIGH);
    digitalWrite(LED_YELLOW_PIN, HIGH);
    delay(1500);
    Serial.println("LED_OFF");
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_YELLOW_PIN, LOW);
    delay(1500);
  }
  delay(5000);
  

}
