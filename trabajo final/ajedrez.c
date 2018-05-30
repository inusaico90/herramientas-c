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
#endif // __APPLE__

char mesa[9][33];
char varJugador1[4];
char varJugador2[4];
bool varJugador=true;
bool varPartida=true;

void tablero();
void validar_mover(char *,char *);
void inicializarVar();
void mover(char *);
void ubicacion(char *,int *,int *,bool,int *,int * ,bool *);

int main(){
	inicializarVar();
	setlocale(LC_CTYPE,"Spanish");
	int varOpcion;
	varOpcion=2;
	strcat(mesa[0],"[tn][cn][an][rn][dn][an][cn][tn]8");
	strcat(mesa[1],"[pn][pn][pn][pn][pn][pn][pn][pn]7");
	for (varOpcion=2;varOpcion<=6;varOpcion++){
		strcat(mesa[varOpcion],"[  ][  ][  ][  ][  ][  ][  ][  ]");
		mesa[varOpcion][32]=56-varOpcion;
	}
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
	do{
	if(varJugador){
		validar_mover("1(blanca)",varJugador1);}
	else{
		validar_mover("2(negra)",varJugador2);}
	}while(varPartida);
	fin:;
	printf("////////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////Gracias por elegirnos, te esperamos pronto para otra partida.\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
}
void inicializarVar(){
	int varContador;
	for(varContador=0;varContador==8;varContador++){
		strcat(mesa[varContador],"");
	}
	strcat(varJugador1,"");
	strcat(varJugador2,"");
}
void validar_mover(char prmColor[],char prmJugador[4]){
		printf("Jugador %s elije la ficha a mover:\n",prmColor);
		scanf("%s",prmJugador);
		mover(prmJugador);
		varJugador=!varJugador;
}
void mover(char *prmJugador){
	int varx=-1,varY=-1,auxx,auxy;
	char varAux[2];
	bool varEsValido;varEsValido=false;
	ubicacion(prmJugador,&varx,&varY,true,&auxx,&auxy,&varEsValido);
	printf("Haz elejido el %c%c\n",mesa[varY][varx],mesa[varY][varx+1]);
	varAux[0]=mesa[varY][varx];varAux[1]=mesa[varY][varx+1];
	segundo:
	printf("Elije en donde quieres poner la ficha\n");
	scanf("%s",prmJugador);
	ubicacion(prmJugador,&varx,&varY,false,&auxx,&auxy,&varEsValido);
	if (varEsValido){
	mesa[varY][varx]=varAux[0];
	mesa[varY][varx+1]=varAux[1];}
	tablero(mesa);
}
void ubicacion(char *prmJugador,int *prmx,int *prmy,bool prmMov,int *prmauxx,int *prmauxy,bool *prmEsValido){
	char aux[2];
	strcat(aux,"");
	if(!prmMov){
		aux[0]=mesa[*prmy][*prmx];
		aux[1]=mesa[*prmy][*prmx+1];
		mesa[*prmy][*prmx]=' ';
		mesa[*prmy][*prmx+1]=' ';
		}
	switch(prmJugador[0]){
		case 'a':
			*prmx=1;
			break;
		case 'b':
			*prmx=5;
			break;
		case 'c':
			*prmx=9;
			break;
		case 'd':
			*prmx=13;
			break;
		case 'e':
			*prmx=17;
			break;
		case 'f':
			*prmx=21;
			break;
		case 'g':
			*prmx=25;
			break;
		case 'h':
			*prmx=29;
			break;
		default:
			mesa[*prmauxy][*prmauxx]=aux[0];
			printf("Letra invalida");
			break;
	}
	switch(prmJugador[1]){
		case '1':
			*prmy=7;
			break;
		case '2':
			*prmy=6;
			break;
		case '3':
			*prmy=5;
			break;
		case '4':
			*prmy=4;
			break;
		case '5':
			*prmy=3;
			break;
		case '6':
			*prmy=2;
			break;
		case '7':
			*prmy=1;
			break;
		case '8':
			*prmy=0;
			break;
		default:
			mesa[*prmauxy][*prmauxx]=aux[0];
			mesa[*prmauxy][*prmauxx+1]=aux[1];
			printf("%c: n�mero no valido\n",prmJugador[1]);
			break;
	}
	if((varJugador&&mesa[*prmy][*prmx+1]=='n')||(!varJugador&&mesa[*prmy][*prmx+1]=='b') ){
		goto parte2;
	}
	if(*prmx==-1||*prmy==-1||((mesa[*prmy][*prmx]==' ')*prmMov)||((mesa[*prmy][*prmx]!=' ')*(!prmMov))){
		parte2:
		printf("Selecciona una opci�n valida\n");
		if (!prmEsValido){
			mesa[*prmauxy][*prmauxx]=aux[0];
			mesa[*prmauxy][*prmauxx+1]=aux[1];
		}
		*prmEsValido=false;
		if(varJugador){
			validar_mover("1(blanca)",varJugador1);
		}
		else{
			validar_mover("2(negra)",varJugador2);
		}
	}
	else{
		if(prmMov){
		*prmEsValido=true;
		*prmauxx=*prmx;
		*prmauxy=*prmy;
		}
	}
}
void tablero(char prmM[][33]){
	system(LIMPIAR);
	int i,j;
	for(i=0;i<=8;i++){
		for(j=0;j<=32;j++){
			printf("%c",prmM[i][j]);
		}
		switch(i){
				case 0:
					printf("\t******CUADRO DE REFERENCIA******");
					break;
				case 1:
					printf("\t   Peon= p\t//\tAlfil=a");
					break;
				case 2:
					printf("\t   Torre= t\t\\\\\tCaballo=c");
					break;
				case 3:
					printf("\t   Rey= r\t//\tDama=d");
					break;
				case 4:
					printf("\t   blanco= b\t\\\\\tnegro=n");
					break;
				case 5:
					printf("\t************INSTRUCCIONES************");
					break;
				case 6:
					printf("\t   >A quien corresponda el turno ingresera primero la ubicaci�n que quiere");
					break;
				case 7:
					printf("\t    mover (ej:b2) y despu�s la ubicaci�n a donde lo quieres mover(ej:b3)");
				break;
				defult:
					break;}
		printf("\n");
	}
}
