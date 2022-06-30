#include <SoftwareSerial.h>  
#include <dht.h>
//CREAMOS UN NUEVO PUERTO SERIE (RX, TX)
SoftwareSerial Serie2(0,1); 
dht DHT;
#define DHT11_PIN 8
const int pingPin = 2;
int trig=10;
int eco = 9;
int duracion;
int distancia;
int sensor;
void setup(){

  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  
  
  Serial.begin(9600);
  Serie2.begin(115200);   
}
void loop(){
   
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
duracion = pulseIn(eco,HIGH);
 distancia = (duracion/2)/29;
    long duration;
  int cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);
  cm = (duration / 29)/2;
  DHT.read11(DHT11_PIN);
  int temp = DHT.temperature;
Serial.write(cm);
delay(1000);
Serial.write(temp);
delay(1000);
Serial.write(distancia);
delay(1000);
  }
