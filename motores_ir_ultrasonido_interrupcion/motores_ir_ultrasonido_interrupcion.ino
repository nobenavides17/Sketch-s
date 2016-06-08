#include <IRremote.h> //Libreria para poder hacer uso de el IR
int RECV_PIN = 2; //Pin que se utiliza para la interrupcion
IRrecv irrecv(RECV_PIN);
decode_results results;
//Pines utilizados para los motores
volatile int motor1_1 = 13;
volatile int motor1_2 = 12;
volatile int motor2_1 = 7;
volatile int motor2_2 = 6;
//Variables requeridas para la funcion del ultrsonido
long distancia; 
long tiempo;
int OUT = 8;
int IN = 9;
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
  attachInterrupt(0, loope, FALLING);//Convocamos la interrupcion
}
void loop()
{ 
  digitalWrite(OUT,LOW);
  delayMicroseconds(5);//Pausa de 5 segundos
  digitalWrite(OUT, HIGH);
  delayMicroseconds(10); //Pausa de 10 segundos
  tiempo=pulseIn(IN, HIGH);
  distancia= int(0.017*tiempo); //Calculo de distancia en la que se encuentra el objeto detectado
  if(distancia <=10) 
  {
    /*
    Calculamos que si la distancia en menor o igual a 10cm los motores
    se apagaran de lo contrario mientras un objeto este a mayor distancia
    el carrito seguira avanzando
    */
    digitalWrite(motor1_1, LOW);
    digitalWrite(motor1_2, LOW);
    digitalWrite(motor2_1, LOW);
    digitalWrite(motor2_2, LOW);
  }
  Serial.print("Distancia  "); //Imprime la distancia en el monitor serial
  Serial.print(distancia);
  Serial.println(" cm");
  delay(1000);
}
//Funciones generales
void apagar(){ //Funcion de apagar el carrito
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);
}
void adelante(){//Funcion de avanzar
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH);
}

void atras(){//Funcion de retroceder
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,HIGH);
    digitalWrite(motor2_1,HIGH);
    digitalWrite(motor2_2,LOW);
}
void izquierda(){//Funcion de giro a la izquierda
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);
}

void derecha(){//Funcion de giro a la derecha
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH);
}

void loope()//Funcion de la interrupcion
{
  if (irrecv.decode(&results)) {//Verifica el resultado
    Serial.println(results.value );
    irrecv.resume();
  }
    if(results.value == 61809)//LLama a la funcion apagar
    {
      apagar();
    }
    if(results.value == 61737)//LLama a la funcion adelante
    {
      adelante();
    }
    if(results.value == 61865)//LLama a la funcion atras
    {
      atras();  
    }
    if(results.value == 61897)//LLama a la funcion izquierda
    {
      izquierda();
    }  
    if(results.value == 61769)//LLama a la funcion derecha
    {
      derecha();
    }
}
