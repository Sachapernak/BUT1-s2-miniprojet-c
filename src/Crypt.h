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
*  Nom du fichier : Crypt.h                                                   *
*                                                                             *
******************************************************************************/
#include "Lecture.h"
#include <stdio.h>

// Constantes
#define ALPHABET_SIZE 62 //La taille de l'alphabet: 10 chiffres + 26 maj + 26 minuscules
#define NB_START '0'     // les chiffres commencent a '0'
#define NB_END '9'       // Les chiffres finissent a '9'
#define MAJ_START 'A'    // Les majuscules commencent a 'A'
#define MAJ_END 'Z'      // Les majuscules finissent a 'Z'
#define MIN_START 'a'    // Les minuscules commences a 'a'
#define MIN_END 'z'      // Les minuscules finissent a 'z'

//Declarations de fonctions
void cesarCrypt(int size, int key, char* text);
void cesarDecrypt(int size, int key, char* text);
void cesarCharCrypt(int key, char* ch);

/**
 * Chiffre le texte donné en utilisant la technique de chiffrement de César.
 * Chiffre uniquement l'alphanumérique.
 * 
 * @param size La taille du tableau de texte.
 * @param key La clé de chiffrement.
 * @param text Un pointeur vers le tableau de texte à chiffrer.
 * 
 * @return rien.
 */
void cesarCrypt(int size, int key, char* text) {
	for (int i = 0; i < size-1; i++) {
		cesarCharCrypt(key, &text[i]);
	}

}

void cesarDecrypt(int size, int key, char* text){
	key = ALPHABET_SIZE - key;
	cesarCrypt(size, key, text);
}

/**
 * Chiffre un caractère donné en utilisant la technique de chiffrement de César.
 * Chiffre uniquement l'alphanumérique
 * 
 * @param key La clé de chiffrement.
 * @param ch Un pointeur vers le caractère à chiffrer. Le caractère sera modifié pour contenir le caractère chiffré.
 * 
 * @return Aucune.
 */
void cesarCharCrypt(int key, char* ch){
	/* 
     * Pour éviter les problèmes de dépassement de valeurs, le caractère doit être converti en un entier.
     * Les valeurs de type 'char' deviennent négatives si elles dépassent 127, donc on les traite comme des entiers.
     */
	int c = *ch;
    /*
     * La difficulté ici est que l'alphanumérique n'est pas continu dans la table ASCII :
     * - La plage des chiffres '0' à '9' s'étend de 48 à 57.
     * - La plage des lettres majuscules 'A' à 'Z' s'étend de 65 à 90.
     * - La plage des lettres minuscules 'a' à 'z' s'étend de 97 à 122.
     * Nous ne pouvons donc pas simplement utiliser le modulo, car nous risquerions de transformer un caractère 
     * alphanumérique en un caractère non-alphanumérique !
     */
	//La clé de chiffrement ne dépasse pas 62.
	int keyMod = key % ALPHABET_SIZE; // 62 char : 10 (0-9) + 26 (A-Z) + 26 (a-Z)
	
    // Gestion des chiffres
	if (c >= NB_START && c <= NB_END){
		c = c+keyMod;
		// Si le caractère chiffré est un chiffre, on le laisse tel quel
		if (c <= NB_END) {
			*ch = c;
        /* Si le caractère chiffré dépasse '9', nous devons le déplacer dans la plage des lettres majuscules
         * en calculant la différence entre le caractère et '9', puis en avançant dans la plage des lettres majuscules.
         */
		} else if (c-NB_END + MAJ_START-1 <= MAJ_END) {
			*ch = c-NB_END + MAJ_START-1;
        /* Si le caractère dépasse la plage des chiffres et des lettres majuscules,
         * nous le déplaçons dans la plage des lettres minuscules en calculant la différence,
         * puis en avançant dans la plage des lettres minuscules.
         */
		} else if ( c-NB_END + MAJ_START-2 -MAJ_END+MIN_START <= MIN_END){
			*ch = c-NB_END + MAJ_START-MAJ_END + MIN_START - 2;
		} else {
 		/* Si le caractère dépasse les trois plages, il retourne à sa plage d'origine en tenant compte de la clé de chiffrement. */
			*ch = (c - keyMod) - (ALPHABET_SIZE - keyMod);
		}

    // Gestion des lettres majuscules
	} else if (c >= MAJ_START && c <= MAJ_END){
		c = c+keyMod;
		if (c >= MAJ_START && c <= MAJ_END){
			*ch = c;
        /* Si le caractère chiffré dépasse la plage des lettres majuscules,
         * nous le déplaçons dans la plage des lettres minuscules.
         */
		} else if (c-MAJ_END + MIN_START-1 >= MIN_START && c-MAJ_END + MIN_START-1 <= MIN_END) {
			*ch = c-MAJ_END + MIN_START-1;

		} else if (  (c-MAJ_END + MIN_START-2 - MIN_END+NB_START) <= NB_END){
			*ch = c-MAJ_END + MIN_START-2 - MIN_END+NB_START;
		} else {
			*ch = (c-keyMod) - (ALPHABET_SIZE - keyMod);
		}

    // Gestion des lettres minuscules
	} else if (c >= MIN_START && c <= MIN_END) {
		c = c+keyMod;
		if (c >=MIN_START && c<=MIN_END){
			*ch = c;
		} else if (c-MIN_END + NB_START-1 <= NB_END) {
			*ch = c-MIN_END + NB_START-1;
		} else if (c-MIN_END + NB_START-2 - NB_END+MAJ_START <= MAJ_END) {
			*ch = c-MIN_END + NB_START-2 - NB_END+MAJ_START;
		} else {
			*ch = (c-keyMod) - (ALPHABET_SIZE - keyMod);
		}
	}

}
