#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

int RedLed = 13;
int BlueLed = 12;

int value;

void setup()
{
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
  Serial.begin(9600);
  pinMode(RedLed,OUTPUT);
  pinMode(BlueLed,OUTPUT);
}
void loop()
{
  delay(2000);
  digitalWrite(BlueLed,HIGH);
  
  value = analogRead(A0);

  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Gas Level: ");
  lcd.setCursor(11,0);
  lcd.print(value);
  
  Serial.println(value);
  
  if (value > 400){
    digitalWrite(BlueLed,LOW);
    Serial.print ("Alert ");Serial.println(value);

    lcd.setCursor(0,2);
    lcd.print("Alert.....");
    
    for(int BackLight = 0; BackLight<10; BackLight++){
      lcd.display();
      digitalWrite(RedLed,HIGH);
      delay(250);
      digitalWrite(RedLed,LOW);
      lcd.noDisplay();
      delay(250);
    }
    lcd.display();
  }
  else {
    Serial.print("Normal ");Serial.println(value);
    
    lcd.setCursor(0,2);
    lcd.print("Normal");
    //digitalWrite(BlueLed,LOW);
  }
  digitalWrite(BlueLed,LOW);
  
}
