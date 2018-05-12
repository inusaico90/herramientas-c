#include <stdio.h>
#include <stdlib.h>

int Validar();
void Llenar(int nc, int nf);
void Mostrar(int nf, int nc);
int NumeroPositivo(int nf, int nc);
int main() {
	
	int fila, col;
	
	printf("Digite el tamaño de la matriz MxN\n");
	fila=Validar();
	col=Validar();
	
	printf("fila: %d\ncolumna: %d\n",fila,col);
	int Matrix[fila][col];
	
	Llenar(col,fila);
	Mostrar(fila, col);
	
	printf("El numero de elementos positivos en la matriz es: %d", NumeroPositivo(fila, col));
	
	return 0;
}
void Mostrar(int nf, int nc){
	int m[nf][nc];
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			printf("[%d]\t", m[i][j]);
		}
		printf("\n");
	}	
}

void Llenar(int nc,int nf){
	int m[nf][nc];
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			printf("Digite valor para la posicion (%i,%i)", i, j);
			scanf("%i", &m[i][j]);
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

int NumeroPositivo(int nf, int nc){
	int m[nf][nc];
	int cont=0;
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			if((m[i][j])>0){
				cont++;
			}
		}
	}
	return cont;
}
