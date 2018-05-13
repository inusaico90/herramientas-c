#include <stdio.h>
#include <stdlib.h>

int main(){
	int x,y,i,j;
	printf("primero: ");
	scanf("%i",&x);
	printf("Segundo: ");
	scanf("%i",&y);
	int m[x][y];
	for(i=0;i<=x-1;i++){
		for(j=0;j<=y-1;j++){
			printf("[%i,%i]",j,i);
		}
		printf("\n");
	}
}
