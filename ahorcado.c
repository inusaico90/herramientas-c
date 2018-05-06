/*CREADO POR INUSAICO90
JUEGO: "El ahorcado"
VERSIÓN: 0.1.3
*/
#include <stdio.h>
#include <string.h>

#include <time.h>
#include <stdlib.h>


void elegir_palabra(char prmPS[]);
void crear_secreto(char prmPS[],int prmL,char prmP[]);
void comparar(char prmPS[],int prmL,int *prmE,char varI[],char prmP[]);
void mostrar(char prmI[],char prmP[],char prmPS[], int prmL);


int main(){
	inicio:;
	char varPSecreta[100]="";
	char varPalabra[100]="";
	char varIntento[25];
	int varLargo,i,varError;
	varError=0;
	elegir_palabra(varPSecreta);
	varLargo=(strlen(varPSecreta))-1;
	crear_secreto(varPSecreta,varLargo,varPalabra);
	for (i=0;varError<=4;i++){
		printf("\n\nintento numero %i con %i fallos de 5\n",i,varError);
		comparar(varPSecreta,varLargo,&varError,varIntento,varPalabra);
		if (strcmp(varPSecreta,varPalabra)==0){
			goto exito;
		}
		else{
			if(varError==5){
				printf("\nLa palabra era: %s",varPSecreta);
				goto fin;
			}
		}
	}
	exito:
		system("cls");
		printf("Felicidades, encontraste la palabra");
	fin:;
}

void elegir_palabra(char prmPS[]){
	int varOpcion;
	srand(time(NULL));
	varOpcion=1+rand()%(10-1);
	switch(varOpcion){
		case 1:
			strcat(prmPS,"cauca");
			printf("Pista: Universidad del ");
			break;
		case 2:
			strcat(prmPS, "inusaico90");
			printf("Pista: soy yo, soy yo\n");
			break;
		case 3:
			strcat(prmPS, "ensamblador");
			printf("Pista: Lenguaje de maquina\n");
			break;
		case 4:
			strcat(prmPS, "sistema");
			printf("Pista: Conjunto de elementos que trabajan por un mismo fin\n");
			break;
		case 5:
			strcat(prmPS,"pseudocodigo");
			printf("Pista: 'codigo' antes de pasar a un lenguaje\n");
			break;
		case 6:
			strcat(prmPS,"java");
			printf("Pista: mejor que c (segun yo)\n");
			break;
		case 7:
			strcat(prmPS,"cafe");
			printf("Pista: Amor olor a ");
			break;
		case 8:
			strcat(prmPS,"azul");
			printf("Pista: color mar\n");
			break;
		case 9:
			strcat(prmPS,"negro");
			printf("Pista: Color con todos los colores\n");
			break;
		case 10:
			strcat(prmPS,"feu");
			printf("Pista: Federación de estudiantes universitario\n");
			break;
		default:
			printf("creado por inusaico90");
			strcat(prmPS,"");
			break;
	}
}

void crear_secreto(char prmPS[],int prmL,char prmP[]){
	int i;
	for(i=0;i<=prmL;i++){
		if(prmPS[i]==' '){
			prmP[i]=' ';
		}
		else{
			prmP[i]='_';
		}
	}
	for (i=0;i<=prmL;i++){
		printf("%c",prmP[i]);
	}
}

void comparar(char prmPS[],int prmL,int *prmE,char varI[],char prmP[]){
	int i,x=0;
	printf("por favor ingresa tu intento %i: ",x+1);
	fgets(varI,24,stdin);
	for(i=0;i<=prmL;i++){
		if(varI[0]==prmPS[i]){
			mostrar(varI,prmP,prmPS,prmL);
			goto fin;
		}
		else{
			x=x+1;
			if(x==prmL){
				*prmE=*prmE+1;
			}
		}
	}
	fin:;
}

void mostrar(char prmI[],char prmP[],char prmPS[], int prmL){
	int i;
	i=0;
	for(i=0;i<=prmL;i++){
		if(prmI[0]==prmPS[i]){
			prmP[i]=prmPS[i];
		}
	}
	printf("La palabra la llevas asi:\n%s",prmP);
}
