#include <stdio.h>  
#include <stdlib.h>



/* Besoin :  parcours en largeur d'un arbre */

// Structure d'un noeud
struct noeud{
	int valeur;
	struct noeud *fg;
	struct noeud *fd;
};


// Liste chainee pour enfiler / Défiler
struct maillon{
	struct noeud *node;
	struct maillon *suivant;


};



// DECLARATION DE FONCTIONS :
struct noeud * creerNoeud(int valeur);
void enfile(struct maillon **debut, struct noeud *n, struct maillon **fin);
struct noeud * defile(struct maillon **debut, struct maillon **fin);
void affiche(struct maillon* liste);
struct maillon* defiler(struct maillon **liste);

int main(){
	
	struct maillon * debut = NULL;
	struct maillon * fin = NULL;

	struct noeud * n1 = creerNoeud(1);
	struct noeud * n3 = creerNoeud(3);
	struct noeud * n2 = creerNoeud(2);

printf("LISTE :\n");
	enfile(&debut, n1, &fin);
	enfile(&debut, n3, &fin);
	enfile(&debut, n2, &fin);
	
	affiche(debut);
	printf("\nDEFILADE : \n" );
	while(debut != NULL){
		printf("\nAPRES DEFILADE : \n" );
		defile(&debut, &fin);
		affiche(debut);
	}

	


	printf("\n ___________________ \n");
};

/*
	Facilite juste la creation de noeud pour l'instant
*/
struct noeud * creerNoeud(int valeur){
	struct noeud * noeud = (struct noeud *) malloc(sizeof(struct noeud));	
	noeud->valeur = valeur;
	noeud->fg = NULL;
	noeud->fd = NULL;
	return noeud;
}

// void enfilerV2(struct maillon **liste, struct noeud *node){

// 	struct maillon *newMaillon = (struct maillon *)malloc(sizeof(struct maillon));
// 	newMaillon->node = node; 

// 	// Need pointeur de debut

// 	while(*liste !=NULL){
// 		*liste = (*liste)->suivant;
// 		printf("++ \n");
// 	}

// 	// Cas de la liste vide, j'ajoute directement
// 	// J'ajoute à la fin de la liste
// 	else if(*liste !=NULL){
// 		printf("Ajout à la fin\n");
// 			newMaillon->suivant = NULL; // Toujours à NULL car on ajoute à la fin
// 		(*liste)->suivant = newMaillon;
// 	}
// }
/*
	Specifications : Cas vide => J'ajoute au debut et utilisation de deux pouinteurs
		Tete et Queue

		Cas Element dedans : la queue pointera sur la nouvelle boite et j'joute à la fin
*/
void enfile(struct maillon **debut, struct noeud *n, struct maillon **fin){
	
	struct maillon *newMaillon = (struct maillon *)malloc(sizeof(struct maillon));
	newMaillon->node = n;
	newMaillon->suivant = NULL;	
	// Cas 1 , liste vide
	if(*debut == NULL){
		*debut = newMaillon;
		*fin = newMaillon;	
	}else{ // Le pointeur de fin sera sur le nouvel el
		(*fin)->suivant = newMaillon; // la tete ne bouge jamais
		*fin = newMaillon;
	}

}

struct noeud * defile(struct maillon **debut, struct maillon **fin){
	if(*debut == NULL){
		return NULL;
	}else {
		struct maillon *result = *debut;
		struct maillon *next = (*debut)->suivant;		
		// *debut = (*debut)->suivant; // Je décale la tete
		free(*debut); // Je vire la tete
		*debut= next;
		return result->node;
	}
}


// affiche une liste chainee
void affiche(struct maillon* liste){
	while(liste != NULL){
		printf("\n[ : %d ] \n", liste->node->valeur);
		liste = liste->suivant;
	}
}