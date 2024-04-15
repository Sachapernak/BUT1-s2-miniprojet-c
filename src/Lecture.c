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
*  Nom du fichier : Lecture.c                                                 *
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
	*exitCode = 0;
	char c;
	char* txt;
	int size = 1;
	txt = (char*) malloc(size * sizeof(char));
	txt[0] = '\0';
	do {
		c = getchar();
		if (c != eotxt) {
			if ( (c & 128) == 0 ){
				size++;
				txt = (char*)realloc(txt, size * sizeof(char));
				txt[size-2] = c;
				txt[size-1] = '\0';
			} else {
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
	while ('\n' != c) {
		c = getchar();
	}
}


