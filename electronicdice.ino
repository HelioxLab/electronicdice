// ----- DECLARATION DES VARIABLES ------

// Pour les LED
int pinLeds1 = 0; 
int pinLeds2 = 1;
int pinLeds3 = 2;
int pinLed4 = 3; 

// on indique la pin du capteur d'inclinaison
int buttonPin = 4; 
// On vérifie l'état du capteur d'inclinaison
int buttonState;
// Variable pour le random de l'animation 
long ranim;
// Variable pour le random du résultat final
long ran;
// Il n'y a pas encore eu de lancement de dé
int last = 0;
// Temps que le dé reste affiché 1000 ms = 1 seconde
int time = 7000; 


// ----- DECLARATION ENTREES ET SORTIES ------
void setup ()
{
  //On indique que les LED sont des sorties
  pinMode (pinLeds1, OUTPUT);
  pinMode (pinLeds2, OUTPUT);
  pinMode (pinLeds3, OUTPUT);
  pinMode (pinLed4, OUTPUT);
  // On indique que le detecteur d'inclinaison est une entrée.
  pinMode (buttonPin, INPUT);

  randomSeed(analogRead(0)); // on initialise le fait de pouvoir lancer des randoms
}

// ----- ACTIONS A EFFECTUER ------
void loop()
{	
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW){ // Si on bouge le dé
    
   for (int i=0; i <= 7; i++){ // Animation pour 8 affichages de dé avec 200 ms entre chaque
     
  ranim = random(1, 7); // on effectue un random pour chaque affichage
  
  while (ranim == last){ // On verifie que deux affichages consécutifs ne sont pas les mêmes 
    ranim = random(1, 7); // Sinon on random un autre chiffre
  }
  last = ranim; // On stock le chiffre pour éviter d'afficher les 2 mêmes valeurs de dé pendant l'animation
    if (ranim == 1){
      digitalWrite (pinLed4, HIGH);
    }
    if (ranim == 2){
      digitalWrite (pinLeds1, HIGH);
    }
    if (ranim == 3){
      digitalWrite (pinLeds3, HIGH);
      digitalWrite (pinLed4, HIGH);
    }
    if (ranim == 4){
      digitalWrite (pinLeds1, HIGH);
      digitalWrite (pinLeds3, HIGH);
    }
    if (ranim == 5){
      digitalWrite (pinLeds1, HIGH);
      digitalWrite (pinLeds3, HIGH);
      digitalWrite (pinLed4, HIGH);
   }
   if (ranim == 6){
      digitalWrite (pinLeds1, HIGH);
      digitalWrite (pinLeds2, HIGH);
      digitalWrite (pinLeds3, HIGH);
   }
      delay(200); // Pause entre l'affichage de l'animation : 200ms led éteintes
    digitalWrite (pinLeds1, LOW);
    digitalWrite (pinLeds2, LOW);
    digitalWrite (pinLeds3, LOW);
    digitalWrite (pinLed4, LOW);
      delay(50);
   } 
    
    
// RANDOM DU RESULTAT FINAL
    ran = random(1, 7); 
    if (ran == 1){
      digitalWrite (pinLed4, HIGH);
      delay (time); // time étant la variable qui vaut 7000ms donc affichage du résultat pendant 7 secondes
    }
    if (ran == 2){
      digitalWrite (pinLeds1, HIGH);
      delay (time);
    }
    if (ran == 3){
      digitalWrite (pinLeds3, HIGH);
      digitalWrite (pinLed4, HIGH);
      delay (time);
    }
    if (ran == 4){
      digitalWrite (pinLeds1, HIGH);
      digitalWrite (pinLeds3, HIGH);
      delay (time);
    }
    if (ran == 5){
      digitalWrite (pinLeds1, HIGH);
      digitalWrite (pinLeds3, HIGH);
      digitalWrite (pinLed4, HIGH);
      delay (time);
   }
   if (ran == 6){
      digitalWrite (pinLeds1, HIGH);
      digitalWrite (pinLeds2, HIGH);
      digitalWrite (pinLeds3, HIGH);
      delay (time);
   }
  }
  // On éteint tout pour pouvoir relancer le dé
  digitalWrite (pinLeds1, LOW);
  digitalWrite (pinLeds2, LOW);
  digitalWrite (pinLeds3, LOW);
  digitalWrite (pinLed4, LOW);
}
