/*Nombre: ajedrez en C
creador: Kevin Erney Acosta (inusaico90)
version: 0.1.3*/
#include <stdio.h> //standard input-output header
#include <stdlib.h>//Librearia estandar propositos generales
#include <locale.h>//Librearia estandar para el analisis local del sistema
#include <string.h>//Librearia estandar para facilitar el manejo de cadenas de texto
#include <stdbool.h>//Librearia estandar para el manejo de variables logicas
#include <time.h>//Librearia estandar para el analisis del tiempo
//declararción multiplataforma para sysytem("clear")
#ifdef __linux__
#define LIMPIAR "CLEAR"
#endif // __linux__

#ifdef __MINGW32__
#define LIMPIAR "CLS"
#endif // __MINGW32__

#ifdef __APPLE__
#define LIMPIAR "clear"
#endif // __APPLE__
//fin declaración
//Declaración variables globales
char mesa[9][33];
char varJugador1[4];
char varJugador2[4];
bool varJugador=true;
bool varPartida=true;
struct  tm  *timelocal;

//Declaración estructura de las funciones
void reproMenu();
void newJugador();
void tablero();
void validar_mover(char *,char *);
void inicializarVar();
void mover(char *prmJugador,char prmColor[]);
void ubicacion(char *,int *,int *,bool,int *,int * ,bool *,char []);
void guardar();
void cargarTablero();
void vaciar(char temp[]);
void copiar(char temp[],int i);

