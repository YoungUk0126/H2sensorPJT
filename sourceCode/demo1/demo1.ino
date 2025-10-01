const int GAS_SENSOR_PIN = A0;   // MQ-8 아날로그 출력(AO) 핀
const int LED_RED_PIN = 13;      // 빨간색 LED 핀 (경고 1)
const int LED_YELLOW_PIN = 12;   // 노란색 LED 핀 (경고 2)
const int BUZZER_PIN = 11;       // 수동 부저 핀 (경고음)

int PPM = 0;


void setup() {
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  PPM = analogRead(GAS_SENSOR_PIN);
  Serial.println("PPM : %d\n", PPM);
  if(PPM >= 4000) { // 폭팔 임계인 40000의 10%
    Serial.println("WARNING!!!!\n");
    digitalWrite(LED_RED_PIN, HIGH);
    digitalWrite(LED_YELLOW_PIN, HIGH);

    tone(BUZZER_PIN, 1500, 100);// 핀이름, HZ, ms후 꺼짐
    delay(100);
    noTone(BUZZER_PIN);

    tone(BUZZER_PIN, 1500, 100);// 핀이름, HZ, ms후 꺼짐
    delay(100);
    noTone(BUZZER_PIN);

    delay(500);
  }
  else {
    Serial.println("SAFE~~\n");
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_YELLOW_PIN, LOW);

    noTone(BUZZER_PIN);

    delay(500);

  }
  delay(200);


}
