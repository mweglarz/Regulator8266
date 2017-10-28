#include <dht11.h>
 
dht11 DHT11;
 
#define D2 4    //przypisanie pinu 2 Arduino jako odczyt z sensora
 
void setup()
{
//  Serial.println("Test");
    Serial.begin(9600);                    //inicjalizacja monitora szeregowego
    Serial.println("Program testowy DHT11"); 
    Serial.println();
}
 
void loop()
{
  int chk = DHT11.read(D2);         //sprawdzenie stanu sensora, a następnie wyświetlenie komunikatu na monitorze szeregowym
 
  Serial.print("Stan sensora: ");
  switch (chk)
  {
    case DHTLIB_OK: 
        Serial.print("OK\t"); 
        break;
    case DHTLIB_ERROR_CHECKSUM: 
        Serial.println("Blad sumy kontrolnej"); 
        break;
    case DHTLIB_ERROR_TIMEOUT: 
        Serial.println("Koniec czasu oczekiwania - brak odpowiedzi"); 
        break;
    default: 
        Serial.println("Nieznany blad"); 
        break;
  }
  Serial.print("Wilgotnosc (%): ");              //wyświetlenie wartości wilgotności
  Serial.print((float)DHT11.humidity, 2);
  Serial.print("\t\t");
  Serial.print("Temperatura (C): ");           //wyświetlenie temperatury
  Serial.println((float)DHT11.temperature, 2);
//  Serial.println("Test message");

  delay(10000);                                  //opóźnienie między kolejnymi odczytami - 1 s
} 


