/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Chiffrement de messages                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 :   Oliver DA SILVA                                            *
*                                                                             *
*  Nom-prénom2 :   Sacha PERNAK                                               *
*                                                                             *
*  Nom-prénom3 :                                                              *
*                                                                             *
*  Nom-prénom4 :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/
#include "Crypt.h"
#include <stdio.h>
#include <string.h>

//Ajoute seulement si on est sur windows
#ifdef _WIN32
#include <Windows.h>
#endif

// Permet de changer les couleurs dans la console
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void menuKB(char* eotxt);
void cryptDecrypt(int type, char * eotxt);
void enableColor();

void main(int argc, char *argv[])
{
	enableColor();

	char eotxt = '/';
	if (argc == 1){
		printf("Bienvenue dans ce programme de chiffrement.\n");
		printf("\nPar defaut, le caractere de fin de saisie est '/'."
			ANSI_COLOR_MAGENTA"\n>Veuillez entrer '/' a la fin de votre saisie puis appuyer sur la touche entree.\n\n"ANSI_COLOR_RESET);
		menuKB(&eotxt);

	}


	// int arg;

	// int exit;

	// int keySize;
	// printf("Veuillez entrer le text \n>");
	// char* text = getText(&size, eotxt, &exit);

	// printf("Veuillez entrez la clé \n>");
	// char* key = getOnlyText(&keySize, eotxt);

	// printf("\nText d'origine : %s\n",text);
	// vigenereCrypt(text,size,key,keySize-1);
	// printf("\nTexte crypte : %s\n",text);
	// vigenereDecrypt(text,size,key,keySize-1);
	// printf("\nTexte decrypte : %s\n",text);


}