typedef struct{//Estructura para facilitar la declaración de los FILE
	char lectoEscritura[100];
}ficheros;
int main(){//función principal
	setlocale(LC_CTYPE,"Spanish");//Manejo local para que la consola imprima ñ y tildes
	reproMenu();//Redirección a la ejecución del menu
}
void reproMenu(){//función para ejecutar el menu principal
	int varOpcion;
	ficheros aux;FILE *menu; FILE *jugadores;FILE *juegos;ficheros temp;//Declaración de los file en donde se guardara y trabajara reporte
	secMenu:
	system(LIMPIAR);
	menu=fopen("menu.txt","r");jugadores=fopen("jugadores.txt","r");juegos=fopen("juegos.txt","a+");//Sincronización de los archivos a trabajar	
	while (!feof(menu)){//Imprimir menu principal
		fgets(aux.lectoEscritura,100,menu);
		printf("%s",aux.lectoEscritura);
	}
	printf("\n");
	fclose(menu);//Cierre del Stream
	scanf("%i",&varOpcion);
	system(LIMPIAR);//limpiar pantalla multi plataforma
	switch(varOpcion){//Elección de la opción seleccionada
		case 1:
			//cargarTablero();
			printf("\n\ningresa cualquier valor diferente a %i para salir\n",varOpcion);
			do{
				scanf("%i",&varOpcion);
			}while(varOpcion==1);
			system(LIMPIAR);
			goto secMenu;//Regreso a la impresión del menu
			break;
		case 2:
			//Imprimir contenido de jugadores.txt (listado de jugadores registrados)
			while(!feof(jugadores)){
				fgets(aux.lectoEscritura,100,jugadores);
				printf("%s",aux.lectoEscritura);
			}
			fclose(jugadores);
			//system pause improvisado (multiplataforma)
			printf("\n\ningresa cualquier valor diferente a %i para salir\n",varOpcion);
			do{
				scanf("%i",&varOpcion);
			}while(varOpcion==2);
			system(LIMPIAR);
			goto secMenu;
			break;		//creado por inusaico90 erneyjj@hotmail.es
		case 3:
			while(!feof(juegos)){//Impresión del historial de partidas jugadas
				fgets(aux.lectoEscritura,100,juegos);
				printf("%s",aux.lectoEscritura);
			}
			fclose(juegos);
			printf("\n\ningresa cualquier valor diferente a %i para salir\n",varOpcion);
			do{
				scanf("%i",&varOpcion);
			}while(varOpcion==3);
			system(LIMPIAR);
			goto secMenu;
			break;
		case 4:
			newJugador();//redireccionamiento a la función para crear un nuevo jugador
			system(LIMPIAR);
			goto secMenu;
			break;
		case 5:
			//crear reporte de nueva partida
			varOpcion=0;
			while(!feof(juegos)){//contar cuantos partidas hay registradas
				fgets(temp.lectoEscritura,100,juegos);
				varOpcion++;}
			rewind(juegos);//devuelvo a la posición 0 del txt
			vaciar(temp.lectoEscritura);
			inicializarVar();//rediracción a la inicialización de variables
			fprintf(juegos,"\n");fprintf(juegos,"%i",varOpcion);fprintf(juegos,")\t");//crea el espacio de la nueva partida
			for (varOpcion=0;varOpcion<2;varOpcion++){//leer nombre de los jugadores
				printf("ingresa el nombre del jugador %i\n",varOpcion+1);
				scanf("%s",temp.lectoEscritura);
				fprintf(juegos,temp.lectoEscritura);fprintf(juegos,"\t\t");
			}
			fclose(juegos);
			tablero(mesa);//impresión en pantalla del tablero
			do{//Ciclo para pasar de un jugador al otro
				if(varJugador){
					validar_mover("1(blanca)",varJugador1);
					}
				else{
					validar_mover("2(negra)",varJugador2);
				}
				varJugador=!varJugador;//cambio de estado para permitir el cambio de jugador
			}while(varPartida);
			varPartida=true;
			goto secMenu;
			break;
		case 6:
			goto fin;//Opción de cierre del juego
			break;	
		default:
			printf("Selecciona una opción valida");//caso de contigencia contra la estupidez
			goto secMenu;
			break;
	}
	fin:;
}
void vaciar(char temp[]){//limpia lo que contenga el string
	int i;
	for(i=0;i<100;i++){
		temp[i]='\0';
	}
}
void newJugador(){//Función para la creación de un nuevo jugador
	ficheros aux; ficheros nick;ficheros name;
	//variables para el manejo del tiempo
	char    out_time[128],  d[25];
	time_t tiempo;
	//Fin variables
	FILE *jugador;
	jugador=fopen("jugadores.txt","a");fprintf(jugador,"\n");
	printf("Ingresa el nombre del nuevo jugador\n");
	scanf("%s",name.lectoEscritura);
	fprintf(jugador,name.lectoEscritura);fprintf(jugador,"\t");
	printf("Ingrese el nick del nuevo jugador\n");
	scanf("%s",nick.lectoEscritura);
	fprintf(jugador,nick.lectoEscritura);fprintf(jugador,"\t");
	printf("Ingresa el correo del nuevo jugador\n");
	scanf("%s",nick.lectoEscritura);
	fprintf(jugador,nick.lectoEscritura);fprintf(jugador,"\t\t");
	//capturar fecha y hora además de guardarla en el archivo
	tiempo = time(0);
	timelocal = localtime(&tiempo);
	strftime(out_time, sizeof(out_time), "%d/%m/%y  %H:%M:%S", timelocal);
	fprintf(jugador, "%s", out_time);
	fclose(jugador);
}
void inicializarVar(){//función para inicializar todas la variables
	int varContador;
	for(varContador=0;varContador==8;varContador++){//Ciclo para inicializar la cadena de textos del tablero
		strcat(mesa[varContador],"");
	}
	strcat(varJugador1,"");
	strcat(varJugador2,"");
	int varOpcion;
	//Crear estado base para el tablero
	strcat(mesa[0],"[tn][cn][an][dn][rn][an][cn][tn]8");
	strcat(mesa[1],"[pn][pn][pn][pn][pn][pn][pn][pn]7");
	for (varOpcion=2;varOpcion<=5;varOpcion++){ //"para" que permite ahorrar lineas de codigo en la inicialización de las casillas vacias
		strcat(mesa[varOpcion],"[  ][  ][  ][  ][  ][  ][  ][  ]");
		mesa[varOpcion][32]=56-varOpcion;//manejo del codigo ascii para guardar el número correspondiente
	}
	strcat(mesa[6],"[pb][pb][pb][pb][pb][pb][pb][pb]2");
	strcat(mesa[7],"[tb][cb][ab][db][rb][ab][cb][tb]1");
	strcat(mesa[8]," a   b   c   d   e   f   g   h ");
	//Fin creación
}
void validar_mover(char prmColor[],char prmJugador[4]){//función para empezar movimientos
	printf("Jugador %s elije la ficha a mover:\n",prmColor);//Impresión de a quien le corresponde el turno
	scanf("%s",prmJugador);
	FILE *juegos;juegos=fopen("juegos.txt","a+");int varOpcion;
	if(strcmp(prmJugador,"gua")==0 || strcmp(prmJugador,"sal")==0 || strcmp(prmJugador,"ren")==0){
		if (strcmp(prmJugador,"gua")==0){
			varOpcion=0;
		}
		if (strcmp(prmJugador,"sal")==0){
			varOpcion=1;
		}
		if (strcmp(prmJugador,"ren")==0){
			varOpcion=2;
		}
		switch(varOpcion){
			case 0:
				printf("Guardando juego\n");
				guardar();
				fprintf(juegos,"Juego guardado");
				break;
			case 1:
				printf("cancelando juego");
				fprintf(juegos,"Juego cancelado");
				break;
			case 2:
				printf("Se ha rendido el jugador %s",prmColor);
				if(prmColor[0]=='1'){
					fprintf(juegos,"gana j2");
				}else{
					fprintf(juegos,"gana j1");
				}
				printf("\n\ningresa cualquier valor diferente a %i para salir\n",varOpcion);
				do{
					scanf("%i",&varOpcion);
				}while(varOpcion==2);
				system(LIMPIAR);
				break;
			default:
				printf("el pendejo del programador la cago");
				break;
			}
		fclose(juegos);
		varPartida=false;
		system(LIMPIAR);
	}
	else{
		mover(prmJugador,prmColor);//Redirección a la función para realizar el movimiento
	}
}
void mover(char *prmJugador,char prmColor[]){//función para validar el movimiento
	int varx=-1,varY=-1,auxx,auxy;
	char varAux[2];
	bool varEsValido;varEsValido=false;
	
	FILE *juegos;juegos=fopen("juegos.txt","a+");int varOpcion;
	if(strcmp(prmJugador,"gua")==0 || strcmp(prmJugador,"sal")==0 || strcmp(prmJugador,"ren")==0){
		if (strcmp(prmJugador,"gua")==0){
			varOpcion=0;
		}
		if (strcmp(prmJugador,"sal")==0){
			varOpcion=1;
		}
		if (strcmp(prmJugador,"ren")==0){
			varOpcion=2;
		}
		switch(varOpcion){
			case 0:
				printf("Guardando juego\n");
				guardar();
				break;
			case 1:
				printf("cancelando juego");
				break;
			case 2:
				printf("Se ha rendido el jugador %s",prmColor);
				printf("\n\ningresa cualquier valor diferente a %i para salir\n",varOpcion);
				do{
					scanf("%i",&varOpcion);
				}while(varOpcion==2);
				system(LIMPIAR);
				break;
			default:
				printf("el pendejo del programador la cago");
				break;
			}
		fclose(juegos);
		varPartida=false;
		system(LIMPIAR);
	}
	else{
		ubicacion(prmJugador,&varx,&varY,true,&auxx,&auxy,&varEsValido,prmColor);//confirmación de la ubicación de la ficha
		printf("Haz elejido el %c%c\n",mesa[varY][varx],mesa[varY][varx+1]);
		varAux[0]=mesa[varY][varx];varAux[1]=mesa[varY][varx+1];//creación de copia de la variable en caso de selección final invalida
		printf("Elije en donde quieres poner la ficha\n");
		scanf("%s",prmJugador);
		ubicacion(prmJugador,&varx,&varY,false,&auxx,&auxy,&varEsValido,prmColor);//confirmación de la ubicación a poner
		if (varEsValido){//si es valido el movimiento se guardaran los cambios
			mesa[varY][varx]=varAux[0];
			mesa[varY][varx+1]=varAux[1];}
		tablero(mesa);//impresión del tablero
		}
}
void ubicacion(char *prmJugador,int *prmx,int *prmy,bool prmMov,int *prmauxx,int *prmauxy,bool *prmEsValido, char prmColor[]){//validar ficha de movimiento
	char aux[2];
	strcat(aux,"");
	FILE *juegos;juegos=fopen("juegos.txt","a+");int varOpcion;
	if(strcmp(prmJugador,"gua")==0 || strcmp(prmJugador,"sal")==0 || strcmp(prmJugador,"ren")==0){
		if (strcmp(prmJugador,"gua")==0){
			varOpcion=0;
		}
		if (strcmp(prmJugador,"sal")==0){
			varOpcion=1;
		}
		if (strcmp(prmJugador,"ren")==0){
			varOpcion=2;
		}
		switch(varOpcion){
			case 0:
				printf("Guardando juego\n");
				guardar();
				break;
			case 1:
				printf("cancelando juego");
				break;
			case 2:
				printf("Se ha rendido el jugador %s",prmColor);
				do{
					scanf("%i",&varOpcion);
				}while(varOpcion==2);
				system(LIMPIAR);
				break;
			default:
				printf("el pendejo del programador la cago");
				break;
			}
		fclose(juegos);
		varPartida=false;
		system(LIMPIAR);
	}
	else{
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
				if(!prmEsValido){
					mesa[*prmauxy][*prmauxx]=aux[0];
				}
				printf("Letra invalida\n");
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
				if(!prmEsValido){
					mesa[*prmauxy][*prmauxx]=aux[0];
					mesa[*prmauxy][*prmauxx+1]=aux[1];
				}
				printf("número no valido\n");
				break;
		}
		if((varJugador&&mesa[*prmy][*prmx+1]=='n')||(!varJugador&&mesa[*prmy][*prmx+1]=='b')){
			if(!prmEsValido){
				if((mesa[*prmy][*prmx+1]==mesa[*prmauxy][*prmauxx+1])&&(*prmauxy==-1||*prmauxx==-1)){
					goto parte2;
				}
			}
			else{
				goto conti;
			}
		}
		conti:
		if(aux[1]==mesa[*prmy][*prmx+1]){
			goto parte2;
		}
		else{
			if(!prmMov){
				switch(aux[0]){
					case 'a':
						if((/*cond1*/*prmauxy-1==*prmy&&(*prmauxx+4==*prmx||*prmauxx-4==*prmx)) || (/*cond2*/*prmauxy-2==*prmy&&(*prmauxx+8==*prmx||*prmauxx-8==*prmx)) || (/*cond3*/*prmauxy-3==*prmy&&(*prmauxx+12==*prmx||*prmauxx-12==*prmx)) || (/*cond4*/*prmauxy-4==*prmy&&(*prmauxx+16==*prmx||*prmauxx-16==*prmx)) || (/*cond5*/*prmauxy-5==*prmy&&(*prmauxx+20==*prmx||*prmauxx-20==*prmx)) || (/*cond6*/*prmauxy+1==*prmy&&(*prmauxx+4==*prmx||*prmauxx-4==*prmx)) || (/*cond7*/*prmauxy+2==*prmy&&(*prmauxx+8==*prmx||*prmauxx-8==*prmx)) || (/*cond8*/*prmauxy+3==*prmy&&(*prmauxx+12==*prmx||*prmauxx-12==*prmx)) || (/*cond9*/*prmauxy+4==*prmy&&(*prmauxx+16==*prmx||*prmauxx-16==*prmx)) || (/*cond10*/*prmauxy+5==*prmy&&(*prmauxx+20==*prmx||*prmauxx-20==*prmx))){
							goto parte3;
						}
						else{
							goto parte2;
						}
						break;
					case 'c':
						if( (/*cond1*/*prmauxy-2==*prmy&&(*prmauxx+4==*prmx||*prmauxx-4==*prmx)) || (/*cond2*/*prmauxy-1==*prmy&&(*prmauxx+8==*prmx||*prmauxx-8==*prmx)) || (/*cond3*/*prmauxy+2==*prmy&&(*prmauxx+4==*prmx||*prmauxx-4==*prmx)) || (/*cond4*/*prmauxy+1==*prmy&&(*prmauxx+8==*prmx||*prmauxx-8==*prmx)) ){
							goto parte3;
						}
						else{
							goto parte2;
						}
						break;
					case 't':
						if((/*cond1*/(*prmauxy-1==*prmy||*prmauxy-2==*prmy||*prmauxy-3==*prmy||*prmauxy-4==*prmy||*prmauxy-5==*prmy||*prmauxy-6==*prmy||*prmauxy-7==*prmy)&&*prmauxx==*prmx) || (/*cond2*/(*prmauxx-4==*prmx||*prmauxx-8==*prmx||*prmauxx-12==*prmx||*prmauxx-16==*prmx||*prmauxx-20==*prmx||*prmauxx-24==*prmx||*prmauxx-28==*prmx)&&*prmauxy==*prmy)||((*prmauxy+1==*prmy||*prmauxy+2==*prmy||*prmauxy+3==*prmy||*prmauxy+4==*prmy||*prmauxy+5==*prmy||*prmauxy+6==*prmy||*prmauxy+7==*prmy)&&*prmauxx==*prmx)||((*prmauxx+4==*prmx||*prmauxx+8==*prmx||*prmauxx+12==*prmx||*prmauxy+16==*prmx||*prmauxx+20==*prmx||*prmauxx+24==*prmx||*prmauxx+28==*prmx)&&*prmauxy==*prmy)){
							goto parte3;
						}
						else{
							goto parte2;
						}
						break;
					case 'd':
						if((/*cond1*/*prmauxy-1==*prmy&&(*prmauxx+4==*prmx||*prmauxx-4==*prmx)) || (/*cond2*/*prmauxy-2==*prmy&&(*prmauxx+8==*prmx||*prmauxx-8==*prmx)) || (/*cond3*/*prmauxy-3==*prmy&&(*prmauxx+12==*prmx||*prmauxx-12==*prmx)) || (/*cond4*/*prmauxy-4==*prmy&&(*prmauxx+16==*prmx||*prmauxx-16==*prmx)) || (/*cond5*/*prmauxy-5==*prmy&&(*prmauxx+20==*prmx||*prmauxx-20==*prmx)) || (/*cond6*/*prmauxy+1==*prmy&&(*prmauxx+4==*prmx||*prmauxx-4==*prmx)) || (/*cond7*/*prmauxy+2==*prmy&&(*prmauxx+8==*prmx||*prmauxx-8==*prmx)) || (/*cond8*/*prmauxy+3==*prmy&&(*prmauxx+12==*prmx||*prmauxx-12==*prmx)) || (/*cond9*/*prmauxy+4==*prmy&&(*prmauxx+16==*prmx||*prmauxx-16==*prmx)) || (/*cond10*/*prmauxy+5==*prmy&&(*prmauxx+20==*prmx||*prmauxx-20==*prmx)) || (/*cond11*/(*prmauxy-1==*prmy||*prmauxy-2==*prmy||*prmauxy-3==*prmy||*prmauxy-4==*prmy||*prmauxy-5==*prmy||*prmauxy-6==*prmy||*prmauxy-7==*prmy)&&*prmauxx==*prmx) || (/*cond12*/(*prmauxx-4==*prmx||*prmauxx-8==*prmx||*prmauxx-12==*prmx||*prmauxx-16==*prmx||*prmauxx-20==*prmx||*prmauxx-24==*prmx||*prmauxx-28==*prmx)&&*prmauxy==*prmy)||((*prmauxy+1==*prmy||*prmauxy+2==*prmy||*prmauxy+3==*prmy||*prmauxy+4==*prmy||*prmauxy+5==*prmy||*prmauxy+6==*prmy||*prmauxy+7==*prmy)&&*prmauxx==*prmx)||((*prmauxx+4==*prmx||*prmauxx+8==*prmx||*prmauxx+12==*prmx||*prmauxy+16==*prmx||*prmauxx+20==*prmx||*prmauxx+24==*prmx||*prmauxx+28==*prmx)&&*prmauxy==*prmy)){
							goto parte3;
						}else{
							goto parte2;
						}
						break;
					case 'r':
						if((/*cond1*/*prmauxy-1==*prmy&&*prmauxx==*prmx) || (/*cond2*/*prmauxy-1==*prmy&&(*prmauxx==*prmx+4||*prmauxx==*prmx-4)) || (/*cond3*/*prmauxy+1==*prmy&&*prmauxx==*prmx) || (/*cond4*/*prmauxy+1==*prmy&&(*prmauxx==*prmx+4||*prmauxx==*prmx-4)) || (/*cond5*/*prmauxy==*prmy&&(*prmauxx==*prmx+4||*prmauxx==*prmx-4))){
							goto parte3;
						}else{
							goto parte2;
						}
						break;
					case 'p':
						if(((*prmauxy-1==*prmy&&*prmauxx==*prmx)||(*prmauxy-1==*prmy&&(*prmauxx==*prmx+4||*prmauxx==*prmx-3))&&(prmJugador[0]=='1'))||((*prmauxy+1==*prmy&&*prmauxx==*prmx)||(*prmauxy+1==*prmy&&(*prmauxx==*prmx+4||*prmauxx==*prmx-3))&&(prmJugador[0]=='2'))){
							goto parte3;
						}
						else{
							goto parte2;
						}
						break;
					default:
						break;
				}
			}
		}
		if(*prmx==-1||*prmy==-1 || ((mesa[*prmy][*prmx]==' ')*prmMov)){
			parte2:
			printf("Selecciona una opción valida\n");
			if(prmEsValido){
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
			parte3:
			if(!prmEsValido){
				*prmauxy=-1;
				*prmauxx=-1;
			}
			if(prmMov){
				*prmEsValido=true;
				*prmauxx=*prmx;
				*prmauxy=*prmy;
			}
		}
	}
}
void guardar(){
	int aux,aux2;aux=0;aux2=0;
	FILE *nGuardado;FILE *partida;
	nGuardado=fopen("guardar.txt","w");
	if(nGuardado==NULL){
		printf("Error al abrir el archivo");
		exit(1);
	}
	for(aux=0;aux<9;aux++){//ciclo anidado for que guarda lamatriz de 9 por 33 que corresponde al tablero de juego
		for(aux2=0;aux2<33;aux2++){
			fprintf(nGuardado,"%c",mesa[aux][aux2]);
		}
		if(aux!=8){//condición para evitar una linea extra vacia
			fprintf(nGuardado,"\n");//salto de linea cuando se haya completado la fila
		}
	}
	fclose(nGuardado);
}
void tablero(char prmM[][33]){//imrpimir tablero
	system(LIMPIAR);
	int i,j;
	for(i=0;i<=8;i++){//imprimir Entor grafico
		for(j=0;j<=32;j++){//Imprimir tablero
			printf("%c",prmM[i][j]);
		}
		switch(i){//Imprimir cuadro de ayuda
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
					printf("\t   >A quien corresponda el turno ingresera primero la ubicación que quiere");
					break;
				case 7:
					printf("\t    mover (ej:b2) y después la ubicación a donde lo quieres mover(ej:b3)");
					break;
				case 8:
					printf("\t    >Escribe gua, para guardar el juego, sal para cancelar partida y ren para rendirse");
					break;
				break;
				defult:
					break;}
		printf("\n");
	}
}
/*void cargarTablero(){
	int aux,aux2;aux=0;aux2=0;char temp[33];ficheros varTemp;
	FILE *juego;
	juego=fopen("guardar.txt","r");
	if(juego==NULL){
		printf("Error al abrir el archivo");
	}	
	for (aux=0;!feof(juego);aux++){
		strcat(temp,'0');
		for(aux2=0;temp!='\n';aux2++){
			temp=fgetc(juego);
			if(temp!='\n'){
				varTemp.lectoEscritura[aux2]=temp
			}
		}
		copiar(varTemp.lectoEscritura,aux);
	}
	fclose(nGuardado);
}
/*void copiar(char temp[],int i){
	int N = strlen(temp)+1;
	strcpy(mesa[i],temp);
}*/
