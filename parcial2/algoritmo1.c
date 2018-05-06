/*
	NOMBRE DEL PROGRAMA: ALGORITMO1
	NOMBRE DEL ESTUDIANTE: KEVIN ERNEY ACOSTA LLANO
	CÓDIGO DEL ESTUDIANTE: 104618011480
	CORREO DEL ESTUDIANTE: erneylla@unicauca.edu.co
*/

#include <stdio.h>

void leer_arreglo(int prml, int prma[]);
void ordenar_a(int a[],int prml);

	
int main(){
	int varlargo;
	
	printf ("ingrese el largo que desea: ");
	scanf ("%i",&varlargo);
	int arreglo[varlargo];
	
	leer_arreglo(varlargo,arreglo);
	
	ordenar_a(arreglo,varlargo);
	return 0;
}

void leer_arreglo(int prml, int prma[]){
	int i,j;
	for (i=0;i<prml;i++){
		printf("Ingrese el valor numero %i:",i+1);
		scanf("%i",&prma[i]);
	}
}


void ordenar_a(int a[],int prml)
{
	int i,j,aux;
	for (i=0;i<(prml-1);i++){
		for (j=0;j<(prml-1-i);j++){
			if(a[j]>a[j+1]){
			aux=a[j];
			a[j] = a[j+1];
			a[j+1] = aux;
			}
			/*if(j==4&&i==4){
				for (aux=0;aux<prml;aux++){
				printf("%i",a[aux]);}
				}
			}*/
		}
	}

