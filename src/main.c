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

/** @file main.c 
 * 	Contiens la fonction main.
 * */ 

#include "FonctionMenu.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Inclut seulement si on est sur windows
#ifdef _WIN32
#include <Windows.h>
#endif

//Constantes
//Permet de changer les couleurs dans la console
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Declarations de fonctions

void enableColor();


/**
 * Fonction principale du programme. Permet d'utiliser les fonctionnalités de chiffrement
 * et de déchiffrement en ligne de commande ou via une interaction avec l'utilisateur.
 * 
 * @param argc Le nombre d'arguments passés à la ligne de commande
 * @param argv Un tableau de pointeurs vers les arguments passés à la ligne de commande
 */
void main(int argc, char *argv[]) {

	//active la couleur dans la console windows
	enableColor();

	char eotxt = '/'; // valeur par défaut
	char * path = "./ResultatChiffrement.txt";
	int enr = 1;

	// Si il n'y a pas d'arguments en ligne de commande
	if (argc == 1){
		printf("\nBienvenue dans ce programme de chiffrement.\n");
		printf("\nPar defaut, le caractere de fin de saisie est '/'."
			ANSI_COLOR_MAGENTA"\n>Veuillez entrer '/' a la fin de votre saisie puis appuyer sur la touche entree.\n\n"ANSI_COLOR_RESET);
		menuKB(&eotxt, path, &enr);
	} else {
		entreeCmd(argc,argv);
	}
}


/**
 * Active la coloration du texte dans la console.
 * Cette fonction est destinée à être utilisée sur Windows afin de permettre
 * l'affichage des couleurs dans la console de la même manière que sur Linux.
 * 
 * Note : Ce code est activé uniquement si le programme est exécuté sur Windows.
 */
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