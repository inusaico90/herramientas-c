#include <stdio.h>
#include <stdlib.h>
long aiData[15000];
long i, iN, iM, iTemp, iTotal;

int compare(const void *piNuml, const void *piNum2){
	return (*(long *)piNuml - *(long *)piNum2);
}

int main(void){
	printf("Valor 1\n");
	scanf("%ld",&iN);
	printf("El numero de lista es:");
	for (i=0;i<iN;i++){
		scanf("%ld",&aiData[i]);
	}
	printf("valor 2\n");
	scanf("%ld",&iM);
	for (i=0, iTotal;i<iM;i++){
		printf ("valor 2 lectura %ld de %ld\n",i,iM);
		scanf("%ld",&iTemp);
		if(bsearch(&iTemp,aiData,iN,sizeof(long),compare)!=NULL){
		iTotal++;
		}
		printf("%ld\n",iTotal);
	}
	printf("%ld",iTotal);
	return(0);
}

