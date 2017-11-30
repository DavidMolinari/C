#include <stdio.h>  
#include <stdlib.h>

void afficheTab(int tab[], int taille);
void afficheValeurTab(int tab[], int taille);
void afficheMatrix(int **matrix, int taille);
void plusPetit(int **matrix, int taille, int *distance, int *pred);
int* getVoisin(int **tab, int taille, int sommet);
struct Node
{
	int valeur;
	int ponderation;
};

void main(){

	int nb = 8;
	int taille = 8;
	int **matrix = NULL;
	matrix = (int **) malloc(taille*sizeof(int**));
	for (int i = 1; i < taille+1; i++) 
		matrix[i] = (int *)malloc(taille*sizeof(int));

    // int *d = NULL;

	// struct Node *node;

 //    int **m = NULL;
 //    m = (int **) malloc(taille*sizeof(int**));
 //    for (int i = 0; i < taille; i++)
 //    {
 //    	m[i] = (struct Node*)malloc(taille*sizeof(struct Node));
 //    }
 //    	node = (struct Node*) malloc(sizeof(struct Node));
	// 	node->valeur = 3;
	// 	node->ponderation = 5;
 //    	m[1] = node;

 //    for (int i = 0; i < taille; i++)
 //    {
 //    	for (int j = 0; j < taille; j++)
 //    	{
 //    		printf("%d\n",m[i][j]->valeur);
 //    	}
 //    }




    int distance[] = {0,0,0,0,0,0,0,0};
    int pred[] = {0,0,0,0,0,0,0,0};


    plusPetit(matrix, taille, distance, pred);

	afficheMatrix(matrix, taille);

}
void plusPetit(int **matrix, int taille, int *distance, int *pred){

	unsigned int infini = -1;

	    // Initialisation de tous les distances à l'infini
   	for (int i = 0; i < taille; i++)
		distance[i] = infini;

    // Initialisation de tous les prédécésseurs à -1
	for (int i = 0; i < taille; i++)
		pred[i] = -1;

	printf("Tableau des distances : \n");
	afficheTab(distance, 8);
	printf("Tableau des prédécésseurs : \n");
	afficheValeurTab(pred, 8);

	matrix[1][2] = 1;
	matrix[1][3] = 3;
	matrix[2][1] = 1;
	matrix[2][6] = 4;
	matrix[2][5] = 9;
	matrix[2][7] = 4;
	matrix[3][1] = 3;
	matrix[3][4] = 10;
	matrix[4][3] = 10;
	matrix[4][7] = 7;
	matrix[4][5] = 8;
	matrix[5][4] = 8;
	matrix[5][2] = 9;
	matrix[6][2] = 4;
	matrix[7][2] = 4;
	matrix[7][4] = 7;

	printf("AFFICHAGE DES VOISINS");
	int *voisin = NULL;


	voisin = getVoisin(matrix, taille, 3);
	printf("\nVoisin de  %d : ", 3);
	for (int i = 1; i < taille+1; i++)
		if(voisin[i] > 0)
		printf("%d,",i);
	
	printf("\n");
	}
/* Affiche une matrice */
void afficheMatrix(int **matrix, int taille){
	for (int i = 1; i <taille+1; i++){
		for (int j = 1; j < taille+1; j++){
			printf("%d\t",matrix[i][j] );
		}
		printf("\n");
	}
}
/*	Affiche un tableau avec ses valeurs en %u */
void afficheTab(int tab[], int taille){
    for (int i = 0; i < taille; i++)
    {
        printf("%u | ", tab[i]);
    }
    printf("\n");
}
/* Affiche un tableau avec ses valeurs en %d */
void afficheValeurTab(int tab[], int taille){

    for (int i = 0; i < taille; i++)
    {
        printf("%d | ", tab[i]);
    }
    printf("\n");
}
/* Affiche un tableau avec la liste des voisins du sommet */
int* getVoisin(int **tab, int taille, int sommet){
	int *result = (int *) malloc(taille*sizeof(int));
	for (int i = 0; i < taille; i++)
		if(tab[sommet][i]>0) result[i] = tab[sommet][i];
	return result;
}
