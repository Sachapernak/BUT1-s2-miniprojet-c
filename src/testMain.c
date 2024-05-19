#include "FonctionMenu.h"
#include "FonctionLecture.h"
#include "FonctionChiffrement.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	printf("ok\n");
	char* path = "./testFic";
	// Les pointeurs DOIVENT etre initialisé
	// On ne peut pas mettre int* sSize ou int* exitCode !
	int sSize;
	int exitCode;
	printf("ok\n");
	char* text = getTextFic(&sSize,path,&exitCode);
	printf("%s\n", text);
	cesarCrypt(sSize,20, text);
	writeText("./TestResult", text);

}