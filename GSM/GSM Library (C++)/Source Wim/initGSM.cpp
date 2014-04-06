#include "arduPi.h"

void switchModule();

int onModulePin = 2;        // the pin to switch on the module (without press on button)

int count = 0;

int n_sms,x,sms_start;
char data[256];

void switchModule(){
    digitalWrite(onModulePin,HIGH);
    delay(1500);
    digitalWrite(onModulePin,LOW);
}

void setup(){

    Serial.begin(115200);                // UART baud rate
    delay(1500);
    pinMode(onModulePin, OUTPUT);
    switchModule();                    // switches the module ON
    for (int i=0;i< 2;i++){
        delay(5000);
    } 

    Serial.println("AT+CPIN=5370");
    delay(4500);
    Serial.println("AT+CMGF=1");         // sets the SMS mode to text
    delay(2500);
}

void loop(){
    Serial.println("AT+CPMS=\"SM\",\"SM\",\"SM\"");    //selects SIM memory
    Serial.flush();
    delay(500);
    Serial.println("AT+CMGL=\"ALL\"");
    Serial.flush();
    printf("INIT DONE");
}

int main (){
	setup();
	loop();
	return (0);
}

