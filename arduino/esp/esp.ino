#define BLYNK_TEMPLATE_ID           "TMPLZhVH8x5S"
#define BLYNK_DEVICE_NAME           "Control de gato"
#define BLYNK_AUTH_TOKEN            "7_co05zOFGM0DaXieyc606fjWncCOHNJ"
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include<iostream>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h> 
//CREAMOS UN NUEVO PUERTO SERIE (RX, TX)
SoftwareSerial Serie2(D9,D10); 
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Galaxy A02s1027";
char pass[] = "aedu4200";
BlynkTimer timer;
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, value);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V4);
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}
void setup()
{ pinMode(13,OUTPUT);
  Serial.begin(115200);          //Inicializa puerto estÃ¡ndar
  Serie2.begin(9600);         //Inicializa nuevo puerto
  digitalWrite(13,LOW);
  Blynk.begin(auth, ssid, pass);
timer.setInterval(1000L, myTimerEvent);
}
void loop()
{ 
  Blynk.run();
  timer.run();
  
//Blynk.virtualWrite(V6, Serial.read());
if (Serie2.available())
  {
    
  int datox= Serie2.read();
  Blynk.virtualWrite(V6, datox);
  //Serie2.println(datox);
  if((datox)>=50){
    Blynk.virtualWrite(V9, "No");
    }else{
      Blynk.virtualWrite(V9, "Si");
      }
      delay(1000);
      int datox2= Serie2.read();
  //Serie2.println(datox2);
  Blynk.virtualWrite(V7, datox2);
  if((datox2)>=19){
    Blynk.virtualWrite(V8, "Caliente");
    }else{
      Blynk.virtualWrite(V8, "Fresca");
      }
 delay(1000);
  int datox3= Serie2.read();
  //Serie2.println(datox3);
  Blynk.virtualWrite(V11, datox3);
  if((datox3)>=49){
    Blynk.virtualWrite(V10, "No");
    }else{
      Blynk.virtualWrite(V10, "Si");
      }
   }
   delay(1000);
}
