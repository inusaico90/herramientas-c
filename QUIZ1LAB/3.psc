Algoritmo Quiz1Part3
	Definir a,n,i,r,x Como Real;
	Leer a,n;
	i<-n;
	r<-1;
	x<-a;
	Repetir
		Si (i%2)!=0 Entonces
			r<-r*x;
		Fin Si
		x<-(x*x);
		i<-trunc(i/2);
	Hasta Que i=0
	Escribir r;
FinAlgoritmo
