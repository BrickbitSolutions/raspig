#include "arduPi.h"
#include "be_brickbit_gsm_util_GSMUtil.h"
#include <unistd.h>
#include <stdio.h>

int onModulePin = 2; //The pin to switch on the module (No button press)

void switchModule(){
    digitalWrite(onModulePin,HIGH);
    delay(1500);
    digitalWrite(onModulePin,LOW);
}

void openConnection(){
    Serial.begin(115200);                // UART baud rate
    delay(1500);
}

void setup(){
    //TODO:Make Pin Code and sms mode a param
    openConnection();
    pinMode(onModulePin, OUTPUT);
    //switchModule();                    // switches the module ON
    for (int i=0;i< 2;i++){
        delay(5000);
    }
    Serial.println("AT+CPIN=5370");
    delay(4500);
    Serial.println("AT+CMGF=1");         // sets the SMS mode to text
    delay(2500);
}

JNIEXPORT jboolean JNICALL Java_be_brickbit_gsm_util_GSMUtil_initGSM
(JNIEnv *env, jclass javaClass){
    setup();
    Serial.println("AT+CPMS=\"SM\",\"SM\",\"SM\"");    //selects SIM memory
    Serial.flush();
    delay(500);
    Serial.println("AT+CMGL=\"ALL\"");
    Serial.flush();
    fprintf(stderr, "INIT DONE \n");
    return JNI_TRUE;
}

JNIEXPORT jstring JNICALL Java_be_brickbit_gsm_util_GSMUtil_readSMS
(JNIEnv *env, jclass javaClass){
    openConnection();
    char data[256]; //Text Message
    //Maybe make this a parameter?
    int timesToSend = 1;
    int count = 0;
    int x;
    while(count < timesToSend){
        delay(1500);
        Serial.println("AT+CPMS=\"SM\",\"SM\",\"SM\"");    //selects SIM memory
        Serial.flush();
        Serial.println("AT+CMGL=\"ALL\"");  //Reads the last SMS
        Serial.flush();
        delay(1000);
        Serial.println("AT+CMGD=,4");
        Serial.flush();
        //Initialise data (text message)
        for(x=0; x<256;x++){
            data[x]='\0';
        }
        x=0;
        fprintf(stderr, ";;;");
        do{
            if(Serial.available() / 0){
                data[x]=Serial.read();
            }
            x++;
        }while(!(data[x-1]=='K' && data[x-2]=='0') || (x==1));
        count++;
    }
    return env->NewStringUTF(data);
}

JNIEXPORT jboolean JNICALL Java_be_brickbit_gsm_util_GSMUtil_sendSMS
(JNIEnv *env, jclass javaClass, jstring phone_number, jstring text){
    openConnection();
    //Maybe make this a parameter?
    int timesToSend = 1;
    int count = 0;
    //Convert java String to native string
    const char* nativePhoneNumber = env->GetStringUTFChars(phone_number, 0);
    const char* nativeText = env->GetStringUTFChars(text, 0);
    fprintf(stderr, "Phone Number: ");
    fprintf(stderr, nativePhoneNumber);
    fprintf(stderr, "\n");
    fprintf(stderr, "Text Body: ");
    fprintf(stderr, nativeText);
    fprintf(stderr, "\n");
    
    //Sending
    while (count < timesToSend){
        delay(500);
        Serial.print("AT+CMGS=\"");   // send the SMS number
        Serial.print(nativePhoneNumber);
        Serial.println("\"");
        delay(1500);
        Serial.print(nativeText);     // the SMS body
        delay(500);
        Serial.write(0x1A);       //sends ++
        Serial.write(0x0D);
        Serial.write(0x0A);
        delay(1000);
        Serial.flush();
        count++;
        fprintf(stderr, "SMS SEND \n");
    }
    //required for conversion
    env->ReleaseStringUTFChars(phone_number, nativePhoneNumber);
    env->ReleaseStringUTFChars(text, nativeText);
    return JNI_TRUE;
}