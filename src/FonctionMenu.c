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
*  Nom du fichier : FonctionMenu.c                                            *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "FonctionMenu.h"
#include "FonctionChiffrement.h"
#include "FonctionLecture.h"

//Constantes
//Permet de changer les couleurs dans la console
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


/**
 * Affiche le menu et permet à l'utilisateur de choisir une action en utilisant le clavier.
 * Cette fonction propose différentes options pour effectuer des opérations de chiffrement et de déchiffrement
 * en mode César ou Vigenère, ainsi que des fonctionnalités supplémentaires comme la modification du marqueur de fin de saisie.
 * Une fois une action choisie, elle appelle la fonction appropriée pour effectuer l'opération correspondante.
 * Après l'exécution de l'action choisie, le menu est réaffiché pour permettre à l'utilisateur de choisir une autre action.
 * 
 * @param eotxt Le marqueur de fin de saisie utilisé pour la saisie clavier.
 *              Lorsque l'utilisateur appuie sur ce marqueur, la saisie est terminée.
 */
void menuKB(char* eotxt){
		char c;
		
		//affichage du menu
		printf("Veuillez choisir l'action a realiser (mode saisie clavier):"
			"\n\n -- Cesar --"
			"\n 1) chiffrer"
			"\n 2) dechiffrer"
			"\n\n -- Vigenere --"
			"\n 3) chiffrer" 
			"\n 4) dechiffrer"
			"\n\n -- Utilitaire --"
			"\n 5) Menu des fichiers texte"
			"\n 6) Choisir marqueur de fin d'entree (actuel : ");
		
		//affichage du marqueur de fin de saisie
		if (*eotxt == '\n'){ 
			printf("'Entree' * 2)");
		} else {
			printf("'%c')", *eotxt);
		
		}
		printf("\n\n 0) Quitter"
			"\n\n>");

		// Saisie clavier
		printf(ANSI_COLOR_CYAN);
		c = getchar();
		clearBuffer();
		printf(ANSI_COLOR_RESET);

		// Traitement de l'action choisie
		switch (c)
		{
		case '1': 
			// Chiffrement cesar
			chiffrementKB(0, eotxt);
			menuKB(eotxt);
			break;

		case '2':
			// Dechiffrement cesar
			chiffrementKB(1, eotxt);
			menuKB(eotxt);
			break;

		case '3':
			// Chiffrement vigenere
			chiffrementKB(2, eotxt);
			menuKB(eotxt);
			break;

		case '4':
			// Dechiffrement vigenere
			chiffrementKB(3, eotxt);
			menuKB(eotxt);
			break;

		case '5':
			// Accès au menu des fichiers
			printf("\nEn cours d'implementation...\n");
			break;

		case '6':
			// Changement du marqueur de fin
			printf("Marqueur de fin actuel : ");
			if (*eotxt == '\n'){
				printf("'Entree' * 2)\n");
			} else {
				printf("'%c')\n", *eotxt);
			}

			printf("Veuillez entrer le nouveau marqueur de fin :\n>"ANSI_COLOR_CYAN);
			
			// Recuperation du nouveau marqueur
			*eotxt = getchar();
			clearBuffer();
			printf(ANSI_COLOR_RESET);

			//Affichage du nouveau marqueur
			printf(ANSI_COLOR_MAGENTA"\nNouveau marqueur de fin :");
			if (*eotxt == '\n'){
				printf("'Entree' * 2'\n");
			} else {
				printf("'%c'\n", *eotxt);
			}
			printf("\n"ANSI_COLOR_RESET);
			
			menuKB(eotxt);
			break;

		case '0':
			// Fin du programme
			break;

		default:
			printf("\n\n [Entree non reconnue. Veuillez reessayer.]\n\n");
			menuKB(eotxt);
		}
}


/**
 * Chiffre ou déchiffre un texte en entrée clavier selon le type spécifié.
 * 
 * @param type Type de cryptage/decryptage:
 * 			   0, 1 : Cesar
 * 			   2, 3 : Vigenere
 * 			   chiffre pair : chifrer (0,2)
 * 			   chiffre impair : dechiffrer (1,3)
 * @param eotxt Caractère de fin de saisie.
 * @return rien.
 */
