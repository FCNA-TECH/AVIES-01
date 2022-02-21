/*                                                

   -Spider-Man suit AI  AVIES

   This is a Program prototype-01 ,when i get more funding and components i will upgrade it to something greater
   i hope to one day make an actual AI and inject it into my spiderman suit. I Think this Project is AMAZING!
   I am very proud 

   DISCLAIMER: when using the keypad you will need to press down for a while , approximatley 3 seconds ,
               i do not know why this is ,and after days of trying to figure out why the keypad wasnt getting recognised 
               i realised its because im pressing too quick for AVIES to recognise

   Made by Ferdinand Nneji
   started - some time in 2019 i cant remember
   finished 08/11/2020

   AVIES Now functions/works as intended no mistakes have been spotted 

   i used to call this program Evelyn instead of AVIES ,because inspired by how peter parkour picked his personal assistant (Karen) and
   he only picked it because he licked the name ,i think the name Evelyn is quite nice too but unlike JARVIS it has no mening behind it,
   i picked it randomly ,jarvis is an abreviation from Just A Rather Very Intelligent System, and AVIES (pronounced Ayy Vi Ess) means
   A Very Intelligent Expressive System, but it dosnt have the same ring to it as Evelyn, when i get more advanced i will make it accept 
   AVIES as a defaut proffesional name but my nickname for this program will be Evelyn and if i ever call this evelyn it will know it is me 
   and can access special commands

*/


#include <Keypad.h>
#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//i2c pins
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //

dht DHT;

int pirSensor = 10;
int vibMotor = 12;
#define DHT11_PIN 13
const int trigPin = 14; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 15; // Echo Pin of Ultrasonic Sensor

const byte ROWS = 4; 
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

long duration;
int distance;

void setup()
{

  lcd.begin(16,2);      //WE define our LCD 16 columns and 2 rows
  lcd.backlight();      //Power on the back light
  lcd.backlight();      //Power off the back light

  pinMode(pirSensor, INPUT);
  pinMode(vibMotor, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.setCursor(0,0);
  lcd.print("Hello Ferdinand");
  delay(3000);
  lcd.clear();
  lcd.print("I am AVIES");
  delay(3500);
  lcd.clear();
  lcd.print("Your Peronanl");
  lcd.setCursor(0,1);
  lcd.print("Assistant");
  delay(3000);
  lcd.clear();

  lcd.clear();
  lcd.print("Press 1 for: ");
  lcd.setCursor(0,1);
  lcd.print("Temp&Humidity");
  delay(2000);
  lcd.clear();
  delay(10);
  lcd.setCursor(0,0);
  lcd.print("Press 2 for: ");
  lcd.setCursor(0,1);
  lcd.print("Distance sensor");
  delay(2000);
  lcd.clear();
  delay(10);
  lcd.print("Press 1 for: ");
  lcd.setCursor(0,1);
  lcd.print("Temp&Humidity");
  delay(2000);
  lcd.clear();
  delay(10);
  lcd.setCursor(0,0);
  lcd.print("Press 2 for: ");
  lcd.setCursor(0,1);
  lcd.print("Distance sensor");
  delay(2000);
  lcd.clear();
}


void loop(){


  char customKey = customKeypad.getKey();

    delay(500); 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Awaiting");
    lcd.setCursor(0,1);
    lcd.print("Instructions");
    delay(2000);
    lcd.clear();  

 
  if(customKey == '1'){
    for(int h = 0; h <= 25; h++){     
     int chk = DHT.read11(DHT11_PIN);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Temp: ");
     lcd.print(DHT.temperature);
     lcd.print((char)223);
     lcd.print("C");
     lcd.setCursor(0,1);
     lcd.print("Humidity: ");
     lcd.print(DHT.humidity);
     lcd.print("%");
     delay(2000);                 //this is different from the generic 1000 delay because from the data sheet it states the sensor only takes measurments every 2 seconds
      if(h == 25){
        lcd.clear();
        lcd.print("Timed out..");
        delay(2000);
       }
      }
     }
  

    if(customKey == '2'){
     for(int u = 0; u <= 175; u++){
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance= duration*0.034/2;
      delay(300);
      lcd.clear();
      delay(10);
      lcd.setCursor(0,0);
      lcd.print("Distance: ");
      lcd.setCursor(0,1);
      lcd.print(distance);
      lcd.print(" cm");
       if(u == 175){
        lcd.clear();
        lcd.print("Timed out..");
        delay(2000);
        }
       }
      }   


    if(char(customKey) =='3' || char(customKey) =='4' || char(customKey) =='5' || char(customKey) =='6' || char(customKey) =='7' || char(customKey) =='8' || 
       char(customKey) =='9' || char(customKey) =='0' || char(customKey) =='A' || char(customKey) =='B' || char(customKey) =='c' || char(customKey) =='D' ||
       char(customKey) =='*' || char(customKey) =='#'){
        delay(10);
        lcd.clear();
        lcd.setCursor(0,0);            
        lcd.print("Invalid Key");
        delay(1000);
        lcd.clear();    
      }

delay(1000);  //for stability
  
}
