// Open Source
// KY-013 ANALOG TEMP

#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
#include <math.h>

int pinOut = 10;

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = (Temp * 2.89193);        
 return Temp;
}

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)  
}

void loop() {             
  int val;                
  double temp;            
  val=analogRead(0);      
  temp=Thermistor(val);
  lcd.clear();
  Serial.print("TEMPERATURA = ");
  Serial.print(temp);   
  Serial.println(" C");
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("  TEMPERATURA"); //IMPRIME O TEXTO NO DISPLAY LCD
  lcd.setCursor(4,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print(temp); //IMPRIME O TEXTO NO DISPLAY LCD
  lcd.print(" *C"); //IMPRIME O TEXTO NO DISPLAY LCD
  
  delay(500);            
}
