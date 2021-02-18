#include <Servo.h>

Servo s1,s2,s3,s4,s5; 
int pos = 0,data;
void setup() {
  pinMode(10,OUTPUT);
  s1.attach(3);
  s2.attach(4);
  s3.attach(5);
  s4.attach(6);
 s5.attach(7);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0)  
  { 
    data=Serial.read();      
    if(data=='1')
    {
      s1.write(0);
      s2.write(0);
      s3.write(0);
      s4.write(0);
      s5.write(0);
     delay(5000);
      s1.write(180);
      s2.write(180);
      s3.write(180);
      s4.write(180);
      s5.write(180);
    }

    else if(data=='2')
    {
      for(pos=0;pos<=100;pos++)
      {
        s1.write(pos);
        s2.write(pos);
        delay(10); 
      }
    }
   else if(data=='3')
    {
      for(pos=0;pos<=80;pos++)
      {
        s1.write(pos);
        s2.write(pos);
        delay(10);
      }
    }
   else if(data=='4')
    {
      for(pos=0;pos<=50;pos++)
      {
        s1.write(pos);
        s2.write(pos);
        delay(10);
      }
    }
    else
    {
      digitalWrite(10,HIGH);
      delay(1000);
      digitalWrite(10,LOW);
    }

  }
}
