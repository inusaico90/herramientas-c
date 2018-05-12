#include <stdio.h>
#include <stdlib.h>
#define t NULL

void Mostrar(int m[][t], int nf, int nc);
void Llenar(int nc, int nf,int m[][t]);
int Validar();
int NumeroPositivo(int m[][t], int nf, int nc);
int main() {
	
	int fila, col;
	
	printf("Digite el tamaño de la matriz MxN\n");
	fila=Validar();
	col=Validar();
	
	printf("fila: %i\ncolumna: %i\n",fila,col);
	int Matrix[fila][t];
	
	Llenar(col,fila,Matrix);
	Mostrar(Matrix, fila, col);
	
	printf("El número de elementos positivos en la matriz es: %d", NumeroPositivo(Matrix, fila, col));
	
	return 0;
}


void Mostrar(int m[][t], int nf, int nc){
	
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			printf("[%d]\t", m[i][j]);
		}
		printf("\n");
	}	
}

void Llenar(int nc,int nf,int m[][t]){
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			printf("Digite valor para la posicion (%d,%d)", i, j);
			scanf("%d", &m[i][j]);
		}
	}
}

int Validar(){
	int valor;
	do{
		printf("Digite un valor: ");
		scanf("%d", &valor);
	}while(valor<=0);
	return valor;
}

int NumeroPositivo(int m[][t], int nf, int nc){
	
	int cont=0;	
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			if(m[i][j]<0){
				cont++;
			}
		}
	}
	return cont;
}
