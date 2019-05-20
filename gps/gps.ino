#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define GPS_RX_PIN D3
#define GPS_TX_PIN D4
long lat,lon; // create variable for latitude and longitude object

SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN); // create soft serial object
TinyGPS gps; // create gps object

void setup(){
  Serial.begin(9600); // connect serial
  serialSIM800.begin(9600);
  gpsSerial.begin(9600); // connect gps sensor
  pinMode(GPS_RX_PIN, INPUT);
  pinMode(GPS_TX_PIN, OUTPUT);
}

void loop(){
  while(gpsSerial.available()){ // check for gps data
   if(gps.encode(gpsSerial.read())){ // encode gps data
    gps.get_position(&lat,&lon); // get latitude and longitude
    Serial.print("lat: ");
    Serial.print(lat);
    Serial.print("//");
    Serial.print("lon: ");
    Serial.println(lon);
   }
  }
}
