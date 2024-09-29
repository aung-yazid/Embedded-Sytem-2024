int led = 6; //membuat variabel LED dengan pin arduino 6

void setup(){
  pinMode(led, OUTPUT); //mendeklarasikan LED sebagai output
}

void loop(){
  digitalWrite(ledPin, HIGH); //menuliskan kondisi led hidup selama 1 detik 
  delay(1000);
  digitalWrite(ledPin, LOW); //menuliskan kondisi led mati selama 1 detik
  delay(1000);
}