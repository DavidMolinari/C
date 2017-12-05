#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

struct Maillon
{
	int valeur;
	struct Maillon *fg;
	struct Maillon *fd;
};

void afficheOccurence(int * T);
int * histo(char * C);
// void insereApres(int valeur, struct Maillon **ptr);

void main(){
	char * phrase = "Hello World !";
	for (int i = 0; i < strlen(phrase); i++) printf("%c",phrase[i]);

	int * T = (int *) malloc(256*sizeof(int));
	T = histo(phrase);

	afficheOccurence(T);
}

void afficheOccurence(int * T){
	printf("\n");
	for (int i = 0; i < 256; ++i) if(T[i] > 0) printf("le caractère : '%c' est present %d fois\n",i, T[i]);
}

int * histo(char * C){
	// Tableau d'int de 256 valeurs
	int * T = (int *) malloc(256*sizeof(int));
	// On init tout à 0
	for (int i = 0; i < 256; ++i) T[i] = 0;
	for (int i = 0; i < strlen(C); i++)T[C[i]]++;
	return T;
}


/*void insereApres(int valeur, struct Maillon **ptr){
	struct Maillon *new;
	new = (struct Maillon*) malloc(sizeof(struct Maillon));
	new->valeur = valeur;
	if(*ptr == NULL) {
		new->prec = NULL;
		new->suivant = NULL;
		*ptr = new;
	}else if((*ptr)->suivant == NULL){
		new->suivant = NULL;
		new->prec = *ptr;
		(*ptr)->suivant = new;
	}else{
		new->suivant = (*ptr)->suivant;
		(*ptr)->suivant = new;
		new->suivant->prec = new;
		new->prec = *ptr;
	};
};*/