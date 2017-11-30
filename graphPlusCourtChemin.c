#include <stdio.h>  
#include <stdlib.h>
/*
    Méthode pour afficher un tableau
*/
void afficheTab(int tab[], int taille);
void plusPetitChemin(int **matrix, int **d, int **pred, int nbNoeuds);
// void printTab(int *tab, int taille);
void initMatrix(int **matrix, int taille);
void main(){
	int nb = 8;
	int taille = 8;
	int **matrix = NULL;

    // int *d = NULL;
    int distance[] = {0,0,0,0,0,0,0,0};
    int pred[] = {0,0,0,0,0,0,0,0};

	// int infini = -1;
	
	matrix = (int **) malloc(taille*sizeof(int**));
	for (int i = 1; i < taille+1; i++) 
		matrix[i] = (int *)malloc(taille*sizeof(int));
	



	afficheTab(t, 8);

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

	for (int i = 1; i <nb+1; i++){
		for (int j = 1; j < nb+1; j++){
			printf("%d\t",matrix[i][j] );
		}
		printf("\n");
	}
	
}
/*	
*/
void initMatrix(int **matrix, int taille){

}
/*
    Méthode pour afficher un tableau
*/
void afficheTab(int tab[], int taille){
	printf("Tableau : \n");
    for (int i = 0; i < taille; i++)
    {
        printf("%u | ", tab[i]);
    }
    printf("\n");
}


void plusPetitChemin(int **matrix, int **d, int **pred, int nbNoeuds){

	unsigned int infini = -1;

	for (int i = 0; i < taille; i++)
		distance[i] = infini;

	for (int i = 0; i < taille; i++)
		pred[i] = -1;
}