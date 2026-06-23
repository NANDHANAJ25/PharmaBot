#include <ThingSpeak.h> 
#include <WiFi.h> 
WiFiClient client; 
#include <LCD_I2C.h> 
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according 
float val,m1,m2,m3,m4,m5; 

#include <ESP32Servo.h> 
Servo s1,s2,s3,s4,s5; 
int pos = 0,a=0,b=0,c=0,d=0,e=0; 
const char* host = "api.thingspeak.com"; 
const char* streamId   = "YOUR_WRITE_API_KEY"; 

void setup()  
{ 
Serial.begin(9600); 
WiFi.mode(WIFI_STA); 
WiFi.begin("WIFI_NAME","PASSWORD"); 
Serial.println("connecting"); 
while(WiFi.status() != WL_CONNECTED) 
  { 
Serial.print("."); delay(100); 
  } 
lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false) 
                 // this stop the library(LCD_I2C) from calling Wire.begin() 
lcd.backlight(); 
lcd.print("   PHARMABOT   "); 
delay(2000);
ESP32PWM::allocateTimer(0); 
  ESP32PWM::allocateTimer(1); 
  ESP32PWM::allocateTimer(2);   
  ESP32PWM::allocateTimer(3); 
  s1.setPeriodHertz(50);    // standard 50 hz servo 
  s1.attach(32); 
