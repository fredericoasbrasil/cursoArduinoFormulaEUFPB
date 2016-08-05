#include <SoftwareSerial.h>
#include <TinyGPS++.h> 
TinyGPSPlus gps; //Cria o objeto gps

static const int RXPin = 4, TXPin = 3; //Constantes dos pinos RX e TX
static const uint32_t GPSBaud = 9600; //Baud Rate do GPS (Padrão)

SoftwareSerial ss(RXPin, TXPin); //Usa 'ss' como serial nos pinos RXPin e TXPin

char latitude[10];
char longitude[10];

void setup() {
  Serial.begin(115200); //Baud rate do console
  ss.begin(GPSBaud);    //Baud rate do GPS
}

void loop() {
  while(ss.available()){
   String dados = "";
      Serial.println("teste2");
      delay(100);
    if(gps.encode(ss.read())){
      Serial.println("teste");
      dtostrf((gps.location.lat()), 5, 5, latitude);
      dtostrf((gps.location.lng()), 5, 5, longitude);
      
      dados += latitude;
      dados += " ;";
      dados += longitude;     
      Serial.println(dados);  
  }
  delay(1000);  
  }
}
