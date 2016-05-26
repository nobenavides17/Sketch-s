#include <IRremote.h>
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;
int motor1_1 = 13;
int motor1_2 = 12;
int motor2_1 = 9;
int motor2_2 = 8;
void setup()
{
  pinMode(motor1_1, OUTPUT);
  pinMode(motor1_2, OUTPUT);
  pinMode(motor2_1, OUTPUT);
  pinMode(motor2_2, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop()
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value );
    irrecv.resume(); // Receive the next value
  }
  switch(results.value)
  {
    case 2640445695:
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);
    break;
    case 2640478335:
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH);
    break;
    case 2640462015:
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,HIGH);
    digitalWrite(motor2_1,HIGH);
    digitalWrite(motor2_2,LOW);  
    break;
    case 2640494655:
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);  
    break;
    case 2640453855:
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH); 
    break;
  }
}
