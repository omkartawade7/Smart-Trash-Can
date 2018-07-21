#include <SoftwareSerial.h>         // including the library for the software serial
                                 
const int trigPin = 8;            // Making the arduino's pin 8 as the trig pin of ultrasonic sensor
const int echoPin = 9;            // Making the arduino's pin 9 as the echo pin of the ultrasonic sensor
// defining two variable for measuring the distance
long duration;
int distance;
char data;
#define TxD 0
#define RxD 1
SoftwareSerial BT(TxD, RxD);

void setup()
{

  pinMode(13,OUTPUT);         // Led to indicate status of trash can
  pinMode(trigPin, OUTPUT);   // Setting the trigPin as Output pin
  pinMode(echoPin, INPUT);    // Setting the echoPin as Input pin
  pinMode(TxD,OUTPUT);
  pinMode(RxD,INPUT);
  BT.begin(9600);
  Serial.begin(9600);
  
}

void loop()
{
digitalWrite(trigPin, LOW);           // Making the trigpin as low
delayMicroseconds(2);                 // delay of 2us
digitalWrite(trigPin, HIGH);          // making the trigpin high for 10us to send the signal 
delayMicroseconds(10);
digitalWrite(trigPin, LOW);   
duration = pulseIn(echoPin, HIGH);    // reading the echopin which will tell us that how much time the signal takes to come back 
distance= duration*0.034/2;           // Calculating the distance and storing in the distance variable
  
 
       if (distance<5)
       {
        Serial.println("Trash can is Full");
        digitalWrite(13,HIGH);
         if(BT.available()>0){
                Serial.print("Trash is Full");
         }
        delay(5000);
          }
        
        else{
         // Serial.println  ("Trash can is Empty");
          digitalWrite(13,LOW);
        }
  

        
}
