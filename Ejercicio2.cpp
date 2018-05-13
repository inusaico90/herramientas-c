#include <stdio.h>
#include <stdlib.h>

int Validar();
int Llenar(int nc,int nf,int j,int i);
void Mostrar(int nf, int nc);
int cola;
int NumeroPositivo(int nf, int nc,int m[][6]);

int main() {
	int i,j;
	int fila, col;
	printf("Digite el tamaño de la matriz MxN\n");
	fila=Validar();
	col=Validar();
	
	printf("fila: %i\ncolumna: %i\n",fila,col);
	int Matrix[fila][col];
	for(i=0;i<=fila-1;i++){
		for(j=0;j<=col-1;j++){
			Matrix[i][j]=Llenar(col,fila,j,i);
		}
	}
	Mostrar(fila, col);
	printf("El numero de elementos positivos en la matriz es: %d", NumeroPositivo(fila, col,&Matrix));
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

int Llenar(int nc,int nf,int j,int i){
	int m[nf][nc];
	printf("Digite valor para la posicion (%i,%i)", i, j);
	scanf("%i",&m[i][j]);
	return m[i][j];
}

int Validar(){
	int valor;
	do{
		printf("Digite un valor: ");
		scanf("%i", &valor);
	}while(valor<=0);
	return valor;
}

int NumeroPositivo(int nf, int nc,int m[][6]){
	int cont=0;
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			printf("%i\n",*m[i]);
			if(m[i]>0){
				cont++;
			}
		}
	}
	return cont;
}
