#include <stdio.h>  
#include <stdlib.h>

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


int main(){
	struct noeud * noeud = (struct noeud *) malloc(sizeof(struct noeud));	


};