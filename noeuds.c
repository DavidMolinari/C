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
struct noeud *defile(struct maillon **debut, struct maillon **fin);
void affiche(struct maillon* liste);
void insert(int val, struct noeud **racine);
void parcours_g_pre(struct noeud *racine);
void parcours_g_inf(struct noeud *racine);
void parcours_g_post(struct noeud *racine);
void parcours_largeur(struct maillon *file, struct maillon *fin);
struct maillon* defiler(struct maillon **liste);

int main(){
	
	struct maillon * debut = NULL;
	struct maillon * fin = NULL;

struct noeud * n1 = NULL;

	 insert(10, &n1);
	 insert(5, &n1);
	 insert(15, &n1);
	 insert(3, &n1);
	 insert(8, &n1);
	 insert(9, &n1);
	 insert(1, &n1);

/*
	printf("LISTE :\n");
	enfile(&debut, n1, &fin);
	enfile(&debut, n3, &fin);
	enfile(&debut, n2, &fin);
	affiche(debut);*/


	// printf("\nDEFILADE : \n" );
	// while(debut != NULL){
	// 	printf("\nAPRES DEFILADE : \n" );
	// 	defile(&debut, &fin);
	// 	affiche(debut);
	// }
	// printf("\n ___________________ \n");


	// Insertion random values
	// for (int i = 0; i < 5; i++) insert(rand() % 30, &n1);



	parcours_g_pre(n1);

printf("\n");

	enfile(&debut, n1, &fin);

	parcours_largeur(debut,fin);


};

void insert(int val, struct noeud **racine){
	struct noeud * N;

	if(*racine == NULL){
		N = (struct noeud *) malloc(sizeof(struct noeud));
		N->valeur = val;
		*racine = N;
		N->fg = NULL; N->fd = NULL;
	}else{
		if((*racine)->valeur > val){
			if((*racine)->fg != NULL)  {
				insert(val, &((*racine)->fg));
			}else{
				N = (struct noeud *) malloc(sizeof(struct noeud));
				N->valeur = val;
				(*racine)->fg = N;
				N->fg = NULL;
				N->fd = NULL;
			}
		}else{
			if((*racine)->fd != NULL) {
				insert(val, &((*racine)->fd));
			}else {
				N = (struct noeud *) malloc(sizeof(struct noeud));
				N->valeur = val;
				(*racine)->fd = N;
				N->fg = NULL;
				N->fd = NULL;
			}
		}
	}
}

/* Creation de Node plus facilitée */
struct noeud * creerNoeud(int val){
		struct noeud * N =(struct noeud *) malloc(sizeof(struct noeud));
		N->valeur = val;
		N->fg = NULL;
		N->fd = NULL;
		return N;
}

void parcours_largeur(struct maillon *file, struct maillon *fin){
	if(file!=NULL){

		struct maillon *dd = NULL;
		struct maillon *ff = NULL;
		struct noeud * tmp = NULL;

		while(file!=NULL){
			tmp = defile(&file, &fin);
			printf("[%d]", tmp->valeur);
			if(tmp->fg!=NULL){
				enfile(&dd, tmp->fg, &ff);
			}
			if(tmp->fd != NULL){
				enfile(&dd, tmp->fd, &ff);
			}

		}
		if(dd!=NULL) parcours_largeur(dd, ff);
		}
}

/*	Specifications : Cas vide => J'ajoute au debut et utilisation de deux pouinteurs
		Tete et Queue

		Cas Element dedans : la queue pointera sur la nouvelle boite et j'joute à la fin */
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

struct noeud *defile(struct maillon **debut, struct maillon **fin){
	if(*debut == NULL){
		return NULL;
	}else {
		struct noeud *result = (*debut)->node;
		struct maillon *next = (*debut)->suivant;		
		free(*debut); // Je vire la tete
		*debut= next;
		return result;
	}
}

// affiche une liste chainee
void affiche(struct maillon* liste){
	while(liste != NULL){
		printf("\n[ : %d ] \n", liste->node->valeur);
		liste = liste->suivant;
	}
}

// Parcours à gauche en Infix
void parcours_g_pre(struct noeud *racine){
	if(racine!=NULL){
		printf("%d|",racine->valeur);
		parcours_g_pre(racine->fg);
		parcours_g_pre(racine->fd);
	}
}

void parcours_g_inf(struct noeud *racine){
	if(racine!=NULL){
		parcours_g_inf(racine->fg);
		printf("%d|",racine->valeur);
		parcours_g_inf(racine->fd);
	}
}

void parcours_g_post(struct noeud *racine){
	if(racine!=NULL){
		parcours_g_post(racine->fg);
		parcours_g_post(racine->fd);
		printf("%d|",racine->valeur);
	}
}
