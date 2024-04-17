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
*  Nom du fichier : Crypt.c                                                   *
*                                                                             *
******************************************************************************/
#include "Lecture.h"
#include <stdio.h>

void cesarCrypt(int size, int key, char* text);

void main(int argc, char *argv[])
{
	int arg;
	int size;
	char eotxt = '/';
	int exit;

	if (argc > 1){
		arg = strtol(argv[1], NULL, 10);
		printf("Cle : %d\n", arg % 62);
		char* text = getText(&size, eotxt, &exit);
		printf("text : %s\n", text);
		cesarCrypt(size, arg, text);
		printf("code : %s\n", text);
	}

	if (argc == 1){
		char test[65] = "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
		char test2[65] = "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
		printf("%s\n\n", test);
		cesarCrypt(65, 1, test);
		printf("%s\n", test);
		for (int i = 1; i < 7; i++){
			cesarCrypt(65, 11, test);
			printf("%s\n", test);
		}
		cesarCrypt(65,61,test2);
		printf("\n%s\n", test2);
	}
}

void cesarCrypt(int size, int key, char* text) {
	/* c Doit etre un int, les char devienne négatif si il dépassent 127,
	or on ajoute au char c la clé par la suite, ce qui peut faire >127
	*/
	int c;
	/*
	La difficulté ici est que l'alphanumerique n'est pas continue
	dans la table ASCII : on a trois "zone" :
	-la zone de '0' a '9', qui s'étend de 48 a 57
	-la zone de 'A' a 'Z', qui s'étend de 65 a 90
	-la zone de 'a' a 'z', qui s'étend de 97 a 122
	On ne peut pas donc simplement utiliser le modulo : on risquerais
	sinon de transformer une char alphanumerique en non-alphanumérique !
	*/
	int keyMod = key % 62; // 62 char : 10 (0-9) + 26 (A-Z) + 26 (a-Z)
	for (int i = 0; i < size-1; i++) {
		c = text[i];
		//gere les chiffre de 0 a 9
		
		// OK
		if (c >= '0' && c <= '9'){
			c = c+keyMod;
			// si le char crypté est entre 0 et 9 : on le laisse tel quel
			if (c <= '9') {
				text[i] = c;
			/* Le char crypté depasse 9 : on regarde d'abord de combien
			il "depasse" de sa zone [c -'9']
			On doit ensuite avancer de cette différence dans la zone suivante
			pour trouver le char crypté. Le doit char crypté doit etre dans la
			nouvelle zone.
			*/
			} else if (c-'9'+'A'-1 <= 'Z') {
				text[i] = c-'9'+'A'-1;
			/* Le char dépasse de la zone précédente :
			on regarde la différence et on avance dans la zone
			suivante
			*/
			} else if ( c - '9'+'A'- 2 -'Z'+'a' <= 'z'){
				text[i] = c-'9'+'A'-'Z'+'a'- 2;
			} else {
			/* Le char dépasse des trois zone. Il re-rentre alors dans
			sa zone d'origine (on en est certains grace au modulo 62)
			*/
				text[i] = (c - keyMod) - (62 - keyMod);
			}

		// OK
		} else if (c >= 'A' && c <= 'Z'){
			c = c+keyMod;
			if (c >= 'A' && c <= 'Z'){
				text[i] = c;
			/* Ces expressions pourraient etre remplacé par c + const;
			cependant, on perdrait en lisbilité du code
			*/
			} else if (c-'Z' + 'a'-1 >= 'a' && c-'Z' + 'a'-1 <= 'z') {
				text[i] = c-'Z'+ 'a'-1;

			} else if (  (c-'Z'+'a'-2-'z'+'0') <= '9'){
				text[i] = c-'Z'+'a'-2-'z'+'0';
			} else {
				text[i] = (c-keyMod) - (62 - keyMod);
			}

		// OK
		} else if (c >= 'a' && c <= 'z') {
			c = c+keyMod;
			if (c >='a' && c<='z'){
				text[i] = c;
			} else if (c-'z'+'0'-1 <= '9') {
				text[i] = c-'z'+'0'-1;
			} else if (c-'z'+'0'-2-'9'+'A' <= 'Z') {
				text[i] = c-'z'+'0'-2-'9'+'A';
			} else {
				text[i] = (c-keyMod) - (62 - keyMod);
			}
		}
	}
}


