void setup()
{
//Declaracion de los pin en modo de salida para los led
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
}
void loop()
{
//Enciende y apaga los led en intervalos de 100 milisegundos en orden ascendente
for (int i=4; i<9; i++)
  {
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    delay(100);
  }
//Enciende y apaga los led en orden descendente en intervalos de 100 milisecs
for (int i=8; i>3; i--)
  {
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    delay(100);
  }
}
