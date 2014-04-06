#include "arduPi.h"

void switchModule();

int led = 9;
int onModulePin = 2;        // the pin to switch on the module (without press on button)

int timesToSend = 1;        // Numbers of SMS to send
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
printf("Code enter");
delay(3000);
printf("1");
    Serial.println("AT+CMGF=1");         // sets the SMS mode to text
    delay(1001);
printf("2");
}

void loop(){

    while (count < timesToSend){
        delay(1500);
        Serial.println("AT+CPMS=\"SM\",\"SM\",\"SM\"");    //selects SIM memory     
Serial.flush();
//        for (x=0;x< 255;x++){            
//            data[x]='\0';                        
//        } 
//        x=0;
//        do{
//            while(Serial.available()==0);
//            data[x]=Serial.read();  
//            x++;

//        }while(!(data[x-1]=='K'&&data[x-2]=='O'));

//        n_sms=((data[32]-0x30)*10)+(data[33]-0x30);    

//        Serial.print(n_sms,DEC);
//        Serial.println("  SMS stored in SIM memory. Showing last SMS:");    
        // shows the total number of SMS and the last SMS

        Serial.println("AT+CMGL=\"ALL\"");    //Reads the last SMS 
Serial.flush();
delay(1000);
Serial.println("AT+CMGD=,4");        
        Serial.flush();
printf("66");
        for (x=0;x< 255;x++){
           data[x]='\0';
        } 
        x=0;
printf(";;;");
      do{
	if(Serial.available() > 0)
{
           data[x]=Serial.read();
printf("YES");
}
           x++;

//printf(""); 
//printf(data[x]);
  //          if(data[x-1]==0x0D&&data[x-2]=='"'){
    //            x=0;
      //      }
        }while(!(data[x-1]=='K'&&data[x-2]=='O')||(x==1));

     //   data[x-3]='\0';        //finish the string before the OK

       // printf("%s",data);    //shows the message

        //delay(5000);

        count++;
    }
}

int main (){
	setup();
	
		loop();
	return (0);
}