void enableColor() {
//Ce code est mis seulement si on est sur windows	
#ifdef _WIN32
    // Permet de mettre la console en couleur sur windows (comme sur linux)
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        GetConsoleMode(hOut, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
#endif
}

void menuKB(char* eotxt){
		char c;
		
		printf("Veuillez choisir l'action a réaliser (mode saisie clavier):"
			"\n\n -- Cesar --"
			"\n 1) chiffrer"
			"\n 2) dechiffrer"
			"\n\n -- Vigenere --"
			"\n 3) chiffrer" 
			"\n 4) dechiffrer"
			"\n\n -- Utilitaire --"
			"\n 5) Menu des fichiers texte"
			"\n 6) Choisir marqueur de fin d'entree (actuel : ");
		
		if (*eotxt == '\n'){
			printf("'Entree' * 2)");
		} else {
			printf("'%c')", *eotxt);
		
		}
		printf("\n\n 0) Quitter"
			"\n\n>");


		printf(ANSI_COLOR_CYAN);
		c = getchar();
		printf(ANSI_COLOR_RESET);
		clearBuffer();

		switch (c)
		{
		case '1':
			cryptDecrypt(0, eotxt);
			menuKB(eotxt);
			break;

		case '2':
			cryptDecrypt(1, eotxt);
			menuKB(eotxt);
			break;

		case '3':
			cryptDecrypt(2, eotxt);
			menuKB(eotxt);
			break;
		case '4':
			cryptDecrypt(3, eotxt);
			menuKB(eotxt);
			break;

		case '5':

			break;
		case '6':
			break;
		case '0':
			break;
		default:
			printf("\n\n [Entree non reconnue. Veuillez reessayer.]\n\n");
			menuKB(eotxt);
		}
}

void cryptDecrypt(int type, char * eotxt){
	// Type <= 1 : Cesar
	// Type >= 2 : vigenere
	// Type % 2 = 0 : chiffrer
	// Type % 2 = 1 : dechiffrer

	char * input;
	char * endPtr;

	char * keyChar;
	int keySize;

	int keyC;

 	char c;
	int exit;
	int size;
	printf("Veuillez entrer la cle de chiffrement (%s)\n>",(type <= 1) ? "entier positif" : "Alphanumerique");

	printf(ANSI_COLOR_CYAN);
	keyChar = getOnlyText(&keySize, *eotxt);
	printf(ANSI_COLOR_RESET);
	if (type <= 1){
		keyC = (int) strtol(keyChar, &endPtr, 10);
		while (endPtr == keyChar || keyC < 0){
			printf(ANSI_COLOR_MAGENTA"[Attention] Valeur incorrecte, veuillez reessayer (entier positif uniquement)\n"ANSI_COLOR_RESET">");
			free(keyChar);
			printf(ANSI_COLOR_CYAN);
			keyChar = getOnlyText(&keySize, *eotxt);
			printf(ANSI_COLOR_RESET);
			keyC = (int) strtol(keyChar, &endPtr, 10);
		}
		free(keyChar);	
	}
	
	if (type <= 1 ){
		printf("\nCle choisie : "ANSI_COLOR_YELLOW"%d"ANSI_COLOR_RESET"\n\n", keyC);
	} else {
		printf("\nCle choisie : "ANSI_COLOR_YELLOW"%s"ANSI_COLOR_RESET"\n\n", keyChar);
	}
	

	printf("Veuillez entrer le texte a %s:\n>", (type%2 == 0) ? "chiffrer" : "dechiffrer");
	printf(ANSI_COLOR_CYAN);
	input = getText(&size, *eotxt, &exit);
	printf(ANSI_COLOR_RESET);

	if (exit != 0){
		printf(ANSI_COLOR_MAGENTA"\n[Attention] Ce texte comporte des caractères non-ascii qui ne seront pas inclut."
			   "\nContinuer ? (o/n)>"ANSI_COLOR_RESET);
		printf(ANSI_COLOR_CYAN);
		c = getchar();
		printf(ANSI_COLOR_RESET);
		if (!(c == 'n' || c == 'N')) {

			printf("\nVotre texte %s: \n%s%s"ANSI_COLOR_RESET"\n\n",(type%2 == 0) ? "" : "chiffre",
																	(type%2 == 0) ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
																	input);
			switch(type){
			case 0:
				cesarCrypt(size, keyC,input);
				break;
			case 1:
				cesarDecrypt(size, keyC,input);
				break;
			case 2:
				vigenereCrypt(input,size,keyChar,keySize-1);
				break;
			case 3:
				vigenereDecrypt(input,size,keyChar,keySize-1);
				break;
			}


			printf("\nVotre texte %s: \n%s%s"ANSI_COLOR_RESET"\n\n",(type%2 == 0) ? "chiffre" : "dechiffre",
																	(type%2 == 0) ? ANSI_COLOR_RED : ANSI_COLOR_GREEN,
																	input);

			printf(ANSI_COLOR_MAGENTA"\n<touche Entree pour continuer>"ANSI_COLOR_RESET);
			getchar();
			clearBuffer();

		}
	} else {
			printf("\nVotre texte %s: \n%s%s"ANSI_COLOR_RESET"\n\n",(type%2 == 0) ? "" : "chiffre",
																	(type%2 == 0) ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
																	input);
			switch(type){
			case 0:
				cesarCrypt(size, keyC,input);
				break;
			case 1:
				cesarDecrypt(size, keyC,input);
				break;
			case 2:
				vigenereCrypt(input,size,keyChar,keySize-1);
				break;
			case 3:
				vigenereDecrypt(input,size,keyChar,keySize-1);
				break;
			}


			printf("\nVotre texte %s: \n%s%s"ANSI_COLOR_RESET"\n\n",(type%2 == 0) ? "chiffre" : "dechiffre",
																	(type%2 == 0) ? ANSI_COLOR_RED : ANSI_COLOR_GREEN,
																	input);

			printf(ANSI_COLOR_MAGENTA"\n<touche Entree pour continuer>"ANSI_COLOR_RESET);
			getchar();
			clearBuffer();

	}
	free(input);

}