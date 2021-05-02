// Code original de HELIOX optimisé par Patrick PIGNOL patrick.pignol@gmail.com

// ----- DECLARATION DES VARIABLES ------

// Pour les LED

#define PINLEDS1 0
#define PINLEDS2 1
#define PINLEDS3 2
#define PINLEDS4 3 

// on indique la pin du capteur d'inclinaison
#define BUTTONPIN 4 

#define SHOWTIME 7000 //"time" est normalement un mot réservé, c'est pour ça qu'il est coloré.
// Nombre minimum de roulades inclus
#define MINROLL 5
// Nombre maximum de roulades exlus
#define MAXROLL 10
// Délais d'animation
#define ANIMATIONDELAY 200
// Délais d'effacement
#define CLEARDELAY 50

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
    digitalWrite (PINLEDS1, LOW);
    digitalWrite (PINLEDS2, LOW);
    digitalWrite (PINLEDS3, LOW);
    digitalWrite (PINLEDS4, LOW);
}

void mShowDice1() // affiche 1
{
    digitalWrite (PINLEDS4, HIGH);
}

void mShowDice2() // affiche 2
{
    digitalWrite (PINLEDS1, HIGH);
}

void mShowDice3() // affiche 3
{
    digitalWrite (PINLEDS3, HIGH);
    digitalWrite (PINLEDS4, HIGH);
}

void mShowDice4() // affiche 4
{
    digitalWrite (PINLEDS1, HIGH);
    digitalWrite (PINLEDS3, HIGH);
}

void mShowDice5() // affiche 5
{
    digitalWrite (PINLEDS1, HIGH);
    digitalWrite (PINLEDS3, HIGH);
    digitalWrite (PINLEDS4, HIGH);
}

void mShowDice6() // affiche 6
{
    digitalWrite (PINLEDS1, HIGH);
    digitalWrite (PINLEDS2, HIGH);
    digitalWrite (PINLEDS3, HIGH);
}

// ----- DECLARATION ENTREES ET SORTIES ------
void setup ()
{    
    //On indique que les LED sont des sorties
    pinMode (PINLEDS1, OUTPUT);
    pinMode (PINLEDS2, OUTPUT);
    pinMode (PINLEDS3, OUTPUT);
    pinMode (PINLEDS4, OUTPUT);
    // On indique que le detecteur d'inclinaison est une entrée.
    pinMode (BUTTONPIN, INPUT);
  
    randomSeed(analogRead(0)); // on initialise le fait de pouvoir lancer des randoms à peu près aléatoires
    mClearDice();//on efface le dé (rien ne garanti que les pines soient à LOW par défaut, tout dépend le compilateur) 
}

// ----- ACTIONS A EFFECTUER ------
void loop()
{
    //Lire l'état du capteur à mercure
    vButtonState = digitalRead(BUTTONPIN);
    // Si on bouge le dé
    if (vButtonState == LOW)
    { 
        vRandomRoll = random(MINROLL, MAXROLL); // le dé roulera aléatoirement entre vMinRoll et vMaxRoll
        for (int vIndex = 0; vIndex <= vRandomRoll; vIndex++) // Animation pour 8 affichages de dé avec 200 ms entre chaque     
        {                     
            mClearDice();//On efface le dé
            delay(CLEARDELAY);//On attend un peu pour que l'utilisateur distingue la transition entre 2 roulades
            // On verifie que deux affichages consécutifs ne sont pas les mêmes sinon on random un autre chiffre
            do // faire
            {
                vRandomAnimation = random(1, 7); // on effectue un random entre 1 inclus et 7 exclus (soit entre 1 et 6 inclus) pour chaque affichage  
            } while (vRandomAnimation == vLastAnimation); //tant que vRandomAnimation == vLastAnimation 
            vLastAnimation = vRandomAnimation; // On stock le chiffre pour éviter d'afficher les 2 mêmes valeurs de dé pendant l'animation
            
            switch(vRandomAnimation) // appliquer le traitement dédié à chaque valeurs de vRandomAnimation
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
            delay(ANIMATIONDELAY); // Pause entre l'affichage de l'animation : 200ms led éteintes   
        } 
        //ici on garde le dernier affichage
        delay (SHOWTIME);
        //Après le délais on efface le dé
        mClearDice();
    }
}
