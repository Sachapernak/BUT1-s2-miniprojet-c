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
*  Nom du fichier : FonctionLecture.c                                         *
*                                                                             *
******************************************************************************/

#include "FonctionLecture.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**
 * Cette fonction permet de récuperer du texte ASCII tapé au clavier tant que le
 * caratère de fin de saisie n'est pas encontré. Ce dernier n'est pas inclut dans
 * le texte. 
 * 
 * @param sSize Pointeur d'entier qui enregistre la taille du texte entrée (inclut '\0')
 * @param eotxt Caractère de fin de saisie
 * @param exitCode Pointeur d'entier qui enregistre le code de sortie indiquant si une
 * 		           erreure a été encontré (0 si aucune erreure)
 * 				   Liste des erreures :
 * 		           	1 si le programme encontre un caractère non ASCII.
 * 					2 si il y a echec de l'allocation mémoire
 * @return Pointeur vers un string alloué dynamiquement qui contient le texte saisie.
 * 		   Attention : le pointeur doit etre free() après utilisation !
 */
char* getText(int* sSize, char eotxt, int* exitCode) {
	*exitCode = 0; //met le code d'erreur a 0 par défaut

	char c;
	char* txt;
	int size = 1; //La taille du string alloué dynamiquement

	txt = (char*) malloc(size * sizeof(char)); //aloue une taille de 1 au string
	txt[0] = '\0'; //met par défaut le caractère de fin de string

	do {
		c = getchar(); //on récup le char

		if (c != eotxt) { //verifie si le char n'est pas la fin de saisie

			if ( (c & 128) == 0 ){ //masque binaire, verifie si le char est ASCII
				
				//Augmentation de la taille du string de 1
				size++;
				txt = (char*)realloc(txt, size * sizeof(char));

				if (txt == NULL) {
                        // L'allocation mémoire a raté
                        *exitCode = 2; // Code d'erreur 2 pour allocation mémoire raté
                        return NULL;
                }

				txt[size-2] = c; // on insère le nouveau char
				txt[size-1] = '\0'; //on deplace la fin de string
			
			} else {
				/*Si le char n'est pas ascii, on met le code d'erreur a 1
				  Le char n'est pas ajouté */
				*exitCode = 1;
			}
		}
	} while (c != eotxt);

	*sSize = size;
	clearBuffer();
	return txt;
}


/**
 * Cette fonction permet de récuperer du texte uniquement alpahnumerique, ignore la
 * ponctuation, les espaces, etc.
 * 
 * @param sSize Pointeur d'entier qui enregistre la taille du texte entrée (inclut '\0')
 * @param eotxt Caractère de fin de saisie
 * @return Pointeur vers un string alloué dynamiquement qui contient le texte saisie.
 * 		   Attention : le pointeur doit etre free() après utilisation !
 */
char* getOnlyText(int* sSize, char eotxt) {
	char c;
	char* txt;
	int size = 1; //La taille du string alloué dynamiquement
	
	txt = (char*) malloc(size * sizeof(char)); //aloue une taille de 1 au string
	txt[0] = '\0'; //met par défaut le caractère de fin de string
	
	do {
		c = getchar(); //on récup le char

		if (c != eotxt) { //verifie si le char n'est pas la fin de saisie

			if ( (c >= '0' && c <= '9') || ( c >='A' && c <= 'Z') || (c >='a' && c <='z') ){ 

				size++;
				//Augmentation de la taille du string de 1
				txt = (char*)realloc(txt, size * sizeof(char));
				txt[size-2] = c; // on insère le nouveau char
				txt[size-1] = '\0'; //on deplace la fin de string
			}
		}
	} while (c != eotxt);

	*sSize = size;
	clearBuffer();
	return txt;
}


/**
 * Cette fonction permet de récuperer du texte ASCII tapé au clavier tant que le
 * caratère de fin de saisie n'est pas encontré. Ce dernier n'est pas inclut dans
 * le texte. 
 * 
 * @param sSize Pointeur d'entier qui enregistre la taille du texte entrée (inclut '\0')
 * @param eotxt Caractère de fin de saisie
 * @param exitCode Pointeur d'entier qui enregistre le code de sortie indiquant si une
 * 		           erreure a été encontré (0 si aucune erreure)
 * 				   Liste des erreures :
 * 		           	1 si le programme encontre un caractère non ASCII.
 * 					2 si il y a echec de l'allocation mémoire
 * 					3 si il y a echec de l'ouverture du fichier
 * @return Pointeur vers un string alloué dynamiquement qui contient le texte saisie.
 * 		   Attention : le pointeur doit etre free() après utilisation !
 */
char* getTextFic(int* sSize, char* path, int* exitCode) {

	*exitCode = 0; //met le code d'erreur a 0 par défaut
	char c;
	char* txt;
	int size = 1; //La taille du string alloué dynamiquement

	txt = (char*) malloc(size * sizeof(char)); //aloue une taille de 1 au string
	txt[0] = '\0'; //met par défaut le caractère de fin de string
	
	FILE* fic;
	fic = fopen(path, "r");

	if (fic == NULL){
		*exitCode = 3; //erreur a 3 si le fichier ne s'est pas ouvert
		return NULL;
	} else {
		//le fichier s'est ouvert avec succès
		do {
			c = fgetc(fic); //on récup le char
			if (c != EOF) { //verifie si le char n'est pas la fin du fic

				if ( (c & 128) == 0 ){ //masque binaire, verifie si le char est ASCII
					
					//Augmentation de la taille du string de 1
					size++;		
					txt = (char*)realloc(txt, size * sizeof(char));
					if (txt == NULL) {
                        // L'allocation mémoire a raté
                        fclose(fic);
                        *exitCode = 2; // Code d'erreur 2 pour allocation mémoire raté
                        return NULL;
                    }

					txt[size-2] = c; // on insère le nouveau char
					txt[size-1] = '\0'; //on deplace la fin de string

				} else {
					/*Si le char n'est pas ascii, on met le code d'erreur a 1
					  Le char n'est pas ajouté */
					*exitCode = 1; //
				}
			}
		} while (c != EOF);
	}

	fclose(fic);
	*sSize = size;
	return txt;
}

int writeText(char * path, char* text){
	FILE* fic;
	fic = fopen(path, "a");
	if (fic == NULL){
		return 3;
	}
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
	fprintf(fic,"////////////// Date de chiffrement: %d-%02d-%02d %02d:%02d:%02d\n\n%s\n\n\n",
			tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, text);
	fclose(fic);
	return 0;
}


/**
 * Fonction pour vider le buffer d'entrée
 */
void clearBuffer() {
	char c = getchar();
	//On récupère les bits tant qu'on n'arrive pas au char de fin de ligne
	while ('\n' != c) {
		c = getchar();
	}
}
