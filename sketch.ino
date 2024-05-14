#include "DHTesp.h"
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

const int DHT_PIN = 15;

DHTesp dhtSensor;

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup() {

  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  lcd.init();
  lcd.backlight();

}

void loop() {

  TempAndHumidity dados = dhtSensor.getTempAndHumidity  ();
  
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: " + String(dados.temperature, 1) + "\xDF"+"C  ");
  lcd.setCursor(0, 1);
  lcd.print("Humidade: " + String(dados.humidity, 1) + "% ");

  delay(1000);
}