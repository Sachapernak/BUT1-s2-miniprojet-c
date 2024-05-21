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
*  Nom du fichier : FonctionMenu.h                                            *
*                                                                             *
******************************************************************************/

/** @file FonctionMenu.h 
 * 	Contiens les en-tetes de fonction des menus
 * */

#ifndef FONCTIONMENU_H
#define FONCTIONMENU_H

/**
 * Affiche le menu et permet à l'utilisateur de choisir une action en utilisant le clavier.
 * Cette fonction propose différentes options pour effectuer des opérations de chiffrement et de déchiffrement
 * en mode César ou Vigenère, ainsi que des fonctionnalités supplémentaires comme la modification du marqueur de fin de saisie.
 * Une fois une action choisie, elle appelle la fonction appropriée pour effectuer l'opération correspondante.
 * Après l'exécution de l'action choisie, le menu est réaffiché pour permettre à l'utilisateur de choisir une autre action.
 * 
 * @param eotxt Le marqueur de fin de saisie utilisé pour la saisie clavier.
 *              Lorsque l'utilisateur appuie sur ce marqueur, la saisie est terminée.
 * @param path Le chemin ou nom du fichier qui enregistre le resultat des opérations
 * @param enr Si le resultat des operations doit etre enregistrer ou nom (1 is oui, 0 si non.)
 */
void menuKB(char* eotxt, char* path, int* enr);


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
void chiffrementKB(int type, char * eotxt, int* enr, char* path);


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
int getOperationType(char *operation);


/**
 * Gère l'entrée des commandes et des données depuis la ligne de commande ou l'utilisateur
 * pour effectuer des opérations de chiffrement et de déchiffrement.
 * 
 * @param argc Le nombre d'arguments passés à la ligne de commande
 * @param argv Un tableau de pointeurs vers les arguments passés à la ligne de commande
 */
void entreeCmd(int argc, char *argv[]);


/**
 * Vérifie si une chaîne de caractères est entièrement composée de caractères alphanumériques.
 * 
 * @param str La chaîne de caractères à vérifier
 * @return 1 si tous les caractères de la chaîne sont alphanumériques, sinon 0
 */
int is_alnum(const char * str);


/**
 * Vérifie si une chaîne de caractères est entièrement composée de caractères ASCII.
 * 
 * @param str La chaîne de caractères à vérifier
 * @return 1 si tous les caractères de la chaîne sont ASCII, sinon 0
 */
int is_ascii(const char *str);

#endif