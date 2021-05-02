// Code original de HELIOX optimisé par Patrick PIGNOL patrick.pignol@gmail.com

// ----- DECLARATION DES VARIABLES ------

// Pour les LED
const int vPinLeds1 = 0; 
const int vPinLeds2 = 1;
const int vPinLeds3 = 2;
const int vPinLed4 = 3; 

// on indique la pin du capteur d'inclinaison
const int vButtonPin = 4; 

const int vTime = 7000; //"time" est normalement un mot réservé, c'est pour ça qu'il est coloré.
// Nombre minimum de roulades inclus
const int vMinRoll = 5;
// Nombre maximum de roulades exlus
const int vMaxRoll = 10;

// On vérifie l'état du capteur d'inclinaison
int vButtonState;
// Variable pour random le nombre de roulades
int vRandomRoll;
// Variable pour le résultat intermédiaire de l'animation 
int vRandomAnimation;
// Il n'y a pas encore eu de lancement de dé
int vLastAnimation = 0;
// Temps que le dé reste affiché 1000 ms = 1 seconde

void mClearDice()// effacement du dé
{
    digitalWrite (vPinLeds1, LOW);
    digitalWrite (vPinLeds2, LOW);
    digitalWrite (vPinLeds3, LOW);
    digitalWrite (vPinLed4, LOW);
}

void mShowDice1() // affiche 1
{
    digitalWrite (vPinLed4, HIGH);
}

void mShowDice2() // affiche 2
{
    digitalWrite (vPinLeds1, HIGH);
}

void mShowDice3() // affiche 3
{
    digitalWrite (vPinLeds3, HIGH);
    digitalWrite (vPinLed4, HIGH);
}

void mShowDice4() // affiche 4
{
    digitalWrite (vPinLeds1, HIGH);
    digitalWrite (vPinLeds3, HIGH);
}

void mShowDice5() // affiche 5
{
    digitalWrite (vPinLeds1, HIGH);
    digitalWrite (vPinLeds3, HIGH);
    digitalWrite (vPinLed4, HIGH);
}

void mShowDice6() // affiche 6
{
    digitalWrite (vPinLeds1, HIGH);
    digitalWrite (vPinLeds2, HIGH);
    digitalWrite (vPinLeds3, HIGH);
}

// ----- DECLARATION ENTREES ET SORTIES ------
void setup ()
{    
    //On indique que les LED sont des sorties
    pinMode (vPinLeds1, OUTPUT);
    pinMode (vPinLeds2, OUTPUT);
    pinMode (vPinLeds3, OUTPUT);
    pinMode (vPinLed4, OUTPUT);
    // On indique que le detecteur d'inclinaison est une entrée.
    pinMode (vButtonPin, INPUT);
  
    randomSeed(analogRead(0)); // on initialise le fait de pouvoir lancer des randoms à peu près aléatoires
    mClearDice();//on efface le dé (rien ne garanti que les pines soient à LOW par défaut, tout dépend le compilateur) 
}

// ----- ACTIONS A EFFECTUER ------
void loop()
{
    //Lire l'état du capteur à mercure
    vButtonState = digitalRead(vButtonPin);
    // Si on bouge le dé
    if (vButtonState == LOW)
    { 
        vRandomRoll = random(vMinRoll, vMaxRoll); // le dé roulera aléatoirement entre vMinRoll et vMaxRoll
        for (int vIndex=0; vIndex <= vRandomRoll; vIndex++) // Animation pour 8 affichages de dé avec 200 ms entre chaque     
        {                     
            mClearDice();//On efface le dé
            delay(50);//On attend un peu pour que l'utilisateur distingue la transition entre 2 roulades
            // On verifie que deux affichages consécutifs ne sont pas les mêmes sinon on random un autre chiffre
            do // faire
            {
                vRandomAnimation = random(1, 7); // on effectue un random entre 1 inclus et 7 exclus (soit entre 1 et 6 inclus) pour chaque affichage  
            } while (vRandomAnimation == vLastAnimation); //tant que vRandomAnimation == vLastAnimation 
            vLastAnimation = vRandomAnimation; // On stock le chiffre pour éviter d'afficher les 2 mêmes valeurs de dé pendant l'animation
            switch(vRandomAnimation)
            {
                case 1: 
                {
                    mShowDice1();
                }break;
                case 2:
                {
                    mShowDice2();
                }break;
                case 3:
                {
                    mShowDice3();
                }break;
                case 4:
                {
                    mShowDice4();
                }break;
                case 5:
                {
                    mShowDice5();
                }break;
                case 6:
                {
                    mShowDice6();
                }break;
            }
            delay(200); // Pause entre l'affichage de l'animation : 200ms led éteintes   
        } 
        //ici on garde le dernier affichage
        delay (vTime);
        //Après le délais on efface le dé
        mClearDice();
    }
}
