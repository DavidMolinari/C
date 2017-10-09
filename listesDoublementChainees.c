#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// Insertion dans une liste chainee de type struct

struct Maillon
{
	int valeur;
	struct Maillon *suivant;
	struct Maillon *prec;

};
void afficheListe(struct Maillon* liste);

void insereApres(int valeur, struct Maillon **ptr);


int main(){

struct Maillon *liste;
liste = (struct Maillon*) malloc(sizeof(struct Maillon));
liste->valeur = 3;
liste->suivant = NULL;
liste->prec = NULL;
insereApres(22, &liste);


insereApres(12, &liste);
insereApres(25, &liste);

afficheListe(liste);


}
// affiche une liste chainee
void afficheListe(struct Maillon* liste){
	while(liste != NULL){
		printf("%d | ", liste->valeur);
		liste = liste->suivant;
	}
}
void insereApres(int valeur, struct Maillon **ptr){
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
};