#include <IRremote.h>

//variables de infrarojo
int RECV_PIN = 4; //pin de infrarrojo
IRrecv irrecv(RECV_PIN);
decode_results results;

//variables de interrupcion
long distancia;//variable para calcular distancia  
long tiempo;//variable que resive la respuesta del ultrasonido
int led = 5;//led que indica la interupcion
int OUT = 12;//pin de salida del ultrasonido
int IN = 11;//pin de entrada del ultrasonido
const byte interruptPin = 2;//pin de la interrupcion del ultrasonido
volatile byte state = HIGH;//variable global
boolean estado =false;//variable para verificar si estan estado autonomo o no

//variables de motores
int motor1_1 = 12;
int motor1_2 = 11;
int motor2_1 = 7;
int motor2_2 = 6;
int enable = 1;

int valor = 10;
int high = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(motor1_1, OUTPUT);
  pinMode(motor1_2, OUTPUT);
  pinMode(motor2_1, OUTPUT);
  pinMode(motor2_2, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(OUT, OUTPUT); //activacion del pin para el pulso ultrasónico (salida)
  pinMode(IN, INPUT); //activacion del pin para el tiempo del rebote del ultrasonido (entrada)
  pinMode(led, OUTPUT);//activacion del pin para encender el led
  pinMode(interruptPin, INPUT);
  attachInterrupt(0, interrupcion, CHANGE);
}
void loop()
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value );
    irrecv.resume(); // Receive the next value
  }
  if(high==1)
  {
  switch(results.value)
  {
    case 61713:
      apagado();
    break;
    
    case 61737:
      adelante();
    break;
    
    case 61865:
      atras();
    break;
    
    case 61769:
      izquierda();
    break;
    
    case 61897:
      derecha();
    break;
    
    case 46654:// autonomo
      estado=!estado;
      autonomo();
    break;

   
   /* case 4251643239:
    if(valor < 250)
    {
      valor+=10;
    }
    analogWrite(enable,valor);
    Serial.println(valor); 
    break;
    case 2090285130:
    if(valor > 10)
    {
      valor-=10;
    }
    analogWrite(enable,valor);
      Serial.println(valor); 
    break;*/
  }
}
if (results.value == 61809)
{
  high = !high;
}
}

void apagado(){
      digitalWrite(motor1_1,LOW);
      digitalWrite(motor1_2,LOW);
      digitalWrite(motor2_1,LOW);
      digitalWrite(motor2_2,LOW);
}
void adelante(){
      digitalWrite(motor1_1,HIGH);
      digitalWrite(motor1_2,LOW);
      digitalWrite(motor2_1,LOW);
      digitalWrite(motor2_2,HIGH);
}
void atras(){
       digitalWrite(motor1_1,LOW);
      digitalWrite(motor1_2,HIGH);
      digitalWrite(motor2_1,HIGH);
      digitalWrite(motor2_2,LOW);    
}
void izquierda(){
      digitalWrite(motor1_1,HIGH);
      digitalWrite(motor1_2,LOW);
      digitalWrite(motor2_1,LOW);
      digitalWrite(motor2_2,LOW);  
      delay(1000);
      digitalWrite(motor1_1,LOW);  
}
void derecha(){

      digitalWrite(motor1_1,LOW);
      digitalWrite(motor1_2,LOW);
      digitalWrite(motor2_1,LOW);
      digitalWrite(motor2_2,HIGH); 
      delay(1000);
      digitalWrite(motor2_2,LOW);
}
void autonomo(){
      while (estado==true){
              digitalWrite(led, state);
              delay(500);  
            }
}


void interrupcion() {

        digitalWrite(9,LOW); //Resetea el sensor
        delayMicroseconds(5);//Pausa de 5 microsegundos 
        digitalWrite(9, HIGH); //Envio del pulso  
        delayMicroseconds(10);//Pausa de 10 microsegundos
        tiempo=pulseIn(8, HIGH); //obtiene el tiempo de retorno del pulzo del Eco
        distancia= int(0.017*tiempo); //fórmula para calcular la distancia obteniendo un valor entero
        
          if(distancia <=10) //Verificamos si esta a menos de 10 centimetros de distancia
          {
            delay(10000);
            digitalWrite(led, LOW);
            state= HIGH;
            atras();
          }
          else{
            digitalWrite(led, HIGH);
            state = LOW;
            adelante();
          }
         delay(1000);//Pausa de 1 segundo para volver a generar el rebote         
     
}
