/*  Skript by SE8DS
 *  Hier ist das Skript, für den auf TikTok gezeigten Blumengießer.
 *  Die Pins könnte ihr belibig anschließen und hier anpassen. Beachtet das das Analoge signal der Sensoren nur auf den analogen Pins gelesen werden kann.
 *  Die Pausenzeit kann leicht abweichen, was an der Ungenauigkeit des Timers im Arduino liegt.
 *  
 */
 
int giesszeit = 1;     // Gießzeit in Sec. (Pumpe an für XX Sekunden)
int pause = 5;         // Pause bis zur nächsten Messung in Sec. (3600 = 1Std.)
int senspowPIN1 = 4;   // Sensor Powerpin 1
int senspowPIN2 = 5;   // Sensor Powerpin 2
int senspowPIN3 = 6;   // Sensor Powerpin 3

int motorPIN1 = 7;     // Motor Signalpin 1
int motorPIN2 = 8;     // Motor Signalpin 2
int motorPIN3 = 9;     // Motor Signalpin 3

int messPIN1 = A3;     // Analoger Messpin 1
int messPIN2 = A2;     // Analoger Messpin 2
int messPIN3 = A1;     // Analoger Messpin 3

int actPin = 13;       // Aktivitäts LED
int beeperPIN = 3;     // Beeperpin

// Je trokener desto höher der Wert

//Topf 1
const int maxi1 = 320; // Feucht
const int mini1 = 400; // Trocken

//Topf 2
const int maxi2 = 320; // Feucht
const int mini2 = 400; // Trocken

//Topf 3
const int maxi3 = 320; // Feucht
const int mini3 = 400; // Trocken

void setup() {
  Serial.begin(9600); // Starte Serielle Verbindung
  pinMode(beeperPIN,OUTPUT);
  pinMode(actPin,OUTPUT);
  //Topf 1
  pinMode(messPIN1,INPUT);
  pinMode(senspowPIN1,OUTPUT);
  pinMode(motorPIN1,OUTPUT);
  digitalWrite(senspowPIN1,LOW);
  digitalWrite(motorPIN1,HIGH);
  //Topf 2
  pinMode(messPIN2,INPUT);
  pinMode(senspowPIN2,OUTPUT);
  pinMode(motorPIN2,OUTPUT);
  digitalWrite(senspowPIN2,LOW);
  digitalWrite(motorPIN2,HIGH);
  //Topf 3
  pinMode(messPIN3,INPUT);
  pinMode(senspowPIN3,OUTPUT);
  pinMode(motorPIN3,OUTPUT);
  digitalWrite(senspowPIN3,LOW);
  digitalWrite(motorPIN3,HIGH);
  giesszeit = giesszeit*1000;
  //pause = pause*1000;
  //Gießen beim Einschalten oder Reset
  
  //Topf1
  digitalWrite(senspowPIN1,LOW);
  digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);
  digitalWrite(motorPIN1,LOW);
  Serial.println("Topf 1 vorlauf...");
  delay(giesszeit);
  Serial.println("Topf 1 vorlauf aus...");
  digitalWrite(motorPIN1,HIGH);
    //Topf2
  digitalWrite(senspowPIN2,LOW);
  digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);delay(50);digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);
  digitalWrite(motorPIN2,LOW);
  Serial.println("Topf 2 vorlauf ...");
  delay(giesszeit);
  Serial.println("Topf 2 vorlauf aus...");
  digitalWrite(motorPIN2,HIGH);
    //Topf3
  digitalWrite(senspowPIN3,LOW);
  digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);delay(50);digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);delay(50);digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);
  digitalWrite(motorPIN3,LOW);
  Serial.println("Topf 3 vorlauf ...");
  delay(giesszeit);
  Serial.println("Topf 3 vorlauf aus...");
  digitalWrite(motorPIN3,HIGH);
}

void loop() {
// Wartezeit bis zur nächsten Messung verplämpern
  for (int i=0; i<pause; i=i+1)
  {
    digitalWrite(actPin,HIGH);
    delay(500);
    digitalWrite(actPin,LOW);
    delay(500);
  } 
// Topf 1 Messen und gegebenenfalls gießen
  digitalWrite(senspowPIN1,HIGH);
  delay(50);
  Serial.println("Wert 1");
  Serial.println(analogRead(messPIN1));
  
  if (analogRead(messPIN1) >= mini1)
  {
    Serial.println("Es wird Topf 1 gegossen...");
    digitalWrite(senspowPIN1,LOW);
    digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);
    digitalWrite(motorPIN1,LOW);
    delay(giesszeit);
    digitalWrite(motorPIN1,HIGH);
  }
  // Topf 2 Messen und gegebenenfalls gießen
  digitalWrite(senspowPIN2,HIGH);
  delay(50);
  Serial.println("Wert 2");
  Serial.println(analogRead(messPIN2));
  
  if (analogRead(messPIN2) >= mini2)
  {
    Serial.println("Es wird Topf 2 gegossen...");
    digitalWrite(senspowPIN2,LOW);
    digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);delay(50);digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);
    digitalWrite(motorPIN2,LOW);
    delay(giesszeit);
    digitalWrite(motorPIN2,HIGH);
  }
  // Topf 3 Messen und gegebenenfalls gießen
  digitalWrite(senspowPIN3,HIGH);
  delay(50);
  Serial.println("Wert 3");
  Serial.println(analogRead(messPIN3));
  
  if (analogRead(messPIN3) >= mini3)
  {
    Serial.println("Es wird Topf 3 gegossen...");
    digitalWrite(senspowPIN3,LOW);
    digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);delay(50);digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);delay(50);digitalWrite(beeperPIN,HIGH);delay(25);digitalWrite(beeperPIN,LOW);
    digitalWrite(motorPIN3,LOW);
    delay(giesszeit);
    digitalWrite(motorPIN3,HIGH);
  }
  
  digitalWrite(senspowPIN1,LOW);
  digitalWrite(senspowPIN2,LOW);
  digitalWrite(senspowPIN3,LOW);
}
