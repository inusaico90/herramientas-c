Algoritmo Parcial1_Part1
	//creado por Kevin Acosta
	Definir x,x1,y,y1,z,z1,t,t1 Como Entero;
	t<-0;t1<-0;x<-0;y<-0;z<-0;
	Mientras X<=0 Hacer
		Escribir "x debe ser mayor que 0";
		Leer X;
	Fin Mientras
	Mientras y<=0 Hacer
		Escribir "Y debe ser mayor que 0";
		Leer Y;
	FinMientras
	Mientras z<=0 Hacer
		Escribir "Z tiene que ser mayor que 0";
		Leer z;
	FinMientras
	x1<-x;
	y1<-y;
	z1<-z;
	Si x<y Entonces
		t<-y;
		y<-x;
		x<-t;
	Fin Si
	Mientras y!=0 Hacer
		T1<-x%y;
		x<-y;
		y<-t1;
	Fin Mientras
	Si x<z Entonces
		t<-z;
		z<-x;
		x<-t;
	Fin Si
	Mientras z!=0 Hacer
		t1<-x%z;
		x<-z;
		z<-t1;
	Fin Mientras
	Escribir "el MCD de: ",x1,", ",y1," y ",z1;
	Escribir "es: ",x;
FinAlgoritmo
