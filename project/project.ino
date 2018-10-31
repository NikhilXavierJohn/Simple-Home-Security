#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include<DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT11
#define SS_PIN 10
#define RST_PIN 9
DHT dht(DHTPIN,DHTTYPE);
//#define LED_G 5 //define green LED pin
//#define LED_R 4 //define red LED
//#define BUZZER 2 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
int hum,temp;
String Name;
int Relay1 = 5; 
int Relay2 = 6; 
int sensorPin = A0;
int sensorValue = 0;
int sensor = 7;             
int state = LOW;
int val = 0; 
int val1=0;  
int door=4;

void setup() 
{
  int Position=90;
  val = digitalRead(sensor);
  pinMode(Relay1, OUTPUT); 
  pinMode(Relay2, OUTPUT); 
  pinMode(sensor, INPUT);
  pinMode(door, INPUT);
  Serial.begin(9600);   // Initiate a serial communication
  dht.begin();
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(Position); //servo start position
//  pinMode(LED_G, OUTPUT);
//  pinMode(LED_R, OUTPUT);
//  pinMode(BUZZER, OUTPUT);
//  noTone(BUZZER);
//  Serial.println("Put your card to the reader...");
  digitalWrite(Relay1, HIGH);   //Turn off relay 
  digitalWrite(Relay2, HIGH);    //Turn on relay 
//  Serial.println();
  

}
void loop() 
{
  
  val1=digitalRead(door);
  while(val1==HIGH){
    digitalWrite(Relay1, LOW);   //Turn off relay 
    digitalWrite(Relay2, LOW);
    Serial.println("NULL,NULL,NULL,NULL,NULL,NULL,ALERT");
    delay(1000);
    val1 = digitalRead(door);
  }
  val=digitalRead(sensor);
  while(val == HIGH ) {

      digitalWrite(Relay1, LOW);   //Turn off relay 
      digitalWrite(Relay2, LOW);
      delay(500);
      digitalWrite(Relay1, HIGH);   //Turn off relay 
      digitalWrite(Relay2, HIGH);
      delay(500);
      digitalWrite(Relay1, LOW);   //Turn off relay 
      digitalWrite(Relay2, LOW);
      delay(500);
      digitalWrite(Relay1, HIGH);   //Turn off relay 
      digitalWrite(Relay2, HIGH);
      delay(500);
      digitalWrite(Relay1, LOW);   //Turn off relay 
      digitalWrite(Relay2, LOW);
      delay(500);
      digitalWrite(Relay1, HIGH);   //Turn off relay 
      digitalWrite(Relay2, HIGH);
      delay(500);
      digitalWrite(Relay1, LOW);   //Turn off relay 
      digitalWrite(Relay2, LOW);
      delay(500);
      digitalWrite(Relay1, HIGH);   //Turn off relay 
      digitalWrite(Relay2, HIGH);
      delay(500);
      digitalWrite(Relay1, LOW);   //Turn off relay 
      digitalWrite(Relay2, LOW);
      delay(500);
      digitalWrite(Relay1, HIGH);   //Turn off relay 
      digitalWrite(Relay2, HIGH);
    delay(2000);
    val = digitalRead(sensor);// delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("NULL,NULL,NULL,NULL,NULL,NULL,ALERT");
      state = HIGH;       // update variable state to HIGH
    }
  }
  hum=dht.readHumidity();
  sensorValue = analogRead(sensorPin);
  if(sensorValue<500){
    digitalWrite(Relay1, LOW);   //Turn off relay 
    digitalWrite(Relay2, LOW);
  }
  else{
    digitalWrite(Relay1, HIGH);   //Turn off relay 
    digitalWrite(Relay2, HIGH);
  }  
  Serial.print(sensorValue);
  Serial.print(",");
  temp=dht.readTemperature();
  Serial.print("Humidity :");
  Serial.print(hum);
  Serial.print(",");
  Serial.print("Temperature :");
  Serial.print(temp);
  Serial.print(",");
  Serial.print("");
  delay(2000);
  int Position=90;
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    Serial.print("No card Detected,");
    Serial.print("NULL,");
    Serial.println("Door close,NULL.");
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.print(",");
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "90 D1 CF A6" || content.substring(1) == "40 65 25 D9" ) //change here the UID of the card/cards that you want to give access
  {
    if (content.substring(1) == "90 D1 CF A6"){
      Serial.print("Pradyumna,NULL.");
      Name="Pradyumna";
    }
    if (content.substring(1) == "40 65 25 D9"){
      Serial.print("Naveen,NULL.");
      Name="Naveen";
    }
//    Serial.print("Authorized access");
    
    delay(500);
    delay(300);
    Position=180;
    Serial.println("Door Open,NULL.");
    myServo.write(Position);
    digitalWrite(Relay1, LOW);   //Turn off relay 
    digitalWrite(Relay2, LOW);
    delay(5000);
    Position=90;
    myServo.write(Position);
    delay(1000);
    digitalWrite(Relay1, HIGH);   //Turn off relay 
    digitalWrite(Relay2, HIGH);
  }
 
 else   {
    Serial.println(" Access denied , NULL.");

    delay(1000);


  }
} 
