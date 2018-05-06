Algoritmo Parcial1_Part2
	//Adivina_Numero
	Definir intentos, num_secreto, varMax_num,num_ingresado,VarIntentos Como Entero;
	varMax_num<-0;
	intentos<-0;
	Mientras intentos>20 | intentos<10 Hacer
		escribir "¿Cuantos intentos quieres tener: (debe ser entre 10 y 20)";
		Leer intentos;
	Fin Mientras
	VarIntentos<-intentos;
	Mientras varMax_num<100 Hacer
		Escribir "¿Cual es el numero que quieres como tope?(tiene que ser mayor a 99)";
		Leer varMax_num;
	Fin Mientras
	num_secreto<-azar(varMax_num)+1;
	Escribir "Adivine el numero de 1 a ",varMax_num;
	Leer num_ingresado;
	Mientras num_secreto!=num_ingresado & intentos>1 hacer
		si num_secreto>num_ingresado Entonces
			Escribir "Muy bajo";
		SiNo
			Escribir "Muy alto";
		FinSi
		intentos<-intentos-1;
		Escribir "Le quedan ", intentos, " intentos";
		Leer num_ingresado;
	FinMientras
	si num_secreto==num_ingresado Entonces
		Escribir "EXACTO!! En ",VarIntentos-intentos, " intentos";
	SiNo
		Escribir "Mal, el número era: ", num_secreto;
	FinSi
FinAlgoritmo
