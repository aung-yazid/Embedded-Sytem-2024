#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trig = A0; //membuat parameter trig untuk HCSR-04 dan terhubung dengan pin A0 arduino
const int echo = A1; //membuat parameter echo untuk HCSR-04 dan terhubung dengan pin A1 arduino

void setup(){
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.init();
  lcd.setBacklight(HIGH);
}

void loop(){
  //mengatur pembacaan sensor HCSR04
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH); //pembacaan frequensi suara dengan jarak didepannya
  float cm = duration*0.034/2; //rumus untuk konversi frequensi suara menjadi jarak
  
  lcd.setCursor(0,0); //seting posisi penempatann pada titik 0,0
  lcd.print("Jarak Sensor :"); //mencetak variabel string kedalam lcd dengan posisi sesuai perintah sebelumnya
  lcd.setCursor(0,1);
  lcd.print(cm);
  
  //Tampilkan data pada serial monitor
  Serial.print("Jarak yang terbaca : ");
  Serial.print(cm);
  Serial.println(" CM"); //println untuk memberikan enter pada data yang akan dikeluarkan selanjutnya

  delay(500); //proses 0.5 detik sekali
}
