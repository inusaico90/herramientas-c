/*Nombre: ajedrez en C
creador: Kevin Erney Acosta (inusaico90)
version: 0.0.1*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#ifdef __linux__
#define LIMPIAR "CLEAR"
#endif // __linux__
 
#ifdef __MINGW32__
#define LIMPIAR "CLS"
#endif // __MINGW32__

#ifdef __APPLE__
#define LIMPIAR "clear"
#endif 

char mesa[9][33];
char varJugador1[4];
char varJugador2[4];
bool varJugador=true;

void ficha (int j, int i);
void color(int i,int j);
void tablero();
void validar_mover(char prmColor[],char prmJugador[]);
void inicializarVar();

int main(){
	inicializarVar();
	setlocale(LC_CTYPE,"Spanish");
	int varOpcion;
	strcat(mesa[0],"[tn][cn][an][rn][dn][an][cn][tn]8");
	strcat(mesa[1],"[pn][pn][pn][pn][pn][pn][pn][pn]7");
	strcat(mesa[2],"[  ][  ][  ][  ][  ][  ][  ][  ]6");
	strcat(mesa[3],"[  ][  ][  ][  ][  ][  ][  ][  ]5");
	strcat(mesa[4],"[  ][  ][  ][  ][  ][  ][  ][  ]4");
	strcat(mesa[5],"[  ][  ][  ][  ][  ][  ][  ][  ]3");
	strcat(mesa[6],"[pb][pb][pb][pb][pb][pb][pb][pb]2");
	strcat(mesa[7],"[tb][cb][ab][db][rb][ab][cb][tb]1");
	strcat(mesa[8]," a   b   c   d   e   f   g   h ");
	printf("****************BIENVENIDO A C.AJEDREZ****************\nSi quieres salir oprime 1, si quieres continuar oprime 2\n");
	scanf("%i",&varOpcion);
	
	system(LIMPIAR);
	if(varOpcion!=2){
		goto fin;
	}
	tablero(mesa);
	if(varJugador){
		validar_mover("1(blanca)",varJugador1);
	}
	else{
		validar_mover("2(negra)",varJugador2);
	}
	fin:
	printf("Gracias por elegirnos, te esperamos pronto para otra partida.");
}
void inicializarVar(){
	int varContador;
	for(varContador=0;varContador==8;varContador++){
		strcat(mesa[varContador],"");
	}
}
void validar_mover(char prmColor[],char prmJugador[]){
		printf("Jugador %c elije que ficha mover:\n",prmColor[0]);
		scanf("%c",prmJugador);	
}

void tablero(char prmM[][33]){
	int i,j;
	for(i=0;i<=8;i++){
		for(j=0;j<=32;j++){
			printf("%c",prmM[i][j]);
		}
		switch(i){
				case 0:
					printf("      ****CUADRO DE REFERENCIA****");
					break;
				case 1:
					printf("        Peon= p   //   Alfil=a");
					break;
				case 2:
					printf("        Torre= t  \\\\   Caballo=c");
					break;
				case 3:
					printf("        Rey= r    //  Dama=d");
					break;
				case 5:
					printf("        blanco= b //  negro=n");
					break;
				defult:
					break;}
		printf("\n");
	}
}
