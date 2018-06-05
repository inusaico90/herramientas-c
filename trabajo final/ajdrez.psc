Funcion imprimirTablero ( prmTablero Por Referencia )
	Definir i Como Entero;
	Para i<-0 Hasta 8 Con Paso 1 Hacer
		Escribir Subcadena(prmTablero(i),0,33) Sin Saltar;
		Segun i Hacer
			0:
				escribir "    ******CUADRO DE REFERENCIA******";
			1:
				Escribir "       Peon= p\t//\tAlfil=a";
			2:
				escribir"       Torre= t\t\\\\\tCaballo=c";
			3:
				Escribir"       Rey= r\t//\tDama=d";
			4:
				Escribir "       blanco= b\t\\\\\tnegro=n";
			5:
				Escribir "    ************INSTRUCCIONES************";
			6:
				Escribir "       >A quien corresponda el turno ingresera primero la ubicación que quiere";
			7:
				Escribir "        mover (ej:b2) y después la ubicación a donde lo quieres mover(ej:b3)";
			8:
				Escribir "        >Escribe gua, para guardar la partida, sal para cancelar partida y ren para rendirce";
			De Otro Modo:
				Escribir "KEVIN PARGERLA ES";
		Fin Segun
	Fin Para
Fin Funcion

Funcion inicializar ( prmTablero Por Referencia)
	Definir i,j Como Entero;
	Para i<-0 Hasta 8 Con Paso 1 Hacer
		Segun i Hacer
			0:
				prmTablero(i)="[tn][cn][an][rn][dn][an][cn][tn]8";
			1:
				prmTablero(i)="[pn][pn][pn][pn][pn][pn][pn][pn]7";
			2:
				prmTablero(i)="[  ][  ][  ][  ][  ][  ][  ][  ]6";
			3:
				prmTablero(i)="[  ][  ][  ][  ][  ][  ][  ][  ]5";
			4:
				prmTablero(i)="[  ][  ][  ][  ][  ][  ][  ][  ]4";
			5:
				prmTablero(i)="[  ][  ][  ][  ][  ][  ][  ][  ]3";
			6:
				prmTablero(i)="[pb][pb][pb][pb][pb][pb][pb][pb]2";
			7:
				prmTablero(i)="[tb][cb][ab][db][rb][ab][cb][tb]1";
			8:
				prmTablero(i)=" a   b   c   d   e   f   g   h ";
			De Otro Modo:
				Escribir "error inesperado";
		Fin Segun
	Fin Para
Fin Funcion
Funcion mover(prmTablero Por Referencia)
	Definir temp como caracter;
	escribir "Jugador elije la ficha a mover:";
	Leer temp;
FinFuncion

Algoritmo ajedrez
	Definir tablero como texto;Definir varJugador Como Logico;
	Dimension tablero(9);
	inicializar(tablero);
	imprimirTablero(tablero);
	mover(tablero);
	
FinAlgoritmo
