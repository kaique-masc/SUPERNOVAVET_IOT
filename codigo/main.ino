#include <LiquidCrystal.h>

#define LEDPIN 2
#define BUZZERPIN 4

LiquidCrystal lcd(23, 22, 21, 19, 18, 5);

void setup() {

  Serial.begin(115200);

  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);

  lcd.begin(16, 2);
}

void loop() {

  int temperatura = random(20, 40);

  Serial.println("==============");
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("TEMP: ");
  lcd.print(temperatura);
  lcd.print("C");

  if (temperatura < 28) {

    digitalWrite(LEDPIN, LOW);
    noTone(BUZZERPIN);

    lcd.setCursor(0,1);
    lcd.print("AMBIENTE OK");

  }
  else if (temperatura < 33) {

    digitalWrite(LEDPIN, HIGH);
    noTone(BUZZERPIN);

    lcd.setCursor(0,1);
    lcd.print("ATENCAO");

  }
  else {

    digitalWrite(LEDPIN, HIGH);

    tone(BUZZERPIN, 1000);

    lcd.setCursor(0,1);
    lcd.print("RISCO ALTO");
  }

  delay(3000);
}