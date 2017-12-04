#include <stdio.h>
#include <stdlib.h>

// Structure d'un noeud
struct noeud{
	int valeur;
	struct noeud *suivant;
};
void parcoursDist(int **matrix, int sd, unsigned int *distance, int *pred);
void enfile(int valeur, struct noeud **debut, struct noeud **fin);
int defile(struct noeud **debut);

void main(){


int taille = 5;
int **matrix = NULL;

matrix = (int **) malloc(taille*sizeof(int**)); // Tab of tab
for (int i = 0; i < taille; ++i)
{
	matrix[i] = (int *)malloc(taille*sizeof(int));
}


matrix[0][1] = 1;
matrix[0][2] = 5;
matrix[1][2] = 2;
matrix[1][3] = 5;
matrix[2][4] = 2;
matrix[2][3] = 12;
matrix[3][4] = 2;
matrix[4][2] = 3;


for (int i = 0; i < 5; ++i) {
	for (int j = 0; j < 5; ++j)
		printf("%d\t",matrix[i][j]);
	 printf("\n");
	}
unsigned int distance[5];
int pred[5];

for (int i = 0; i < 5; ++i) distance[i] = -1;
for (int i = 0; i < 5; ++i) pred[i] = -1;

int sd = 0; // Sommet de départ


for (int i = 0; i < 5; ++i) printf("%d\t",distance[i]);
	printf("\n" );
for (int i = 0; i < 5; ++i) printf("%d\t",pred[i]);
	printf("\n" );

parcoursDist(matrix,sd,distance,pred);

printf("\n________________________\n");
for (int i = 0; i < 5; ++i) {
	for (int j = 0; j < 5; ++j)
		printf("%d\t",matrix[i][j]);
	 printf("\n");
	}

for (int i = 0; i < 5; ++i) printf("%d\t",distance[i]);
	printf("\n" );
for (int i = 0; i < 5; ++i) printf("%d\t",pred[i]);
	printf("\n" );


}

void parcoursDist(int **matrix, int sd, unsigned int *distance, int *pred){
	distance[sd] = 0;struct noeud *dd = NULL;struct noeud *ff = NULL;
	enfile(sd, &dd, &ff);
	while(dd != NULL){
		int s = defile(&dd);
		for (int i = 0; i < 5; ++i)
		{
			if(matrix[s][i]>0){
				if(distance[i] > distance[s] + matrix[s][i]){
					distance[i] = distance[s] + matrix[s][i];
					enfile(i, &dd, &ff);
					pred[i] = s;
				}
			}
		}
	}
}



void enfile(int valeur, struct noeud **debut, struct noeud **fin){
	
	struct noeud *newNode = (struct noeud *)malloc(sizeof(struct noeud));
	newNode->valeur = valeur; newNode->suivant = NULL;	
	// Cas 1 , liste vide
	if(*debut == NULL){
		*debut = newNode;
		*fin = newNode;
	}else{ // Le pointeur de fin sera sur le nouvel el
		(*fin)->suivant = newNode; // la tete ne bouge jamais
		*fin = newNode;
	}
}

int defile(struct noeud **debut){
	if(*debut == NULL)
		return -1;
	else {
		int result = (*debut)->valeur;
		struct noeud *next = (*debut)->suivant;		
		free(*debut); // Je vire la tete
		*debut= next;
		return result;
	}
}