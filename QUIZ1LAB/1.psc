Algoritmo Quiz1Part1
	Definir a,n,i,r,x Como real;
	Leer a,n;
	i<-n;
	r<-1;
	x<-a;
	Mientras i>0 Hacer
		Si (trunc(i)%2)!=0 Entonces
			r<-(r*x);
		Fin Si
		x<-(x*x);
		i<-(i/2); //parte entera
	Fin Mientras
	Escribir r;
	//realizado por Kevin Acosta
FinAlgoritmo
