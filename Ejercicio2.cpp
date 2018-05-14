#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Validar();
void Llenar(int **,int,int);
void Mostrar(int, int,int **);
int NumeroPositivo(int,int,int **);
int **Matrix,fila,col;

int main() {	
	setlocale(LC_CTYPE,"Spanish");
	printf("Digite el tamaño de la matriz MxN\n");
	fila=Validar();
	col=Validar();
	Matrix=new int*[fila];//Reservar memoria de fila
	for (int i=0;i<fila;i++){
		Matrix[i]=new int[col]; //Reservar memoria columna
	}
	printf("fila: %i\ncolumna: %i\n",fila,col);
	Llenar(Matrix,fila,col);
	Mostrar(fila, col, Matrix);
	printf("El numero de elementos positivos en la matriz es: %i", NumeroPositivo(fila,col,Matrix));
	//Liberar memoria
	for (int i=0;i<fila;i++){
		delete[] Matrix[i];
	}
	delete[] Matrix;
	return 0;
}

void Mostrar(int fila, int col,int **Matrix){
	for(int i=0; i<fila; i++){
		for(int j=0; j<col; j++){
			printf("[%i]\t",Matrix[i][j]);
		}
		printf("\n");
	}
}

int NumeroPositivo(int fila, int col,int **Matrix){
	int cont=0;
	for(int i=0;i<fila;i++){
		for(int j=0;j<col;j++){
			if(Matrix[i][j]>0){
				cont=cont+1;
			}
		}
	}
	return cont;
}

void Llenar(int **Matrix,int fila, int col){
	for(int i=0;i<fila;i++){
		for(int j=0;j<col;j++){
			printf("Digite valor para la posicion (%i,%i)", i, j);
			scanf("%i",&Matrix[i][j]);
		}
	}
}

int Validar(){
	int valor;
	do{
		printf("Digite un valor: ");
		scanf("%i", &valor);
	}while(valor<=0);
	return valor;
}
