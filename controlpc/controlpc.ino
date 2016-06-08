#include <SoftwareSerial.h>
//Objeto de la clase software seria para el Bluethoot
SoftwareSerial BT(4,6); //10 RX, 11 TX.
//Variable que recibe la orden del BT 
int orden ;

void setup()
{
  //Inicia la transferencia del BT a 9600 
  BT.begin(9600);
  //Inicia el monitor serial
  Serial.begin(9600);
}
void loop()
{
  //Si el BT esta disponible, es decir si esta conectado
  if(BT.available())
  {
    //orden recibira los comandos recibidos del BT
    orden = BT.read();
    //Imprimimos la orden
    Serial.println(orden);
  }
}
