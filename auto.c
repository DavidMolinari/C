#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int automeh(char* msg, int n);
int main(int argc, char *argv[]){ 
	char* msg = argv[1];
	int n = atoi(argv[2]) ;
	// int n strlen(msg);
	int mmmmmm = automeh(msg, n);
	printf("\nREGEX : a(a*ba(ba)*ab*)\n");
	printf("%s\n",msg);

	if(mmmmmm == 1) printf("TUTTI VA BENE\n");
	else printf("FAIL\n");
}



int automeh(char* msg, int n){
	int etat = 1; 
	for (int i = 0; i < n; i++)
	{
		switch(msg[i]) {
      		case 'a' :
      			if (etat == 1) etat = 2;
      			else if (etat == 2) etat = 3;
      			else if (etat == 3) etat = 3;
      			else if (etat == 4) etat = 5;
      			else if (etat == 5) etat = 6;
      			else if (etat == 3) etat = 3;
      			else if (etat == 7) etat = 5;
      			else return false;
      			break;
      		case 'b' :
      			if(etat == 2) etat = 4;
      			else if(etat == 3) etat = 4;
      			else if(etat == 5) etat = 4;
      			else if(etat == 6) etat = 7;
      			else if(etat == 7) etat = 7;
      			else return false;
         		break; 
      		default :
         		printf("MEH\n");
      			return false;
   			}
	}
	if(etat == 2) return 1;
	else if(etat == 6) return 1;
	else if(etat == 7) return 1;
	else return -1;
}
