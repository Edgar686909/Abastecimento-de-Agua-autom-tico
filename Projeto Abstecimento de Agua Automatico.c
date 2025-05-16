// equipe: Edgar e Levi
// C++ code
//
#include <LiquidCrystal.h>

int umidade = 0;

LiquidCrystal lcd_1(0, 1, 2, 3, 4, 5);

void setup()
{
  pinMode(A3, INPUT);
  lcd_1.begin(16, 2); 
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  umidade = map(analogRead(A3), 0, 1023, 0, 100);
  lcd_1.setCursor(0, 0);
  lcd_1.noAutoscroll();
  if (umidade > 1) {
    lcd_1.clear();
    lcd_1.print("maximo");
  } else {
    umidade = map(analogRead(A2), 0, 1023, 0, 100);
    lcd_1.setCursor(0, 0);
    lcd_1.noAutoscroll();
    if (umidade > 1) {
      lcd_1.clear();
      lcd_1.print("3 litros");
    } else {
      umidade = map(analogRead(A1), 0, 1023, 0, 100);
      lcd_1.setCursor(0, 0);
      lcd_1.noAutoscroll();
      if (umidade > 1) {
        lcd_1.clear();
        lcd_1.print("2 litros");
      } else {
        umidade = map(analogRead(A0), 0, 1023, 0, 100);
        lcd_1.setCursor(0, 0);
        lcd_1.noAutoscroll();
        if (umidade <= 1) {
          lcd_1.clear();
          lcd_1.print("vazio");
        }
      }
    }
  }
  delay(10);
}
