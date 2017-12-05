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

struct node
{
	int code;
	int occurence;
	struct node *suivant;
};

// insert un element dans une liste chainee
void insert(int i, int occ, struct node** tete);
struct Maillon * constructListe(int * T);
void afficheOccurence(int * T);
int * histo(char * C);
void afficheListe(struct node* liste);


void main(){
	char * phrase = "Hello World !";
	for (int i = 0; i < strlen(phrase); i++) printf("%c",phrase[i]);
	int * T = (int *) malloc(256*sizeof(int));
	T = histo(phrase);
	afficheOccurence(T);

	struct node *liste;
	liste = (struct node*) malloc(sizeof(struct node));
	for (int i = 0; i < 256 ; ++i)
		if(T[i] > 0)
			insert(i, T[i], &liste);
	afficheListe(liste);

}

/* Affiche le nombre d'occurence par caractère dans un tableau de char */
void afficheOccurence(int * T){
	printf("\n");
	for (int i = 0; i < 256; ++i) 
		if(T[i] > 0) 
			printf("le caractère : '%c' est present %d fois\n",i, T[i]);
}

/* Calcule l'histogramme d'une chaine de caractères */
int * histo(char * C){
	// Tableau d'int de 256 valeurs
	int * T = (int *) malloc(256*sizeof(int));
	// On init tout à 0
	for (int i = 0; i < 256; ++i) 
		T[i] = 0;
	for (int i = 0; i < strlen(C); i++)
		T[C[i]]++;
	return T;
}

void afficheListe(struct node* liste){
	while(liste != NULL){
		printf("'%c'=> %d fois \n ",liste->code, liste->occurence);
		liste = liste->suivant;
	}
	printf("\n");
}

/* Construit une liste chainée à partir de l'histogramme d'un tableau de char */

// insert un element dans une liste chainee
void insert(int i, int occ, struct node** tete){
	struct node *ptr;
	ptr = (struct node*) malloc(sizeof(struct node));
	ptr->suivant = *tete;
	ptr->code = i;
	ptr->occurence = occ;
	*tete = ptr;
}

