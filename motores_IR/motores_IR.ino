#include <IRremote.h>
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;
<<<<<<< HEAD
int motor1_1 = 6;
int motor1_2 = 8;
int motor2_1 = 10;
int motor2_2 = 12;
int enable1 = A0;
int enable2 =A1;
=======
int motor1_1 = 13;
int motor1_2 = 12;
int motor2_1 = 9;
int motor2_2 = 8;
>>>>>>> 90f99e653c74701256f8b2afec2582b8af4fef35
void setup()

{
  pinMode(motor1_1, OUTPUT);
  pinMode(motor1_2, OUTPUT);
  pinMode(motor2_1, OUTPUT);
  pinMode(motor2_2, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop()
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value );
    irrecv.resume(); // Receive the next value
  }
  switch(results.value)//escoge la orden a seguir
  {
    case 2640445695://motores quietos
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);
    break;
<<<<<<< HEAD
    case 1:
    analogWrite(enable1, 190);
    analogWrite(enable2, 190);
=======
    case 2640478335://primer motor hacia adelante y segundo hacia atras
>>>>>>> 90f99e653c74701256f8b2afec2582b8af4fef35
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH);
    break;
<<<<<<< HEAD
    case 2:
    analogWrite(enable1, 190);
    analogWrite(enable2, 190);
=======
    case 2640462015://segundo motor hacia adelante y primero hacia atras
>>>>>>> 90f99e653c74701256f8b2afec2582b8af4fef35
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,HIGH);
    digitalWrite(motor2_1,HIGH);
    digitalWrite(motor2_2,LOW);  
    break;
<<<<<<< HEAD
    case 3:
    analogWrite(enable1, 80);
=======
    case 2640494655://primer motor hacia adelante y segundo quieto (giro hacia la derecha)
>>>>>>> 90f99e653c74701256f8b2afec2582b8af4fef35
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);  
    break;
<<<<<<< HEAD
    case 4:
    analogWrite(enable2, 80);
=======
    case 2640453855://primer motor quieto y segundo hacia atras (giro hacia la derecha)
>>>>>>> 90f99e653c74701256f8b2afec2582b8af4fef35
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH); 
    break;
  }
}
