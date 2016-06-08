//Define el pin de la led
int led =  13;
int state = 0;
void setup()
{
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available())
  {
//Lee la informacion del puerto serial
    state = Serial.read();
    Serial.println(state);
    switch(state)
    {
      case 'L':
      digitalWrite(led, LOW);
      Serial.println("Led apagada");
      break;
      case 'H':
      digitalWrite(led, HIGH);
      Serial.println("Led Encendida");
      break;
    }
  }
}
