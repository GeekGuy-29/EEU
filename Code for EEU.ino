//* How to use the DHT-11 sensor with Arduino
//   Temperature and humidity sensor and
//   I2C LCD1602
 //  SDA --> A4
 //  SCL --> A5

//Libraries
#include <DHT.h>;
//I2C LCD:
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
  
//Constants
#define DHTPIN 2     // Using the pin 2 to interact with T&H Sensor 
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
int h;  //Stores humidity value
int t; //Stores temperature value
int enA = 10;
int in1 = 9;
int in2 = 8;
int enB = 5;
int in3 = 7;
int in4 = 6;

void setup()
{
    Serial.begin(9600);
    Serial.println("Temperature and Humidity Sensor Test");
    dht.begin();
    lcd.init(); //initialize the lcd
    lcd.backlight(); //open the backlight

    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void loop()
{
    //Read data and store it to variables h (humidity) and t (temperature)
    h = dht.readHumidity();
    t = dht.readTemperature();
    
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %, Temp  ");
    Serial.print(t);
    Serial.println(" ° Celsius");
        
    lcd.setCursor(0, 0);
    lcd.println("Temp:");
    lcd.setCursor(5, 0);
    lcd.print(t);
    lcd.setCursor(8,0);
    lcd.print("Hum:");
    lcd.print(h);
    lcd.print("%");
    
    if(t<=40&&t>=35)
    {
    lcd.setCursor(0,1);
    lcd.println("Fan Speed:= 100%  ");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    delay(2000); //Delay 2 sec
    lcd.clear();
    }
    else if(t<=34&&t>=30)
    {
    lcd.setCursor(0,1);
    lcd.println("Fan Speed:= 80%  ");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 200);
    analogWrite(enB, 200);
    delay(2000); //Delay 2 sec
    lcd.clear();
    }
    else if(t<=29&&t>=25)
    {
    lcd.setCursor(0,1);
    lcd.println("Fan Speed:= 60%  ");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 153);
    analogWrite(enB, 153);
    delay(2000); //Delay 2 sec
    lcd.clear();
    }
    else if(t<=24&&t>=20)
    {
    lcd.setCursor(0,1);
    lcd.println("Fan Speed:= 40%  ");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 102);
    analogWrite(enB, 102);
    delay(2000); //Delay 2 sec
    lcd.clear();
    }
    else if(t>=19&&t<=15)
    {
    lcd.setCursor(0,1);
    lcd.println("Fan Speed:= 20%  ");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 51);
    analogWrite(enB, 51);
    delay(2000); //Delay 2 sec
    lcd.clear();
    }
    else
    {
    lcd.setCursor(0,1);
    lcd.println("Fan Speed:= 0  ");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    delay(2000); //Delay 2 sec
    lcd.clear();
    }
}
