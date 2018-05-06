#include <stdio.h>
void ordenar (int a[]);
void imprimir (int x[]);
int main (){
	int v[10]={10,9,32,41,66,54,123,78,18,001};
	
	imprimir(v);
	ordenar (v);
	imprimir (v);
	return 0;
}
void ordenar (int a[]){
	int i,j,aux;
	for (i=0;i<9;i++){
		for (j=i+1;j<10;j++){
			if(a[i]>a[j]){
			aux=a[i];
			a[i] = a[j];
			a[j] = aux;
			}
		}
	}
}
void imprimir (int x[]){
	int i;
	for (i=0;i<10;i++){
		printf ("%i-",x[i]);
	}
	printf("\n\n");
}