void chiffrementKB(int type, char * eotxt){
	// Type <= 1 : Cesar
	// Type >= 2 : vigenere
	// Type % 2 = 0 : chiffrer
	// Type % 2 = 1 : dechiffrer

	char * input; 		// Pointeur vers le texte saisi par l'utilisateur
	char * endPtr;		// Pointeur utilisé pour la conversion de la clé de chiffrement en entier

	char * keyChar; 	// Pointeur vers la clé de chiffrement en texte alphanumérique
	int keySize;		// Taille de la clé de chiffrement

	int keyC; 			// Clé de chiffrement en int (utilisée si le type est Cesar)

 	char c;				// Caractère utilisé pour les saisies clavier
	int exitCode;		// Code de sortie de la fonction getText
	int size;			// Taille du texte a chiffrer / dechiffrer, saisi par l'utilisateur

	printf("Veuillez entrer la cle de chiffrement (%s)\n"
		   ANSI_COLOR_RED"N'oubliez pas le marqueur de fin de saisie: ",(type <= 1) ? "entier positif" : "Alphanumerique");
	
	//affichage du marqueur de fin de text
	if (*eotxt == '\n'){  
		printf("('Entree' * 2)!\n");
	} else {
		printf("('%c')!\n", *eotxt);
	}
	printf(ANSI_COLOR_RESET"\n>");

	// Récuperation de la clé
	printf(ANSI_COLOR_CYAN);
	keyChar = getOnlyText(&keySize, *eotxt);
	printf(ANSI_COLOR_RESET);

	// Conversion de la clé en entier si nécessaire (pour le chiffrement Cesar)
	if (type <= 1){
		
		keyC = (int) strtol(keyChar, &endPtr, 10);
		// Gestion d'erreur si la clé n'est pas un entier positif
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
	
	// Affichage de la clé choisie
	if (type <= 1 ){
		printf("\nCle choisie : "ANSI_COLOR_YELLOW"%d"ANSI_COLOR_RESET"\n\n", keyC);
	} else {
		printf("\nCle choisie : "ANSI_COLOR_YELLOW"%s"ANSI_COLOR_RESET"\n\n", keyChar);
	}
	
	// Récupération du texte saisi par l'utilisateure
	printf("Veuillez entrer le texte a %s:\n>", (type%2 == 0) ? "chiffrer" : "dechiffrer");
	printf(ANSI_COLOR_CYAN);
	input = getText(&size, *eotxt, &exitCode);
	printf(ANSI_COLOR_RESET);

	// Gestion d'erreurs ou avertissements
	if (exitCode == 2){ // Erreur d'allocation mémoire
		printf(ANSI_COLOR_RED "[Erreur] Erreur de l'allocation mémoire !\nFin du programme\n"
               ANSI_COLOR_RESET);
		exit(2);
	}
	if (exitCode == 1){ // Texte non-ascii
		// On demande a l'utilisateur si il veux continuer
		printf(ANSI_COLOR_MAGENTA"\n[Attention] Ce texte comporte des caractères non-ascii qui ne seront pas inclut."
			   "\nContinuer ? (o/n)>"ANSI_COLOR_RESET);
		printf("\n"ANSI_COLOR_CYAN);
		
		clearBuffer();
		c = getchar();
		printf(ANSI_COLOR_RESET);
		
		if (!(c == 'n' || c == 'N')) {
            // Suite du programme si l'utilisateur décide de continuer malgré les avertissements
            // (le texte non-ascii sera tout de même traité, mais tous les char non-ascii seront ignorées)
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

			printf(ANSI_COLOR_MAGENTA"\n<Entrer une touche pour continuer>\n"ANSI_COLOR_RESET);
			clearBuffer();
			getchar();

		} // else : on ne fait rien.

	// Suite du traitement en fonction du type de cryptage/decryptage choisi si il n'y a pas d'erreur
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

			printf(ANSI_COLOR_MAGENTA"\n<Entrer une touche pour continuer>"ANSI_COLOR_RESET);
			clearBuffer();
			getchar();

	}
	free(input);

}


/**
 * Détermine le type d'opération à effectuer lors de l'utilisation en mode ligne de commande
 * Si l'utilisateur entre "help", affiche un message d'aide.
 * 
 * @param operation Chaîne de caractères représentant l'opération.
 * @return Type d'opération :
 *         0 : chiffrement de César (cc).
 *         1 : déchiffrement de César (cd).
 *         2 : chiffrement de Vigenère (vc).
 *         3 : déchiffrement de Vigenère (vd).
 */
int getOperationType(char *operation) {
	//compare les chaines de texte
    if (strcmp(operation, "cc") == 0) {
        return 0; // 0 pour chiffrement César
    } else if (strcmp(operation, "cd") == 0) {
        return 1; //1 pour dechiffrement César
    } else if (strcmp(operation, "vc") == 0) {
        return 2; //2 pour chiffrement Vigenère
    } else if (strcmp(operation, "vd") == 0) {
        return 3; //3 pour dechiffrement Vigenère
    } else if (strcmp(operation, "help") == 0) { 
    	//Affichage de l'aide si la chaine est "help"
    	printf("\nVoici comment utiliser ce programme:\n\n"

    		   ANSI_COLOR_MAGENTA
    		   "    - Ligne de commande -\n\n"
    		   ANSI_COLOR_RESET

    		   "Linux     : ./main "ANSI_COLOR_CYAN"[operation]"ANSI_COLOR_YELLOW" [cle]"ANSI_COLOR_GREEN" [texte]\n"ANSI_COLOR_RESET
    		   "Windows   : main.exe "ANSI_COLOR_CYAN"[operation]"ANSI_COLOR_YELLOW" [cle]"ANSI_COLOR_GREEN" [texte]\n\n"ANSI_COLOR_RESET

    		   ANSI_COLOR_CYAN
    		   "Operation : cc - chiffrement cesar\n"
    		   "          : cd - dechiffrement cesar\n"
    		   "          : vc - chiffrement vigenere\n"
    		   "          : vd - dechiffrement vigenere\n\n"
    		   ANSI_COLOR_RESET

    		   ANSI_COLOR_YELLOW
    		   "Cle       : nb entier (cesar) /  texte alphanumerique sans espace (vigenere) \n\n"
    		   ANSI_COLOR_RESET

    		   ANSI_COLOR_GREEN
    		   "Texte     : texte ascii\n\n"
    		   ANSI_COLOR_RESET

    		   "\nExemple   : ./main cc JaimeLesChats \"Mon texte ultra secret\"\n\n"

    		   ANSI_COLOR_MAGENTA
    		   "    - Interactif -\n\n"
    		   ANSI_COLOR_RESET

    		   "Linux     : ./main\n"
    		   "Windows   : main.exe\n\n");

    	exit(0); //Fermeture du programme

    } else {
    	//Affichage d'une erreur si aucune opération n'est reconnue.
        printf(ANSI_COLOR_RED "[Erreur] Operation non reconnue. Operations valides:\n"
               ANSI_COLOR_RESET "cc : chiffrement cesar\ncd : dechiffrement cesar\nvc : chiffrement vigenere\nvd : dechiffrement vigenere.\n"
               "./main help (linux) ou main.exe help (windows) pour plus d'aide"
               ANSI_COLOR_RED "\nFin du programme\n" ANSI_COLOR_RESET);
        exit(4); //Fermeture du programme avec l'erreur 4 (commande non reconnue)
    }
}


/**
 * Gère l'entrée des commandes et des données depuis la ligne de commande ou l'utilisateur
 * pour effectuer des opérations de chiffrement et de déchiffrement.
 * 
 * @param argc Le nombre d'arguments passés à la ligne de commande
 * @param argv Un tableau de pointeurs vers les arguments passés à la ligne de commande
 */
void entreeCmd(int argc, char *argv[]) {
    int type; 			// Type d'opération à effectuer

    int keyC;   		// Clé de chiffrement pour le chiffrement de César
    char *keyChar;    	// Clé de chiffrement pour le chiffrement de Vigenère (texte)
    int keySize;  		// Taille de la clé de chiffrement
    
    char *input;      	// Texte à chiffrer ou déchiffrer
    int size;   		// Taille du texte
    
    char *endPtr;   	// Pointeur vers la fin de la chaîne lors de la conversion de la clé en entier
    int exitCode = 0;  	// Code de sortie de l'application

    char eotxt = '/';  	// Caractère de fin de saisie pour le texte

    // verification de l'operation a effectuer
    type = getOperationType(argv[1]);

    // Si aucune clé de chiffrement n'est spécifiée en argument
    if (argc <= 2) {

        printf("Veuillez entrer la cle de chiffrement (%s). Marqueur de fin de saisie: '/'\n>", (type <= 1) ? "entier positif" : "Alphanumerique");
        printf(ANSI_COLOR_CYAN);
        keyChar = getOnlyText(&keySize, eotxt);
        printf(ANSI_COLOR_RESET);

        /// Conversion de la clé en entier si nécessaire pour le chiffrement de César
        if (type <= 1) {
            keyC = (int) strtol(keyChar, &endPtr, 10);
            while (endPtr == keyChar || keyC < 0) {
                printf(ANSI_COLOR_MAGENTA "[Attention] Valeur incorrecte, veuillez reessayer (entier positif uniquement)\n" ANSI_COLOR_RESET ">");
                free(keyChar);
                printf(ANSI_COLOR_CYAN);
                keyChar = getOnlyText(&keySize, eotxt);
                printf(ANSI_COLOR_RESET);
                keyC = (int) strtol(keyChar, &endPtr, 10);
            }
            free(keyChar);
        }

    } else {
 		// Clé de chiffrement spécifiée en argument
        keySize = strlen(argv[2]) + 1;
        keyChar = malloc(keySize * sizeof(char));
        strcpy(keyChar, argv[2]);

        // Vérification de la validité de la clé alphanumérique
        if (!is_alnum(keyChar)) {
            printf(ANSI_COLOR_RED "[Erreur] La cle doit etre alphanumerique, sans espaces. Fin du programme\n" ANSI_COLOR_RESET);
            exit(1);
        }

        // Conversion de la clé en entier si nécessaire pour le chiffrement de César
        if (type <= 1) {
            keyC = (int) strtol(keyChar, &endPtr, 10);
            if (endPtr == keyChar || keyC < 0) {
                printf(ANSI_COLOR_RED "[Erreur] La cle doit etre un entier positif. Fin du programme\n" ANSI_COLOR_RESET);
                exit(1);
            }
        }
    }

    // Affichage de la clé
    if (type <= 1) {
        printf("\nCle choisie : " ANSI_COLOR_YELLOW "%d" ANSI_COLOR_RESET "\n\n", keyC);
    } else {
        printf("\nCle choisie : " ANSI_COLOR_YELLOW "%s" ANSI_COLOR_RESET "\n\n", keyChar);
    }

    // Demande du texte à chiffrer ou déchiffrer si non spécifié en argument
    if (argc <= 3) {
        printf("Veuillez entrer le texte a %s. Marqueur de fin de saisie: '/'\n>", (type % 2 == 0) ? "chiffrer" : "dechiffrer");
        printf(ANSI_COLOR_CYAN);
        input = getText(&size, eotxt, &exitCode);
        printf(ANSI_COLOR_RESET);

        // Echec de l'allocation mémoire
		if (exitCode == 2){
			printf(ANSI_COLOR_RED "[Erreur] Erreur de l'allocation mémoire !\nFin du programme\n"
            	   ANSI_COLOR_RESET);
		exit(2);
		}
    } else {
    	// Texte spécifié en argument
        size = strlen(argv[3]) + 1;
        input = malloc(size * sizeof(char));
        if (input == NULL){
			printf(ANSI_COLOR_RED "[Erreur] Erreur de l'allocation mémoire !\nFin du programme\n"
                   ANSI_COLOR_RESET);
			exit(2);
		}
        strcpy(input, argv[3]);
    }


    // Avertissement en cas de texte non ASCII
    if (!is_ascii(input)) {
        printf(ANSI_COLOR_MAGENTA "\n[Attention] Le texte contient des caracteres non-ascii qui ne seront pas inclus\n" ANSI_COLOR_RESET);
    }

    // Affichage du texte entré
    printf("\nVotre texte %s: \n%s%s" ANSI_COLOR_RESET "\n", (type % 2 == 0) ? "" : "chiffre",
           (type % 2 == 0) ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
           input);

    // Choix de la fonction appropriée selon le type d'opération
    switch (type) {
        case 0:
            cesarCrypt(size, keyC, input);
            break;
        case 1:
            cesarDecrypt(size, keyC, input);
            break;
        case 2:
            vigenereCrypt(input, size, keyChar, keySize - 1);
            break;
        case 3:
            vigenereDecrypt(input, size, keyChar, keySize - 1);
            break;
    }

    // Affichage du texte de sortie
    printf("\nVotre texte %s: \n%s%s" ANSI_COLOR_RESET "\n\n", (type % 2 == 0) ? "chiffre" : "dechiffre",
           (type % 2 == 0) ? ANSI_COLOR_RED : ANSI_COLOR_GREEN,
           input);

    // fin du programme
    free(input);
    exit(0);
}


/**
 * Vérifie si une chaîne de caractères est entièrement composée de caractères alphanumériques.
 * 
 * @param str La chaîne de caractères à vérifier
 * @return 1 si tous les caractères de la chaîne sont alphanumériques, sinon 0
 */
int is_alnum(const char *str) {
    while (*str) {
        if (!isalnum(*str)) {
            return 0; // Renvoie false si un des char n'est pas alphanumérique
        }
        str++;
    }
    return 1; // Return true si tous les char sont alphanumérique
}


/**
 * Vérifie si une chaîne de caractères est entièrement composée de caractères ASCII.
 * 
 * @param str La chaîne de caractères à vérifier
 * @return 1 si tous les caractères de la chaîne sont ASCII, sinon 0
 */
int is_ascii(const char *str) {
    while (*str) {
        if (!isascii(*str)) {
            return 0; // Renvoie false si on a un char non-ascii
        }
        str++;
    }
    return 1; // Return true si tous les char sont ascii
}
