#include <Servo.h>

Servo s1,s2,s3,s4,s5,s6; 
int ipos1,ipos2,ipos3,ipos4,ipos5,ipos6;
int pos=0,ipos=0,data;
void setup() {
  pinMode(10,OUTPUT);
  s1.attach(2);//claw
  s2.attach(3);//plam
  s3.attach(4);//ankle
  s4.attach(5);//elbow
  s5.attach(6);//shoulder
  s6.attach(7);//base
  Serial.begin(9600);
}
void location(){
  //go to the object location and prepare to pick
      for(pos=90;pos>=0;pos--)
     {
      s6.write(pos);
      delay(5);
     }
     delay(1000);
     for(pos=90;pos>=40;pos--)
     {
      s5.write(pos);
      delay(10);
     }
     delay(1000);
     for(pos=90;pos<=110;pos++)
     { 
      s4.write(pos);
      delay(10);
     }
     delay(1000);
     for(pos=90;pos<=180;pos++)
     {
      s1.write(pos);
      delay(10);
     }
     delay(1000);
     for(pos=90;pos>=40;pos--)
     {
      s2.write(pos);
      delay(10);
     }
     delay(1000);
  }
void taking(){
  //take object from its location
     for(pos=180;pos>=0;pos--)
     {
      s1.write(pos);
      delay(10);
     }
     delay(1000);
     for(pos=40;pos<=100;pos++)
     {
      s2.write(pos);
      delay(10);
     }
     delay(1000);
     for(pos=110;pos>=90;pos--)
     {
      s4.write(pos);
      delay(10);
     }
     for(pos=40;pos<=90;pos++)
     {
      s5.write(pos);
      delay(10);
     }  
  }
 void initial(){
    //to go to initial position which is 90 degree(IDEAL position for all 180 degree servos)

    for(ipos=ipos2;ipos<=130;ipos++)
    {
      s2.write(ipos);
      delay(10);
    }
    for(ipos=ipos1;ipos>=90;ipos--)
     {
      s1.write(ipos);
      delay(10);
    }
    delay(1000);
    //for the s4 because it's final position may be less than 90 or greater than 90 according to the color
    if(data=='A' || data=='S')
    {
      for(ipos=ipos4;ipos>=90;ipos--)
     {
      s4.write(ipos);
      delay(10);
     }
    delay(1000);
    }
    else if(data=='D' || data=='F')
    {
     for(ipos=ipos4;ipos<=90;ipos++)
     {
      s4.write(ipos);
      delay(10);
     }
     delay(1000);
    }
    // from here all are same as other servos
    for(ipos=ipos5;ipos<=90;ipos++)
     {
      s5.write(ipos);
      delay(10);
    }
    delay(1000);
    for(ipos=ipos6;ipos>=90;ipos--)
     {
      s6.write(ipos);
      delay(5);
    }
    delay(1000);
    for(ipos=ipos2;ipos<=90;ipos++)
     {
      s2.write(ipos);
      delay(10);
    }
 }


void loop() {
 if (Serial.available()>0)  
  { 
    data=Serial.read(); 
    delay(1000);
    location();
    taking();
   if(data='A')
   {
    //to place object(Small red) to their respective places
     for(pos=0;pos<=150;pos++)
     {
      s6.write(pos);
      delay(5);
      ipos6=pos;
     }
     for(pos=90;pos<=110;pos++)
     {
      s4.write(pos);
      delay(10);
      ipos4=pos;
     }
     delay(1000);
     for(pos=90;pos>=30;pos--)
     { 
      s5.write(pos);
      delay(10);
      ipos5=pos;
     }
     delay(1000);
     for(pos=100;pos>=70;pos--)
     {
      s2.write(pos);
      delay(10);
      ipos2=pos;
     }
     delay(1000);
     for(pos=0;pos<=180;pos++)
     {
      s1.write(pos);
      delay(10);
      ipos1=pos;
     }
     delay(1000);
   }
   else if(data=='S')
    {
      //to place object(Big red) to their respective places
      for(pos=0;pos<=180;pos++)
     {
      s6.write(pos);
      delay(5);
      ipos6=pos;
     }
     for(pos=90;pos>=40;pos--)
     { 
      s5.write(pos);
      delay(10);
      ipos5=pos;
     }
     delay(1000);
     for(pos=90;pos<=110;pos++)
     {
      s4.write(pos);
      delay(10);
      ipos4=pos;
     }
     delay(1000);
     for(pos=100;pos>=70;pos--)
     {
      s2.write(pos);
      delay(10);
      ipos2=pos;
     }
     delay(1000);
     for(pos=0;pos<=180;pos++)
     {
      s1.write(pos);
      delay(10);
      ipos1=pos;
     }
    }
  
  else if(data=='D')
    {
      //to place object(Small blue) to their respective places
      for(pos=0;pos<=150;pos++)
     {
      s6.write(pos);
      delay(5);
      ipos6=pos;
     }
     for(pos=90;pos>=70;pos--)
     {
      s4.write(pos);
      delay(10);
      ipos4=pos;
     }
     delay(1000);
     for(pos=90;pos>=30;pos--)
     { 
      s5.write(pos);
      delay(10);
      ipos5=pos;
     }
     delay(1000);
     for(pos=100;pos>=40;pos--)
     {
      s2.write(pos);
      delay(10);
      ipos2=pos;
     }
     delay(1000);
     for(pos=0;pos<=180;pos++)
     {
      s1.write(pos);
      delay(10);
      ipos1=pos;
     }
    }
   else if(data=='F')
    {
      //to place object(Big blue) to their respective places
      for(pos=0;pos<=150;pos++)
     {
      s6.write(pos);
      delay(5);
      ipos6=pos;
     }
     for(pos=90;pos>=40;pos--)
     { 
      s5.write(pos);
      delay(10);
      ipos5=pos;
     }
     delay(1000);
     for(pos=90;pos<=130;pos++)
     {
      s4.write(pos);
      delay(10);
      ipos4=pos;
     }
     delay(1000);
     for(pos=100;pos>=40;pos--)
     {
      s2.write(pos);
      delay(10);
      ipos2=pos;
     }
     delay(1000);
     for(pos=0;pos<=180;pos++)
     {
      s1.write(pos);
      delay(10);
      ipos1=pos;
     }
    }
 initial();
}
}
