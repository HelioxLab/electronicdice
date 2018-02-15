// ----- DECLARATION DES VARIABLES ------

// Pour les LED
int pinLeds1 = 0; 
int pinLeds2 = 1;
int pinLeds3 = 2;
int pinLed4 = 3; 

// on indique la pin du capteur d'inclinaison
int buttonPin = 4; 
// On vérifie l'état du capteur d'inclinaison
int buttonState = 0;
// Variable pour le random de l'animation 
long ranim = 0;
// Variable pour le random du résultat final
long ran = 0;
// Il n'y a pas encore eu de lancement de dé
int last = 0;
// Temps que le dé reste affiché 1000 ms = 1 seconde
int time = 7000; 


// FONCTION:

// Permet l'affichage du numéro

void affichageChiffre(int num)
{
    switch (num) {
    case 1:
        digitalWrite (pinLed4, HIGH);
        break;
    case 2:
        digitalWrite (pinLeds1, HIGH);
        break;
    case 3:
        digitalWrite (pinLeds3, HIGH);
        digitalWrite (pinLed4, HIGH);
        break;
    case 4:
        digitalWrite (pinLeds1, HIGH);
        digitalWrite (pinLeds3, HIGH);
        break;
    case 5:
        digitalWrite (pinLeds1, HIGH);
        digitalWrite (pinLeds3, HIGH);
        digitalWrite (pinLed4, HIGH);
        break;
    case 6:
        digitalWrite (pinLeds1, HIGH);
        digitalWrite (pinLeds2, HIGH);
        digitalWrite (pinLeds3, HIGH);
        break;
    default:
        break;
    }
}

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
    if (buttonState == LOW)
    { // Si on bouge le dé
        
        for (int i=0; i <= 7; i++)
        { // Animation pour 8 affichages de dé avec 200 ms entre chaque
            
            ranim = random(1, 7); // on effectue un random pour chaque affichage
            
            while (ranim == last)
            { // On verifie que deux affichages consécutifs ne sont pas les mêmes
                ranim = random(1, 7); // Sinon on random un autre chiffre
            }
            last = ranim; // On stock le chiffre pour éviter d'afficher les 2 mêmes valeurs de dé pendant l'animation
            affichageChiffre(ranim) // Fonction d'affichage des chiffres
            delay(200); // Pause entre l'affichage de l'animation : 200ms led éteintes
            digitalWrite (pinLeds1, LOW);
            digitalWrite (pinLeds2, LOW);
            digitalWrite (pinLeds3, LOW);
            digitalWrite (pinLed4, LOW);
            delay(50);
        }
        
        
        // RANDOM DU RESULTAT FINAL
        ran = random(1, 7);
        affichageChiffre(ran); // Fonction d'affichage des chiffres
    }
    delay (time); // time étant la variable qui vaut 7000ms donc affichage du résultat pendant 7 secondes
    // On éteint tout pour pouvoir relancer le dé
    digitalWrite (pinLeds1, LOW);
    digitalWrite (pinLeds2, LOW);
    digitalWrite (pinLeds3, LOW);
    digitalWrite (pinLed4, LOW);
}

