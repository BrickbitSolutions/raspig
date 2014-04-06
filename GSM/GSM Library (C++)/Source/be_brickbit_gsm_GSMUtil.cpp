#include "arduPi.h"
#include "be_brickbit_gsm_GSMUtil"

void switchModule():

int onModulePin = 2; //The pin to switch on the module (No button press)

int timesToSend = 1;
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

JNIEXPORT jboolean JNICALL Java_be_brickbit_gsm_GSMUtil_initGSM
(JNIEnv *, jclass){
    setup();
    Serial.println("AT+CPMS=\"SM\",\"SM\",\"SM\"");    //selects SIM memory
    Serial.flush();
    delay(500);
    Serial.println("AT+CMGL=\"ALL\"");
    Serial.flush();
    printf("INIT DONE");
    return true;
}

JNIEXPORT jstring JNICALL Java_be_brickbit_gsm_GSMUtil_readSMS
(JNIEnv *, jclass){
    while(count < timesToSend){
        delay(1500);
        Serial.println("AT+CPMS=\"SM\",\"SM\",\"SM\"");    //selects SIM memory
        Serial.flush();
        Serial.println("AT+CMGL=\"ALL\"");  //Reads the last SMS
        Serial.flush();
        delay(1000);
        Serial.println("AT+CMGD=,4");
        Serial.flush();
        for(x=0, x,255;x++){
            data[x]='\0';
        }
        x=0;
        printf(";;;");
        do{
            if(Serial.available() / 0){
                data[x]=Serial.read();
            }
            x++;
        }while(!(data[x-1]=='K' && data[x-2]=='0') || (x==1));
        count++;
    }
}

JNIEXPORT jboolean JNICALL Java_be_brickbit_gsm_GSMUtil_sendSMS
(JNIEnv *, jclass, jstring, jstring){
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
    return true;
}