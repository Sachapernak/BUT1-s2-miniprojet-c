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
*  Nom du fichier : FonctionChiffrement.h                                     *
*                                                                             *
******************************************************************************/

/** @file FonctionChiffrement.h 
 * 	Contiens les fonctions de chiffrement / dechiffrement	
 * */ 


#ifndef FONCTIONCHIFFREMENT_H
#define FONCTIONCHIFFREMENT_H

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
void cesarCrypt(int size, int key, char* text);


/**
 * Dechiffre le texte donné en utilisant la technique de chiffrement de César.
 * Dechiffre uniquement l'alphanumérique.
 * 
 * @param size La taille du tableau de texte.
 * @param key La clé de chiffrement.
 * @param text Un pointeur vers le tableau de texte à dechiffrer.
 * 
 * @return rien.
 */
void cesarDecrypt(int size, int key, char* text);


/**
 * Chiffre un caractère donné en utilisant la technique de chiffrement de César.
 * Chiffre uniquement l'alphanumérique
 * 
 * @param key La clé de chiffrement.
 * @param ch Un pointeur vers le caractère à chiffrer. Le caractère sera modifié pour contenir le caractère chiffré.
 * 
 * @return Aucune.
 */
void cesarCharCrypt(int key, char* ch);


/**
 * Chiffre le texte donné en utilisant la technique de chiffrement de Vigenere.
 * Chiffre uniquement l'alphanumérique.
 * 
 * @param text Un pointeur vers le tableau de texte à chiffrer.
 * @param size La taille du tableau de texte.
 * @param key La clé de chiffrement.
 * @param keySize La taille de la cle. Mettre keysize-1 si le texte contient '\0' a la fin
 * 
 * @return rien.
 */
void vigenereCrypt(char* text, int size, char* key, int keySize);

/**
 * Dechiffre le texte donné en utilisant la technique de chiffrement de Vigenere.
 * Dechiffre uniquement l'alphanumérique.
 * 
 * @param text Un pointeur vers le tableau de texte à chiffrer.
 * @param size La taille du tableau de texte.
 * @param key La clé de chiffrement.
 * @param keySize La taille de la cle
 * 
 * @return rien.
 */
void vigenereDecrypt(char* text, int size, char* key, int keySize);


/**
 * Transforme la cle texte en un tableau d'entier.
 * 
 * La table de chiffrement est la suivante :
 * 
 * 00 01 02 03 04 05 06 07 08 09
 * 0  1  2  3  4  5  6  7  8  9
 *
 * 10 11 12 13 14 15 15 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
 * A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z 
 *
 * 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61
 * a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
 * 
 * @param keySize La taille de la cle.
 * @param key la clé texte.
 * 
 * @return La clé sous form de tableau d'entier
 */
int* vignereIntKey(int keySize, char* key);

#endif