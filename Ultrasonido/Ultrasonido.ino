long distancia; 
long tiempo;
int led = 4;
int OUT = 9;
int IN = 8;
void setup(){
  Serial.begin(9600);
  pinMode(OUT, OUTPUT); //activacion del pin para el pulso ultrasónico (salida)
  pinMode(IN, INPUT); //activacion del pin para el tiempo del rebote del ultrasonido (entrada)
  pinMode(led, OUTPUT);//activacion del pin para encender el led
}

void loop(){
  digitalWrite(9,LOW); //Resetea el sensor
  delayMicroseconds(5);//Pausa de 5 microsegundos 
  digitalWrite(9, HIGH); //Envio del pulso
  delayMicroseconds(10);//Pausa de 10 microsegundos
  tiempo=pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: "desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante" */
  distancia= int(0.017*tiempo); //fórmula para calcular la distancia obteniendo un valor entero
  if(distancia <=3) //Verificamos si esta a menos de 3 centimetros de distancia
  {
    digitalWrite(led, HIGH); //Enciende el led
  }
  else //Si esta a mas de 3 centimetros
  {
    digitalWrite(led, LOW);//Apaga la led
  }

  Serial.print("Distancia  ");//Se imprime la longitud del rebote en centimetros
  Serial.print(distancia);
  Serial.println(" cm");
  delay(1000);//Pausa de 1 segundo para volver a generar el rebote
}
