int giessen = 10;
long interval = 7200;
int Wasser = 6;
int Erde = 5;
int ErdeS = 4;
int Motor = 7;
int actPin = 13; // Aktivitäts LED

void setup() {
pinMode(actPin,OUTPUT);
pinMode(Wasser,INPUT);
pinMode(Erde,INPUT);
pinMode(ErdeS,OUTPUT);
pinMode(Motor,OUTPUT);
digitalWrite(ErdeS,LOW);
digitalWrite(Motor,LOW);
giessen = giessen*1000;
digitalWrite(ErdeS,LOW);digitalWrite(Motor,HIGH);delay(giessen);digitalWrite(Motor,LOW);
}

void loop() {
  for (long i=0; i<interval; i=i+1){digitalWrite(actPin,HIGH);delay(1000);digitalWrite(actPin,LOW);} 

    digitalWrite(ErdeS,HIGH);
    delay(30);
    if (digitalRead(Erde) == 1 ){digitalWrite(ErdeS,LOW);digitalWrite(Motor,HIGH);delay(giessen);digitalWrite(Motor,LOW);}
    digitalWrite(ErdeS,LOW);
}
