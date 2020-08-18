
void setup() {
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  // put your setup code here, to run once:

}

void loop() {
    if( Serial.read()=='k')
  {
    digitalWrite(12,HIGH);
    delay(1000);
    digitalWrite(12,LOW);
   }
   else  if( Serial.read()=='l')
  {
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(11,LOW);
    
  }
    else if( Serial.read()=='g')
  {
    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    
  }

}