s2.setPeriodHertz(50);    // standard 50 hz servo 
s2.attach(33); 
s3.setPeriodHertz(50);    // standard 50 hz servo 
s3.attach(25); 
s4.setPeriodHertz(50);    // standard 50 hz servo 
s4.attach(26); 
s5.setPeriodHertz(50);    // standard 50 hz servo 
s5.attach(27); 
ThingSpeak.begin(client); 
s1.write(0); 
s2.write(0); 
s3.write(0); 
s4.write(0); 
s5.write(0); 
pinMode(19,INPUT_PULLUP); 
} 
void loop()  
{ 
//  if(digitalRead(19)==0) 
//{ 
//  lcd.clear(); 
//  lcd.print("Payment Done...");   
//  delay(2000); 
val = ThingSpeak.readFloatField(2901126,1,"2484DVDT7N8NGX10"); 
Serial.println(val); 
delay(1000); 
if(val==1) 
  { 
delay(2000); 
 m1 = ThingSpeak.readFloatField(2901136,1,"M72ZP9WZOWGBAP3E"); 
Serial.println(m1); 
delay(500); 
if(m1>0) 
{ 
  lcd.clear(); 
  lcd.print("ASPIRIN: ");   
  lcd.print(m1); 
  delay(2000);   
  
  for(int i=0;i<m1;i=i+1) 
{ 
Serial.println("for 1"); 
if(a==0)  
{ 
for (pos = 0; pos<= 160; pos += 1) 
{   
  s1.write(pos); 
  delay(20); 
  } 
  a=1; 
  } 
  else if(a==1) 
{ 
  
for (pos = 160; pos>= 0; pos -= 1) 
{ 
s1.write(pos);
delay(20); 
  }   
  a=0; 
  } 
  delay(1000); 
  }
  } 
  
  delay(2000); 
  m2 = ThingSpeak.readFloatField(2901136,2,"M72ZP9WZOWGBAP3E"); 
Serial.println(m2); 
delay(500); 
if(m2>0) 
{ 
  lcd.clear(); 
lcd.print("PARACETAMOL:");   
lcd.print(m2); 
delay(2000); 
for(int i=0;i<m2;i=i+1) 
{ 
Serial.println("for 2"); 
if(b==0)  
{  
for (pos = 0; pos<= 160; pos += 1) 
{   
  s2.write(pos); 
  delay(20); 
  } 
  b=1; 
  } 
  else if(b==1) 
{ 
for (pos = 160; pos>= 0; pos -= 1) 
{ 
  s2.write(pos); 
  delay(20); 
  }   
  b=0; 
  } 
  delay(1000); 
  }
  } 
  delay(2000); 
  m3 = ThingSpeak.readFloatField(2901136,3,"M72ZP9WZOWGBAP3E"); 
Serial.println(m3);
delay(500); 

if(m3>0) 
{ 
  lcd.clear(); 
  lcd.print("NAPROXEN: ");   
  lcd.print(m3); 
  delay(2000); 
  for(int i=0;i<m3;i=i+1) 
{ 
Serial.println("for 2"); 
if(c==0)  
{  
for (pos = 0; pos<= 160; pos += 1) 
{  
  s3.write(pos); 
  delay(20); 
  } 
  c=1; 
} 
else if(c==1) 
{ 
for (pos = 160; pos>= 0; pos -= 1) 
{ 
  s3.write(pos);
  delay(20); 
  }   
  c=0; 
  } 
  delay(1000);
  }
  } 
  delay(2000); 
  
  m4 = ThingSpeak.readFloatField(2901136,4,"M72ZP9WZOWGBAP3E"); 
Serial.println(m4); 
delay(500); 
if(m4>0) 
{ 
  lcd.clear(); 
lcd.print("METOPROLOL:");   
lcd.print(m4); 
delay(2000); 

for(int i=0;i<m4;i=i+1) 
{ 
Serial.println("for 4"); 
 
if(d==0)  {  
for (pos = 0; pos<= 160; pos += 1) 
{   
  s4.write(pos); 
delay(20); 
} 
d=1; 
} 
else if(d==1) 
{ 
for (pos = 160; pos>= 0; pos -= 1) 
{ 
  s4.write(pos); 
delay(20); 
  }   
  d=0; 
  } 
  delay(1000); 
  }
  } 
  delay(2000); 
  
  m5 = ThingSpeak.readFloatField(2901136,5,"M72ZP9WZOWGBAP3E"); 
Serial.println(m5); 
delay(500); 
if(m5>0) 
{ 
  lcd.clear(); 
  lcd.print("DOLO : ");  
  lcd.print(m5); 
  delay(2000); 
  
  for(int i=0;i<m5;i=i+1) 
{ 
Serial.println("for 5"); if(e==0)  
{  
for (pos = 0; pos<= 160; pos += 1) 
{   
  s5.write(pos); 
  delay(20); 
  } 
  e=1; 
  } 
  else if(e==1) 
  { 
for (pos = 160; pos>= 0; pos -= 1) 
{ s5.write(pos);
delay(20); 
  }   
  e=0; 
  } 
  delay(1000); 
}
} 
ThingSpeak.writeField(2901126,1,0,"D0WGJ1JQSV6N24AN"); 
delay(5000); 
sendvaluetoserver(); 
delay(5000); 
  } 
  lcd.clear(); 
  lcd.print("    SCAN QR"); 
  delay(2000); 
 // }
  } 
  
void sendvaluetoserver() 
{ 
const int httpPort = 80; 
if (!client.connect(host, httpPort)) 
{ 
Serial.println("connection failed"); 
return; 
  } 
  // We now create a URI for the request   
 String url = "/update?api_key="; 
 url += streamId; 
 url += "&field1="; 
 url += 0; 
 url += "&field2="; 
 url += 0; 
 url += "&field3="; 
 url += 0; 
 url += "&field4="; 
 url += 0; 
 url += "&field5="; 
 url += 0; 
Serial.print("Requesting URL: "); 
Serial.println(url); 
  // This will send the request to the server 
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + 
               "Host: " + host + "\r\n" +                "Connection: close\r\n\r\n"); unsigned long timeout = millis(); while (client.available() == 0) { if (millis() - timeout > 5000) { Serial.println(">>> Client Timeout !"); client.stop(); return; 
    } 
  } 
  // Read all the lines of the reply from server and print them to Serial 
  while (client.available())  
{ 
    String line = client.readStringUntil('\r'); 
Serial.print(line); 
  } 
Serial.println(); 
Serial.println("closing connection"); 
delay(1000); 
}
