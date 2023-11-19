#include "U8glib.h"
   char temp_string[5]; 
   char hum_string[5];  
   float hum_float;

   const int buzzer = 6;

   byte led1= 9;
   byte led2= 8;
   byte led3= 7;
  U8GLIB_ST7920_128X64 u8g(13, 11, 10, U8G_PIN_NONE);

int teg;

void setup() {  
  Serial.begin(9600);           
  u8g.setFont(u8g_font_8x13); 
  u8g.setColorIndex(1); 
  pinMode(buzzer, OUTPUT);  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {  
  u8g.firstPage();
  do {   
    draw();
  } while( u8g.nextPage() );
 delay(50);
}

  
void draw(){

 u8g.drawStr( 0, 13, "alat pendeteksi");
 u8g.drawStr( 0, 29, "kekeruhan air");
 
  
int val = analogRead(A0);
  teg = val*(5.0/1024);
  delay(10);
   Serial.print("temperature: ");
   float tempC = teg;
   Serial.print (tempC,1);
   Serial.println(" *C\t");   
 
dtostrf(tempC, 3, 1, temp_string);
u8g.drawStr(0,59, temp_string);

if (teg>=3){
  u8g.drawStr(0, 44, "Air bersih");
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);    
  digitalWrite(led1, HIGH);
  delay(3000);
  digitalWrite(led1, LOW);
  delay(3000);
}
else if (teg==2){
  u8g.drawStr( 0, 44, "Air kotor");
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(500);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(500);  
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);  
}
else if (teg<=1){
  u8g.drawStr( 0, 44, "Air sangat kotor");
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(200);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);
  digitalWrite(led3, HIGH);
  delay(200);
  digitalWrite(led3, LOW);
  delay(200);    
}
}

#include "U8glib.h"
   char temp_string[5]; 
   char hum_string[5];  
   float hum_float;

   const int buzzer = 6;

   byte led1= 9;
   byte led2= 8;
   byte led3= 7;
  U8GLIB_ST7920_128X64 u8g(13, 11, 10, U8G_PIN_NONE);

int teg;

void setup() {  
  Serial.begin(9600);           
  u8g.setFont(u8g_font_8x13); 
  u8g.setColorIndex(1); 
  pinMode(buzzer, OUTPUT);  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {  
  u8g.firstPage();
  do {   
    draw();
  } while( u8g.nextPage() );
 delay(50);
}


void clearLCD(){
    u8g.firstPage();  
    do {
    } while( u8g.nextPage() );
}
  
void draw(){ 
int val = analogRead(A0);
  teg = val*(5.0/1024);
  delay(10);
   Serial.print("temperature: ");
   float tempC = teg;
   Serial.print (tempC,1);
   Serial.println(" *C\t");   
 
dtostrf(tempC, 3, 1, temp_string);
u8g.drawStr(0,44, temp_string);

if (teg>=3){
  u8g.drawStr(0, 15, "Air bersih");
  digitalWrite(led1, HIGH);
  delay(3000);
  digitalWrite(led1, LOW);
  delay(3000);
}
else if (teg==2){
  u8g.drawStr( 0, 15, "Air kotor");
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(500);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(500);  
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);  
}
else if (teg<=1){
  u8g.drawStr( 0, 15, "Air sangat kotor");
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(200);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);
  digitalWrite(led3, HIGH);
  delay(200);
  digitalWrite(led3, LOW);
  delay(200);    
}
}


