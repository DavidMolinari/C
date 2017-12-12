
#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// Insertion dans une liste chainee de type struct	
struct maillon
{
	int valeur;
	struct maillon *suivant;
};

void afficheListe(struct maillon* liste);
int recherche(int elt, struct maillon* liste);
void supprimer(int elt, struct maillon** liste);
void insertOrdonne(int el, struct maillon** liste);

void insert(int el, struct maillon** tete);
int main(){

struct maillon *liste;
liste = (struct maillon*) malloc(sizeof(struct maillon));
liste->valeur = 3;
liste->suivant = NULL;


afficheListe(liste);
printf("\n");
//supprimer(66, &liste);
//afficheListe(liste);
insertOrdonne(22, &liste);
insertOrdonne(4, &liste);
insertOrdonne(2, &liste);
insertOrdonne(12, &liste);
insertOrdonne(40, &liste);
insertOrdonne(1, &liste);

afficheListe(liste);

printf("\n");
//insertOrdonne(12, 3)


}

int recherche(int elt, struct maillon* liste){
	struct maillon* ptr;
	ptr = liste;
	// condition d'arret
	while(ptr!= NULL && ptr->valeur != elt){
		ptr = ptr->suivant;
	}
	if(ptr == NULL) return 0;
	else return 1;
}


// insert un element dans une liste chainee
void insert(int el, struct maillon** tete){
	struct maillon *ptr;
	ptr = (struct maillon*) malloc(sizeof(struct maillon));
	ptr->suivant = *tete;
	ptr->valeur = el;
	*tete = ptr;
}

// affiche une liste chainee
void afficheListe(struct maillon* liste){
	while(liste != NULL){
		printf("%d | ", liste->valeur);
		liste = liste->suivant;
	}
}

// supprime un element d'une liste chainee
void supprimer(int elt, struct maillon** liste){
	struct maillon *ptr, *prec;
	ptr = *liste;
	while(ptr != NULL && ptr->valeur !=elt){
		prec = ptr;
		ptr = ptr->suivant;
	}
	if(ptr!=NULL){
		if(prec == NULL) {
			*liste = ptr->suivant;
		}else{
			prec->suivant = ptr->suivant;
		}	
		free(ptr);
	}

}
// Insert dans une liste chainee en ordonné
void insertOrdonne(int el, struct maillon** liste) {
	struct maillon *ptr, *prec, *newBoite;
	prec = NULL;
	newBoite = (struct maillon*) malloc(sizeof(struct maillon));
	newBoite->valeur = el;
	ptr = *liste;
	while(ptr!=NULL && ptr->valeur < el ){
		prec = ptr;
		ptr = ptr->suivant;
	}
	// cas dernier element
	if(ptr == NULL){
		if(prec == NULL){
			newBoite->suivant = NULL;
			*liste = newBoite;
		}
		else {
			prec->suivant = newBoite;
			newBoite->suivant = NULL;
		}
	}else{
		if(prec == NULL){
			newBoite->suivant = ptr;
			*liste = newBoite;
		}
		else {
			prec->suivant = newBoite;
			newBoite->suivant = ptr;

		}
	}
}
