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
*  Nom du fichier : Lecture.h                                                 *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declarations des fonctions
char* getText(int* sSize, char eotxt, int* exitCode);
void clearBuffer();

/**
 * Cette fonction permet de récuperer du texte ASCII tapé au clavier tant que
 * caratère de fin de saisie n'est pas encontré. Ce dernier n'est pas inclut dans
 * le texte. 
 * 
 * @param sSize Pointeur d'entier qui enregistre la taille du texte entrée (inclut '\0')
 * @param eotxt Caractère de fin de saisie
 * @param exitCode Pointeur d'entier qui enregistre le code de sortie indiquant si une
 * 		           erreure a été encontré (0 : succès, 1 : erreur). 
 * 		           Renvoie 1 si le programme encontre un caractère non ASCII.
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
				size++;
				//Augmentation de la taille du string de 1
				txt = (char*)realloc(txt, size * sizeof(char));
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
 * Fonction pour vider le buffer d'entrée
 */
void clearBuffer() {
	char c = getchar();
	//On récupère les bits tant qu'on n'arrive pas au char de fin de ligne
	while ('\n' != c) {
		c = getchar();
	}
}


