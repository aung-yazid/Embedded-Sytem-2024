int led = 8; //membuat variabel untuk mendeklarasikan pin yang digunakan

void setup() {
  pinMode(led, OUTPUT); //mendeklarasikan bahwa LED diatas adalah sebagai OUTPUT
}

void loop() {
  digitalWrite(led, HIGH); //membuat LED menyala sesuai dengan pin yang di deklarasikan
  delay(1000); //delay
  digitalWrite(led, HIGH);
  delay(1000);
}
