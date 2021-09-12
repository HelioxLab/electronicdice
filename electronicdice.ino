// ----- INITIALISATION ------
// Defini pin leds
#define PINLEDS1 0
#define PINLEDS2 1
#define PINLEDS3 2
#define PINLEDS4 3
// Defini le pin du capteur d'inclinaison
#define PINBUTTON 4
// Variable pour le random de l'animation 
int randA;
// Il n'y a pas encore eu de lancement de dé
int last = 0;

// ----- DECLARATION ENTREES ET SORTIES ------
void setup(void)
{
	//On indique que les LEDS sont des sorties
	for (int led = 0; led < 4; led++)
		pinMode (led, OUTPUT);
	// On indique que le detecteur d'inclinaison est une entrée.
	pinMode (PINBUTTON, INPUT);
	// on initialise le fait de pouvoir lancer des randoms
	randomSeed(analogRead(0));
}

// ----- ACTIONS A EFFECTUER ------
void loop(void)
{
	// Si on bouge le dé
	if (!digitalRead(PINBUTTON))
	{
		// Animation pour 8 affichages de dé avec 200 ms entre chaque
		for (int i=0; i < 8; i++)
		{
			// on effectue un random pour chaque affichage
			randA = random(1, 7);
			// On verifie que deux affichages consécutifs ne sont pas les mêmes
			while (randA == last)
				randA = random(1, 7); // Sinon on random un autre chiffre
			// On stock le chiffre pour éviter d'afficher les 2 mêmes valeurs de dé pendant l'animation
			last = randA;
			// Appel de la fonction viewLed pour afficher les led
			viewLed(randA);
			// Pause entre l'affichage de l'animation : 200ms led éteintes
			delay(200);
			for (int led = 0; led < 4; led++)
				digitalWrite(led, LOW);
			delay(50);
		} 

		/*
			RANDOM DU RESULTAT FINAL
			Appel de la fonction viewLed pour afficher les led
		*/
		viewLed(random(1, 7));
		// 7000ms donc affichage du résultat pendant 7 secondes
		delay (7000);
	}
	// On éteint tout pour pouvoir relancer le dé
	for (int led = 0; led < 4; led++)
		digitalWrite(led, LOW);
}

// Creation d'une fonction pour eviter la repetition dans le code
void	viewLed(int number)
{
	switch(number)
	{
		case 1:
			digitalWrite(PINLEDS4, HIGH);
			break ;
		case 2:
			digitalWrite(PINLEDS1, HIGH);
			break ;
		case 3:
			digitalWrite(PINLEDS3, HIGH);
			digitalWrite(PINLEDS4, HIGH);
			break ;
		case 4:
			digitalWrite(PINLEDS1, HIGH);
			digitalWrite(PINLEDS3, HIGH);
			break ;
		case 5:
			digitalWrite(PINLEDS1, HIGH);
			digitalWrite(PINLEDS3, HIGH);
			digitalWrite(PINLEDS4, HIGH);
			break ;
		case 6:
			digitalWrite(PINLEDS1, HIGH);
			digitalWrite(PINLEDS2, HIGH);
			digitalWrite(PINLEDS3, HIGH);
			break ;
	}
	return ;
}
