#include "arduPi.h"

void switchModule();

int onModulePin = 2;        // the pin to switch on the module (without press on button)
int timesToSend = 1;        // Numbers of SMS to send
int count = 0;

char phone_number[]="+32498699869";

void switchModule(){
    digitalWrite(onModulePin,HIGH);
    delay(2000);
    digitalWrite(onModulePin,LOW);
}

void setup(){

    Serial.begin(115200);                // UART baud rate
    delay(2000);
//    pinMode(led, OUTPUT);
//    pinMode(onModulePin, OUTPUT);
//    switchModule();                    // switches the module ON

//    for (int i=0;i< 2;i++){
//        delay(5000);
//    } 

//    Serial.println("AT+CMGF=1");         // sets the SMS mode to text
//    delay(100);
}

void loop(){

    while (count < timesToSend){
        delay(500);
        Serial.print("AT+CMGS=\"");   // send the SMS number
        Serial.print(phone_number);
    	Serial.println("\""); 
        delay(1500);      
        Serial.print("System offline.");     // the SMS body
        delay(500);
        Serial.write(0x1A);       //sends ++
        Serial.write(0x0D);
        Serial.write(0x0A);

        delay(1000);

        count++;
    }
}

int main (){
	setup();
	loop();
	return (0);
}
