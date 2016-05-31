#include <IRremote.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
volatile int motor1_1 = 13;
volatile int motor1_2 = 12;
volatile int motor2_1 = 9;
volatile int motor2_2 = 8;
long distancia; 
long tiempo;
int OUT = 6;
int IN = 5;
void setup()
{
  pinMode(motor1_1, OUTPUT);
  pinMode(motor1_2, OUTPUT);
  pinMode(motor2_1, OUTPUT);
  pinMode(motor2_2, OUTPUT);
  pinMode(IN, INPUT);
  pinMode(OUT, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  attachInterrupt(0, loope, FALLING);
}
void loop()
{
  digitalWrite(OUT,LOW);
  delayMicroseconds(5);
  digitalWrite(OUT, HIGH);
  delayMicroseconds(10);
  tiempo=pulseIn(IN, HIGH);
  distancia= int(0.017*tiempo); 
  if(distancia <=10) 
  {
    digitalWrite(motor1_1, LOW);
    digitalWrite(motor1_2, LOW);
    digitalWrite(motor2_1, LOW);
    digitalWrite(motor2_2, LOW);
  }
  Serial.print("Distancia  ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(1000);
}
void loope()
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value );
    irrecv.resume();
  }
    if(results.value == 16726215)
    {
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);
    }
    if(results.value == 16718055)
    {
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH);
    }
    if(results.value == 16730805)
    {
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,HIGH);
    digitalWrite(motor2_1,HIGH);
    digitalWrite(motor2_2,LOW);  
    }
    if(results.value == 16716015)
    {
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);
    }  
    if(results.value == 16734885)
    {
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH); 
    }
}
