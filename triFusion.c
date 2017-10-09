#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// CORRECTION.
/*
Declaration des prototypes avant le main.
ex : int cherche(int val);
     /!\ JAMAIS DE VARIABLES GLOBALES !  /!\
     /!\ Tableau = Pointeur  /!\
     /!\ Kernighan & Richie Langage C => Livre à lire.
*/
// Prototype

void afficheTab(int tab[], int taille);
void fusion(int tab[], int d, int m, int f);
void tri(int tab[], int d, int f);



int main(){

    int tabAtrier[] = {1, 2, 3, 4, 1, 2, 3, 4};

    int tailleTableau = 7;
    int debut = 0;
    int milieu = ((tailleTableau + debut) / 2) +1;


    int t[] = {3,4,5,6,3,4,5,6};

    printf("Tableau non fusionné :\n");
    afficheTab(tabAtrier, tailleTableau);
    //afficheTab(t, nb);
    printf("\n Tableau après fusion : \n");
    //theFusion(t, 1, mid, nb);
    //  //  afficheTab(t, nb);
    //fusion(tabAtrier, debut, milieu, tailleTableau);
    //afficheTab(tabAtrier, tailleTableau);


    //printf("Nouveau Tableau non trié : \n");
    //int tt[] = {1,3,4,2,1,6,1,3};
    //afficheTab(tt, tailleTableau);

    printf("Trifusion recursive EN COURS :\n");
    tri(tabAtrier,0,tailleTableau);
    afficheTab(tabAtrier, tailleTableau);

}

/*
    Méthode pour afficher un tableau
*/
void afficheTab(int tab[], int taille){

    for (int i = 0; i < taille+1; ++i)
    {
        printf("%d | ", tab[i]);
    }
    printf("\n");
}

/**  
    
**/
void fusion(int t[], int d, int m, int f){
    int milieu = m;
    int debut = d;
    int *newTab = (int *) malloc((f-d)*sizeof(int));
    int i;

    for (i = 0; i <= (f-debut); i++)
    {

        if (d==milieu)
        {
            newTab[i] = t[m];
            m++;

        }else if(m==(f+1)){
            newTab[i] = t[d];
            d++;
        }
        else if (t[d] < t[m])
        {
            newTab[i] = t[d];
            d++;
        }
        else{
            newTab[i] = t[m];
            m++;
        }
    }
    for (i = 0; i <= (f-debut); i++){
        t[debut+i] = newTab[i];

    } 
    free(newTab);

}
/*
    Trifusion recursive.
*/
void tri(int tab[], int d, int f){
    int m;
    if (f%2 == 0) m = (d+f)/2+1;
    else if (f%2==1)  m = (d+f)/2+1;
    if (d!=f){

        tri(tab,d,m-1);
        tri(tab,m,f);
        fusion(tab,d,m,f);
    }
}

