#include <SoftwareSerial.h>
//Define el objeto de la clase software serioal para el BT
SoftwareSerial BT(4,6); //10 RX, 11 TX.
//Pines para los motores
int motor1_1 = 13;
int motor1_2 = 12;
int motor2_1 = 9;
int motor2_2 = 8;
//Pines de potencia de los motores
int enable = 1;
//Variable que sirve como switch de encendido y apagado
int high = 0;
//Variable que recibira la orden del BT
int orden ;

void setup()
{
//Inicia la transferencia del BT
  BT.begin(9600);
  pinMode(motor1_1, OUTPUT);
  pinMode(motor1_2, OUTPUT);
  pinMode(motor2_1, OUTPUT);
  pinMode(motor2_2, OUTPUT);
  pinMode(enable, OUTPUT);
//Inicia la comunicacion serial
  Serial.begin(9600);
}
void loop()
{
//Si hay datos disponibles
  if(BT.available())
  {
    //Orden recibira lo que envia el BT
    orden = BT.read();
    //Imprime la orden
    Serial.println(orden);
//Si esta activado switch de encendido
  if(high==1)
  {
//Verificamos que orden se envio segun el numero de caracter ascii 
  switch(orden)
  {
//Case 1 o 49 en ascii apaga los motores
    case 49:
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);
    break;
//Case 2 (50 en ascii) enciende los motores hacia adelante
    case 50:
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH);
    break;
//Case 3 hacia atras
    case 51:
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,HIGH);
    digitalWrite(motor2_1,HIGH);
    digitalWrite(motor2_2,LOW);  
    break;
//Case 4 hacia la derecha por 400 milisegundos, luego se detiene
    case 52:
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);  
    delay(400);
    digitalWrite(motor1_1,LOW);
    break;
//Case 5 Izquierda
    case 53:
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH); 
    delay(400);
    digitalWrite(motor2_2,LOW);
    break;
  }
}
//Si el caracter enviado es 0
//Si esta encendido, lo apaga y viceversa
if (orden == 48)
{
  high = !high;
}
 }
}
