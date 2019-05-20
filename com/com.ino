/*
* Arduino GSM Alert (v1.0)
* An Arduino Uno + SIM800L GSM Module Project
* T.K.Hareendran / 2018
*/
//Connect the Tx pin of the SIM800L module to D10
//Connect the Rx pin of the SIM800L module to D11
//SMS Trigger Input (Sense Pin) connected to D3 (Active LOW)
// Connect a push-to-on button switch between D3 and GND
// Push the button switch/ground D3 to send a pre-defined SMS

#include <SoftwareSerial.h>
#define SIM800_RX_PIN D5
#define SIM800_TX_PIN D6

SoftwareSerial smsSerial(SIM800_TX_PIN,SIM800_RX_PIN); //(10,11) RX and TX pins to communicate with SIM800L module


String number =""; // Replace this 10-digits with  recipient's number

void setup()
{
  pinMode(D8, OUTPUT);
  Serial.begin(9600);
  smsSerial.begin(9600);
}

unsigned long loop_counter = 0;
void loop()
{
  loop_counter++;              
  digitalWrite(D8, LOW);   
  if (loop_counter >= 9600000)
  {
    digitalWrite(D8, HIGH);  
    loop_counter=0;
    smsSerial.println("AT+CMGF=1"); // Set the Mode as Text Mode
    delay(150);
    smsSerial.println("AT+CMGS=\"+33608359137\""); // Specify the recipient's number in international format by replacing the 91
    delay(150);
    smsSerial.print("Warning! SIM800L"); // Enter the custom message
    delay(150);
    smsSerial.write((byte)0x1A); // End of message character 0x1A : Equivalent to Ctrl+z
    delay(50);
    smsSerial.println();
  }
}
