#include <stdio.h>  
#include <stdlib.h>

void afficheTab(int tab[], int taille);
void afficheValeurTab(int tab[], int taille);
void afficheMatrix(int **matrix, int taille);
void plusPetit(int **matrix, int taille);
void main(){

	int nb = 8;
	int taille = 8;
	int **matrix = NULL;

	unsigned int infini = -1;
    // int *d = NULL;
    int distance[] = {0,0,0,0,0,0,0,0};
    int pred[] = {0,0,0,0,0,0,0,0};

    // Initialisation de tous les distances à l'infini
   	for (int i = 0; i < taille; i++)
		distance[i] = infini;

    // Initialisation de tous les prédécésseurs à -1
	for (int i = 0; i < taille; i++)
		pred[i] = -1;

	printf("%d PRED1 \n", pred[1]);
	printf("%d PRED2 \n", 1[pred]);

	matrix = (int **) malloc(taille*sizeof(int**));
	for (int i = 1; i < taille+1; i++) 
		matrix[i] = (int *)malloc(taille*sizeof(int));
	

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

	afficheMatrix(matrix, taille);

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


