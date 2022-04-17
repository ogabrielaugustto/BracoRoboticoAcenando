#include <Servo.h>

#define PIR 9

Servo servoBase; 
Servo servoDireita;
Servo servoEsquerda;
Servo servoGarra;

int pos = 0;

void setup() 
  {
  pinMode(PIR, INPUT);
  Serial.begin(9600);
  Serial.println("PROGRAMA INICIADO");
  servoBase.attach(13); 
  servoDireita.attach(12); 
  servoEsquerda.attach(11); 
  servoGarra.attach(10);    
}

void loop() 
{
  bool valorPIR = digitalRead(PIR);
  
  if (valorPIR) {
    
    Serial.println("Obstáculo Detectado");
    servoDireita.write(90);
    servoEsquerda.write(180);
    servoGarra.write(80); //80 fechado e 180 aberto
    for (int vezes=0; vezes<2;vezes ++)
    {
      for(pos = 80; pos <= 180; pos += 1)
      {
        servoBase.write(pos);
        delay(7);
      }
      
        for(pos = 45; pos <= 135; pos += 1)
      {
        servoGarra.write(pos);
        delay(7);
      }
        delay(100);
      
        for(pos = 135; pos>=45; pos -=1)
      {
        servoBase.write(pos);
        delay(7);
      }
      
        for(pos = 180; pos>=80; pos -=1)
      {
        servoGarra.write(pos);
        delay(7);
      }
      delay(100);
    }
  }
}
