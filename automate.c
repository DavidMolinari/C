#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int automeh(char* msg, int n);
int main(int argc, char *argv[]){ 
	char* msg = argv[1];
	int n = atoi(argv[2]) ;
	int mmmmmm = automeh(msg, n);
	printf("%d\n",mmmmmm );
	if(mmmmmm == 1) {
		printf("Dylan++\n");
} else "Dylan--\n";
}



int automeh(char* msg, int n){
	int etat = 1; 
	for (int i = 0; i < n; i++)
	{
		printf("%c\n", msg[i]);
		switch(msg[i]) {
      		case 'a' :
      		printf("MEH A\n");
      			if (etat == 1) etat = 2;
      			else if (etat == 2) etat = 3;
      			else return false;
      			break;
      		case 'b' :
      			if(etat == 3) etat = 4;
      			else return false;
         		break; 
     		case 'c' :
     			if(etat == 3) etat = 1;
     			else if(etat == 4) etat = 4;
      			else return false;
         		break;
      		default :
         		printf("MEH\n");
      			return false;
   			}
	}
	if(etat == 4) return 1;
	else return -1;
}
