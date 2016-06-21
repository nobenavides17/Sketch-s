#include<SoftwareSerial.h>
SoftwareSerial BT(7,6);
int l1 = 13;
int l2 = 12;
int l3 = 11;
int e1 = 1;
int e2 = 1;
int e3 = 1;
int e = 1;
int orden;
void setup()
{
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
}
void loop()
{
  if(BT.available())
  {
   orden = BT.read();
   switch(orden)
   {
     case 48:
             if(e == 1)
             {
               digitalWrite(l1, LOW);
               digitalWrite(l2, LOW);
               digitalWrite(l3, LOW);
               e = !e;
             }
             else
             {
               digitalWrite(l1, HIGH);
               digitalWrite(l2, HIGH);
               digitalWrite(l3, HIGH);
               e = !e;
             }
             break;
      case 49:
            if(e1 == 1)
             {
               digitalWrite(l1, HIGH);
               e1 = !e1;
             }
             else
             {
               digitalWrite(l1,LOW);
               e1 = !e1;
             }
             break; 
      case 50:
            if(e2 == 1)
             {
               digitalWrite(l2, HIGH);
               e2 = !e2;
             }
             else
             {
               digitalWrite(l2,LOW);
               e2 = !e2;
             }
             break;
      case 51:
             if(e3 == 1)
             {
               digitalWrite(l3, HIGH);
               e3 = !e3;
             }
             else
             {
               digitalWrite(l3,LOW);
               e3 = !e3;
             }
             break;         
   }
   Serial.println(orden);   
  }
}
