/***************************************************************
* Nom Fichier: coDe.ino
*
* Programme: Projet dé électronique
*
* Fonctions: - Détection agitation du dé           
*            - Animation avec chiffres aléatoires         
*            - Pause de x sec sur un chiffre aléatoire      
*
* Dernière MàJ: 13/02/18 - Eih3Prog
*
****************************************************************
* HelioxLab, Projet dé électronique - http://bit.ly/helioxdice
***************************************************************/

/***************************************************************
* VARIABLES & CONSTANTES
***************************************************************/
#define pinLED1 0 //LED1 sur la broche N°5
#define pinLED2 1 //LED2 sur la broche N°6
#define pinLED3 2 //LED3 sur la broche N°7
#define pinLED4 3 //LED4 sur la broche N°2

#define pinSENSOR 4 //Capteur sur la broche N°3

#define delayNUMBER 7 //Temps d'affichage du chiffre en seconde

byte animNUMBER = 0; //Chiffre du dé pendant l'animation
byte finalNUMBER = 0; //Chiffre final affiché sur le dé
byte lastNUMBER = 0; //Dernier chiffre obtenu

/***************************************************************
* CONFIGURATION DES BROCHES
***************************************************************/
void setup() {
	pinMode(pinLED1, OUTPUT); // ]
	pinMode(pinLED2, OUTPUT); //  | Les broches sont définies
	pinMode(pinLED3, OUTPUT); //  | en tant que sorties
	pinMode(pinLED4, OUTPUT); // ]

	pinMode(pinSENSOR, INPUT); //Broche définie en entrée

	randomSeed(analogRead(0)); //Initialisation du mode aléatoire 
}

/***************************************************************
* FONCTION PRINCIPALE
***************************************************************/
void loop() {
	while (readSensor(pinSENSOR) != 1){};

	animateDice();

	finalDice();
}

/***************************************************************
* FONCTION DETECTION AGITATION
***************************************************************/
int readSensor(byte pin) {
	if (digitalRead(pin) == LOW) return 1;
}

/***************************************************************
* FONCTION ANIMATION LANCER 
***************************************************************/
void animateDice() {
	for (byte i=0; i<8; i++) {
		animNUMBER = random(1, 7);

		while (animNUMBER == lastNUMBER) { 
			animNUMBER = random(1, 7);
		}

		lastNUMBER = animNUMBER;

		numberDice(animNUMBER);

		delay(200);

		numberDice(0);

		delay(50);
	}
}

/***************************************************************
* FONCTION AFFICHAGE CHIFFRES
***************************************************************/
void numberDice(byte num) {
	switch (num) {

	case 1:
		digitalWrite(pinLED4, HIGH);
		break;
	case 2:
		digitalWrite(pinLED1, HIGH);
		break;
	case 3:
		digitalWrite(pinLED3, HIGH);
		digitalWrite(pinLED4, HIGH);
		break;
	case 4:
		digitalWrite(pinLED1, HIGH);
		digitalWrite(pinLED3, HIGH);
		break;
	case 5:
		digitalWrite(pinLED1, HIGH);
		digitalWrite(pinLED3, HIGH);
		digitalWrite(pinLED4, HIGH);
		break;
	case 6:
		digitalWrite(pinLED1, HIGH);
		digitalWrite(pinLED2, HIGH);
		digitalWrite(pinLED3, HIGH);
		break;
	default:
		digitalWrite(pinLED1, LOW);
		digitalWrite(pinLED2, LOW);
		digitalWrite(pinLED3, LOW);
		digitalWrite(pinLED4, LOW);
		break;
	}
}

/***************************************************************
* FONCTION AFFICHAGE CHIFFRE FINAL
***************************************************************/
void finalDice() {
	finalNUMBER = random(1, 7);

	numberDice(finalNUMBER);

	delay(delayNUMBER * 1000);

	numberDice(0);
}

/***************************************************************
* DOCUMENTATIONS & INFOS
***************************************************************/
// https://wiki.mchobby.be/images/4/44/Arduino-ATTiny-85-brancher-22.png
// http://www.farnell.com/datasheets/1698186.pdf