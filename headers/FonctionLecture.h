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
*  Nom du fichier : FonctionLecture.h                                         *
*                                                                             *
******************************************************************************/

/** @file FonctionLecture.h
 *	Contiens les fonctions de lecture d'entrées.
 **/ 

#ifndef FONCTIONLECTURE_H
#define FONCTIONLECTURE_H


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
char* getText(int* sSize, char eotxt, int* exitCode);

/**
 * Cette fonction permet de récuperer du texte uniquement alpahnumerique, ignore la
 * ponctuation, les espaces, etc.
 * 
 * @param sSize Pointeur d'entier qui enregistre la taille du texte entrée (inclut '\0')
 * @param eotxt Caractère de fin de saisie
 * @return Pointeur vers un string alloué dynamiquement qui contient le texte saisie.
 * 		   Attention : le pointeur doit etre free() après utilisation !
 */
char* getOnlyText(int* sSize, char eotxt);

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
char* getTextFic(int* sSize, char* path, int* exitCode);


/**
 * Fonction pour vider le buffer d'entrée
 */
void clearBuffer();


#endif