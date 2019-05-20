#include <SoftwareSerial.h>

#define GPS_RX_PIN D3
#define GPS_TX_PIN D4
#define loop_counter 0

void setup(){
  Serial.begin(9600); // connect serial
  serialSIM800.begin(9600);
  
}

void loop(){
  loop_counter++;
  if (loop_counter >= 20000){
    loop_counter = 0;
    Serial.println("Sending SMS...");
    serialSIM800.write("AT+CMGF=1\r\n");
    delay(1000);
    serialSIM800.write("AT+CMGS=\"0608359137\"\r\n");
    delay(1000);
    serialSIM800.write("TEST");
    delay(1000);
    serialSIM800.write((char)26);
    delay(1000);
    Serial.println("SMS Sent!");
  }
}
