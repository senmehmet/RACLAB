#include <dht11.h>// dht11 kütüphanesini ekle
dht11 DHT11; // Dht11 kütüphanesini DHT11 Olarak adlandırılmasını belirle.
int isiSensor = 3, fan = 8;

void setup () {// custom bölümü
  Serial.begin (9600); // Seri portu iletişime aç Hızını 9600 Olarak ayarla.

  pinMode(isiSensor, INPUT);                      //isiSensor portunu giriş olarak ayarla.
  pinMode(fan, OUTPUT);                             //fan portunu çıkış olarak ayarla.
}

void loop () {// kodların çalışacağı döngünün baslamasi
  int isi = DHT11.read(isiSensor);               //isiSensor’den gelen değeri DHT kütüphanesinin read komutu ile okuyup isi’in içene aktar.

  Serial.println ((float) DHT11.humidity, 2); // Seri port ekranına DHT11 kütüphanesinden humidity’nin (nem) değerini Yazdır.
  Serial.println ((float) DHT11.temperature, 2); // Seri port ekranına DHT11 kütüphanesinden temperature’nin (santigrat biriminde temperature) değerini Yazdır.

  float derece = DHT11.temperature;                     //daha önce okunan sıcaklık değerini derecenin içene aktar.
  if (DHT11.temperature >= 28) // Eger derece’nin Değeri 25’den Büyük imkb {} Arasındaki İşlemleri yap.
  {
    digitalWrite(fan, HIGH); // fan portuna elektrik gönder. 1 Değeri gönder.
  }
  else
  {
    digitalWrite(fan, LOW);
  } // fan portuna elektrik gönderme. 0 Değeri gönder.
}
