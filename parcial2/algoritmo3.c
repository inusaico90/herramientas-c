/*
	NOMBRE DEL PROGRAMA: ALGORITMO2
	NOMBRE DEL ESTUDIANTE: KEVIN ERNEY ACOSTA LLANO
	CÓDIGO DEL ESTUDIANTE: 104618011480
	CORREO DEL ESTUDIANTE: erneylla@unicauca.edu.co
*/
#include <stdio.h>

void leer_arreglo(int prml, int prma[]);
void funcion(int prma[],int prmla);
	
int main(){
	int varlargo;
	
	printf ("ingrese el largo que desea: ");
	scanf ("%i",&varlargo);
	int arreglo[varlargo];
	
	leer_arreglo(varlargo,arreglo);
	funcion(arreglo,varlargo);
}

void leer_arreglo(int prml, int prma[]){
	int i,j;
	for (i=0;i<prml;i++){
		printf("Ingrese el valor numero %i:",i+1);
		scanf("%i",&prma[i]);
	}
}

void funcion(int prma[],int prmla){
	int index,i,j,aux;
	for (i=1;i<prmla;i++){
		index=prma[i];
		j=i-1;
		do{
			prma[j+1]=prma[j];
			j=j-1;
		}
		while((j>=0)&&(prma[j]>index));
		prma[j+1]=index;
		if(j==3&&i==4){
				for (aux=0;aux<prmla;aux++){
				printf("%i",prma[aux]);}
				}
			/*
				if(j==3){
				for (aux=0;aux<prmla;aux++){
				printf("%i",prma[aux]);}
				printf("\n%i\n",i);
			}*/
	}
}
