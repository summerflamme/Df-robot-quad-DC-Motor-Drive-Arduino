const int E1 = 3; //vitesse moteur avant gauche MOTEUR1
const int E2 = 11;//vitesse moteur avant droit MOTEUR2
const int E3 = 5; //vitesse moteur arrière gauche MOTEUR3
const int E4 = 6; //vitesse moteur arrère droit MOTEUR4

const int M1 = 4; // Direction du MOTEUR1 tourne la roue avant droite vers la droite si "HIGH sinon la laisse droite si "LOW 
const int M3 = 8; // Direction du MOTEUR3 tourne  la roue arrière droite vers la droite si "HIGHT  sinon la laisse droite si "LOW 

const int M2 = 12;// Direction du MOTEUR3 tourne la roue avant gauche vers la gauche si "HIGH" sinon la laisse droite si "LOW 
const int M4 = 7; //Direction du MOTEUR4 tourne la roue arrière gauche vers la gauche si "HIGH"  sinon la laisse droite si "LOW 

int Speed=100; //permet de régler la vitesse 0=arrété et 255= vitesse max
int POT = 0;
int ValPot = 0;

void setup() {
  // met les broches de 3 à 9 en sortie
for(int i=3;i<9;i++)
    pinMode(i,OUTPUT);
    // met les broches de 11 à 13 en sortie
  for(int i=11;i<13;i++)
    pinMode(i,OUTPUT);
    pinMode(POT,INPUT);
   
}

void loop() {
  // Lire la valeur du potentiomètre
  ValPot = analogRead(POT); 
  
  //tourner a droite 
  if (ValPot >512) {
  Speed = map (ValPot , 512 , 1023 ,0 , 255);
 digitalWrite(M1,LOW);
 analogWrite(E1,Speed);
 digitalWrite(M2,HIGH);
 analogWrite(E2,Speed);
 digitalWrite(M3,LOW);
 analogWrite(E3,Speed);
 digitalWrite(M4,HIGH);
 analogWrite(E4,Speed);

  }

 //Tourner a gauche 
 if (ValPot <512)
 {
 Speed = map (ValPot , 512 , 0 , 0 , 255);
 digitalWrite(M1,HIGH);
 analogWrite(E1,Speed);
 digitalWrite(M2,LOW);
 analogWrite(E2,Speed);
 digitalWrite(M3,HIGH);
 analogWrite(E3,Speed);
 digitalWrite(M4,LOW);
 analogWrite(E4,Speed);
 }
}

