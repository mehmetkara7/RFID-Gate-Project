#include <Servo.h>
#include <SPI.h>                   //SPI kütüphanemizi tanımlıyoruz.
#include <MFRC522.h>              //MFRC522 kütüphanemizi tanımlıyoruz.

int RST_PIN = 9; //RC522 modülü reset pinini tanımlıyoruz.
int SS_PIN = 10; //RC522 modülü chip select pinini tanımlıyoruz.
int servoPin = 8; //Servo motor pinini tanımlıyoruz.
int buzzerPin=7;
Servo motor; //Servo motor için değişken oluşturuyoruz.
MFRC522 rfid(SS_PIN, RST_PIN); //RC522 modülü ayarlarını yapıyoruz.
byte ID[4] = {
  53,
  135,
  120,
  118
}; //Yetkili kart ID'sini tanımlıyoruz. 
byte ID1[4] = {
  207,
  195,
  187,
  2
};
void ekranaYazdir() {
  Serial.print("ID Numarasi: ");
  for (int sayac = 0; sayac < 4; sayac++) {
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print(" ");
  }
  Serial.println("");
}
void setup() {
  motor.attach(servoPin); //Servo motor pinini motor değişkeni ile ilişkilendiriyoruz.
  Serial.begin(9600); //Seri haberleşmeyi başlatıyoruz.
  SPI.begin(); //SPI iletişimini başlatıyoruz.
  rfid.PCD_Init(); //RC522 modülünü başlatıyoruz.
  pinMode(7,OUTPUT);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) //Yeni kartın okunmasını bekliyoruz.
    return;

  if (!rfid.PICC_ReadCardSerial()) //Kart okunmadığı zaman bekliyoruz.
    return;

  if (rfid.uid.uidByte[0] == ID[0] && //Okunan kart ID'si ile ID değişkenini karşılaştırıyoruz.
    rfid.uid.uidByte[1] == ID[1] &&
    rfid.uid.uidByte[2] == ID[2] &&
    rfid.uid.uidByte[3] == ID[3]) {
    Serial.println("Kapi acildi");
    ekranaYazdir(); 
   motor.write(180); //Servo motoru 180 dereceye getiriyoruz.
    delay(3000);
    motor.write(0); //Servo motoru 0 dereceye getiriyoruz.
    delay(1000);
  }
  
  else if (rfid.uid.uidByte[0] == ID1[0] && //Okunan kart ID'si ile ID değişkenini karşılaştırıyoruz.
    rfid.uid.uidByte[1] == ID1[1] &&
    rfid.uid.uidByte[2] == ID1[2] &&
    rfid.uid.uidByte[3] == ID1[3]) {
    Serial.println("Kapi acildi");
    ekranaYazdir();
    motor.write(180); //Servo motoru 180 dereceye getiriyoruz.
    delay(3000);
    motor.write(0); //Servo motoru 0 dereceye getiriyoruz.
    delay(1000);} 
    
  else { //Yetkisiz girişte içerideki komutlar çalıştırılır.
    Serial.println("Yetkisiz Kart");
    ekranaYazdir();
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(7,LOW);
  }
  rfid.PICC_HaltA();
}

 
