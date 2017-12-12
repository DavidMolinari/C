#include <stdio.h>  
#include <stdlib.h>
void p_p(int **matrix, int s, int *m);
void prgrph(int **matrix);
void main(){

int nb = 5;
int marques[5] = {0};

int taille = 5;
int **matrix = NULL;

matrix = (int **) malloc(taille*sizeof(int**)); // Tab of tab
for (int i = 0; i < taille; i++)
{
	matrix[i] = (int *)malloc(taille*sizeof(int));
}


matrix[1][2] = 1;
matrix[2][1] = 1;
matrix[2][4] = 1;
matrix[4][2] = 1;


for (int i = 0; i <nb; i++){
	for (int j = 0; j < nb; j++){
		printf("%d\t",matrix[i][j] );
	}
	printf("\n");
	}


	prgrph(matrix);
}



void prgrph(int **matrix){
	int marques[5] = {0};
	for (int i = 0; i < 5; i++)
	{
		p_p(matrix, i, marques);
	}
}

void p_p(int **matrix, int s, int *m){
	if(m[s] == 0){
		m[s] = 1;
		printf("%d\n",s+1);
		for(int j = 0; j<5; j++){
			if(matrix[s][j] == 1){
				p_p(matrix, j, m); // j = Le sommet 
		}
	}
	}
}
