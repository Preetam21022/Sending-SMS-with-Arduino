#include <SoftwareSerial.h>   
#define rxPin 9  
#define txPin 8  
SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);  
char text[150];   
String message="";
int i;   

void setup(){ 
  
pinMode(10,OUTPUT);  
Serial.begin(9600);  
while (!Serial){}  
mySerial.begin(9600); 
digitalWrite(10,0);
delay(1000); 
digitalWrite(10,1);
Serial.println("Write your SMS:");  
}  

void loop(){   

i=0;   
while( Serial.available()>0 ){     
 text[i] = Serial.read();   
 message += text[i];   
 i++;   
 if (text[i-1]==46){  
  Serial.println("Send SMS......");  
  SendTextMessage();  
  ShowSerialData();  
  delay(1000);   
  Serial.println("\r"); 
  Serial.println("Success");   
  message="";  
  i=0;  }}}  


void SendTextMessage(){ 
  
mySerial.print("AT+CMGF=1\r"); 
delay(1000);  
mySerial.print("AT+CMGS=\"+491781234567\"\r");  
delay(1000);  
mySerial.println(message);  
mySerial.print("\r");  
delay(1000);  
mySerial.println((char)26);  
mySerial.println();  }  


void ShowSerialData(){  

while(mySerial.available()!=0)  
 Serial.write(mySerial.read());}  


