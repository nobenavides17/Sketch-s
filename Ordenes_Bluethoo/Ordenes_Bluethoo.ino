#include<SoftwareSerial.h>
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
SoftwareSerial BT(4,6); //10 RX, 11 TX.
char orden[255]; //Creamos un array de caracteres de 256 posiciones
int i=0; //Tamaño actual del array
 
void setup()
{
//Inicia el bluethoot
  BT.begin(9600);
//Inicia la comunicacion serial
  Serial.begin(9600);
}
 
void loop()
{
  //Cuando haya datos disponibles
  if(BT.available())
  {
    char dato=BT.read(); //Guarda los datos carácter a carácter en la variable "dato"
 
    orden[i++]=dato; //Vamos colocando cada carácter recibido en el array "orden"
 
    //Cuando reciba una nueva línea (al pulsar enter en la app) entra en la función
    if(dato=='\n')
    {
      Serial.println(orden); //Visualizamos el comando recibido en el Monitor Serial
      
      BT.write("\r"); //Enviamos un retorno de carro de la app. La app ya crea una línea nueva
      clean(); //Ejecutamos la función clean() para limpiar el array
    }
  }
}
 
//Limpia el array
void clean()
{
  for (int cl=0; cl<=i; cl++)
  {
    orden[cl]=0;
  }
  i=0;
}
