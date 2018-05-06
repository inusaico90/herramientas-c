Algoritmo Quiz1Part1
	Definir x,i Como Entero;
	Definir esbueno Como Logico;
	esbueno=Falso;
	//1=Verdadero y 0=a falso;
	Leer x;
	Si x%2==0 Entonces
		esbueno=Verdadero;
		Para i<-1 Hasta x Con Paso 1 Hacer
			esbueno<-!esbueno;
		Fin Para
	Fin Si
	Si esbueno==Verdadero Entonces
		Escribir "Bueno";
	SiNo
		Escribir "Malo";
	Fin Si
FinAlgoritmo
