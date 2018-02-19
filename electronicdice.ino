// ----- DECLARATION DES VARIABLES ------

#define LED_1_PIN 0
#define LED_2_PIN 1
#define LED_3_PIN 2
#define LED_4_PIN 3
#define BUTTON_PIN 4

#define LED_1_MASK 0b1000
#define LED_2_MASK 0b0100
#define LED_3_MASK 0b0010
#define LED_4_MASK 0b0001

#define TIME_TO_SHOW 7000

static char   numbers[7] = {  0b0000,     // 0
                              0b0001,     //
                              0b1000,
                              0b0011,
                              0b1010,
                              0b1011,
                              0b1110  };  // 6

void setup ()
{
  pinMode (LED_1_PIN, OUTPUT);
  pinMode (LED_2_PIN, OUTPUT);
  pinMode (LED_3_PIN, OUTPUT);
  pinMode (LED_4_PIN, OUTPUT);
  pinMode (BUTTON_PIN, INPUT);

  randomSeed(analogRead(0)); // on initialise le fait de pouvoir lancer des randoms
}

void loop()
{	
  bool buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) // Si on bouge le dé
  {
    int last = 0;
    for (int i=0; i <= 7; i++) // Animation pour 8 affichages de dé avec 200 ms entre chaque
    {
      int ranim = random(1, 7); // on effectue un random pour chaque affichage
    
      while (ranim == last) // On verifie que deux affichages consécutifs ne sont pas les mêmes 
        ranim = random(1, 7); // Sinon on random un autre chiffre

      last = ranim; // On stock le chiffre pour éviter d'afficher les 2 mêmes valeurs de dé pendant l'animation
      show(ranim);
      delay(200); // Pause entre l'affichage de l'animation : 200ms led éteintes
      show(0);
      delay(50);
   } 
    
    show(random(1, 7));
    delay(TIME_TO_SHOW);
  }

  show(0);
}

void  show(int number)
{
  char flags = numbers[number];
  
  pinMode(pinLeds1, flags & LED_1_MASK ? HIGH : LOW);
  pinMode(pinLeds2, flags & LED_2_MASK ? HIGH : LOW);
  pinMode(pinLeds3, flags & LED_3_MASK ? HIGH : LOW);
  pinMode(pinLeds4, flags & LED_4_MASK ? HIGH : LOW);
}

