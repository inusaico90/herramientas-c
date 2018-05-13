#include <iostream>
#include <stdlib.h>
#include <locale.h>
using namespace std;
//Declaracion de variables globales
float *estOrden;
//Declaracion de funciones y procedimientos(tam).
void imprimirArreglos(float *arreglo, int tam, string nombre);
void printArreglosE(int *arreglo, int tam, string nombre);
void printArreglosR(float *arreglo, int tam, string nombre);
void regArregloReales(float *arreglo, int tam, string nombre, float val);
void regArregloCaracteres(char *arreglo, int tam, string nombre);
void regArregloEnteros (int *arreglo, int tam, string nombre, int val);
void ordenarPorEstatura (float *arreglo, int tam, float *estOrden);
void buscarPosicionActor (int *arreglo, int tam, int buscarIdentidad, int &pos);
void asignarPeliculaActor (int *arreglo, int pos, int asig, int tam, char *arreglo2, float *arreglo3);
int menu();

int main(int argc, char *argv[]) {
	setlocale(LC_CTYPE,"Spanish");
	//Variables
	bool BANDERA = false, registro = false;
	int opcionE = 0, N = 0, busIdent = 0, posActor = 0, asignada = 0;
	int *identificador, *peliAsignada;
	float *estatura, *puntaje;
	char *idioma;
	
	//Datos de entrada
	
	do{
		opcionE = menu();
		
		switch(opcionE){
		case 1:{
			if(registro == false){
				cout<<"\nDigite el número de actores que desea registrar :\n";
				cin>>N;
				
				cout<<"\n=====Registro de Actores Extra=====\n";
				//Reservar memoria.
				identificador = new int [N];
				estatura = new float [N];
				puntaje = new float [N];
				idioma = new char [N];
				peliAsignada = new int [N];
				
				//Llamado de funciones y procedimientos.
				regArregloEnteros (identificador, N, "Identificación del Extra ", 999999);
				regArregloReales (puntaje, N, "Puntaje del Extra", 0.0);
				regArregloReales (estatura, N, "Estatura del Extra ", 1.71);
				regArregloCaracteres (idioma, N, "Idioma del Extra ");
				
				for(int i = 0; i < N; i++){
					puntaje [i] = 2.0;
				}
				for(int i = 0; i < N; i++){
					peliAsignada [i] = 0;
				}
				registro = true;
			}else{
				cout<<"\nUsted ya registró...\n";
			}
			
			
			break;
		}
		case 2:{
				
				if(registro == true){
					cout<<"\n======Ordenando los Actores Extra======\n";
					estOrden = new float [N];
					ordenarPorEstatura (estatura, N, estOrden);
					imprimirArreglos (estOrden, N, "Estatura del Extra ");
					
					
				}else{
					cout<<"\nDebe hacer primero el registro para poder acceder a esta opcion...\n";
				}
				
				break;
			}
		case 3:{
					if(registro == true){
						cout<<"\n=======Buscar un Actor Extra=======\n";
						cout<<"\nIngrese el numero de identicación del actor al que desea encontrar :\n";
						cin>>busIdent;
						buscarPosicionActor (identificador, N, busIdent, posActor);
						
						if(posActor == -1){
							cout<<"Actor no encontrado";
						}else{
							cout<<"Actor encontrado";
							cout<<"\nIngrese el código de la película\n";
							cin>>asignada;
							asignarPeliculaActor(peliAsignada, posActor, asignada, N, idioma, puntaje);
						}
					}else{
						cout<<"\nDebe hacer primero el registro para poder acceder a esta opción...\n";
					}
					
					break;
				}
		case 4:{
						if(registro == true){
							printArreglosE(identificador, N, "Identificación del actor");
							printArreglosE(peliAsignada, N, "Película asignada del actor");
							printArreglosR(puntaje, N, "Puntaje del actor");
						}else{
							cout<<"\nDebe hacer primero el registro para poder acceder a esta opción...\n";
						}
						break;
					}
		case 5:{
							BANDERA = true;
							break;
						}
		default:{
								cout<<"opcion no valida......\n";
								break;
							}
							
		}
		system("PAUSE");
		system("CLS");
	}while(BANDERA == false);
	
	delete [] identificador;
	delete [] peliAsignada;
	delete [] estatura;
	delete [] puntaje;
	delete [] idioma;
	//Proceso
	
	//Datos de salida
	
	return 0;
}

//Implementacion de funciones y procedimientos
int menu(){
	int opcion = 0;
	
	cout<<"\n=======PIXAR ANIMATION STUDIOS========\n";
	cout<<"\n 1. Registro. \n 2. Ordenar. \n 3. Buscar. \n 4. Informe. \n 5. SALIR.\n";
	cout<<"Digite la opcion: \n";
	cin>>opcion;
	return opcion;
}

void imprimirArreglos(float *arreglo, int tam, string nombre){
	cout<<"\n---------"<<nombre<<"------------\n";
	for(int k = 0; k<tam; k++){
		cout<<nombre<<"["<<k+1<<"]="<<arreglo[k]<<endl;
	}
	cout<<"\n----------------------------\n";
}

void printArreglosE(int *arreglo, int tam, string nombre){
	for(int k = 0; k<tam; k++){
		cout<<nombre<<"["<<k+1<<"]="<<arreglo[k]<<endl;
	}
	cout<<"\n----------------------------\n";	
}
void printArreglosR(float *arreglo, int tam, string nombre){
	float aux;
	aux=*arreglo;
	cout<<"\n-----------"<<nombre<<"------------\n";
	for ( int k=0; k<tam; k++){
		cout<<nombre<<"["<<k+1<<"]=";
		printf("%.2f",arreglo[k]);
		cout<<"\n------------------------\n";
	}
}
void regArregloReales(float *arreglo, int tam, string nombre, float val){
	float aux = 0;
	cout<<endl;
	for (int k = 0; k<tam; k++){
		cout<<nombre<<"["<<k+1<<"] = \n";
		cin>>aux;
		while(aux <= val){
			cout<<"\nDigite correctamente "<<nombre<<"["<<k+1<<"]:\n";
			cin>>aux;
		}
		arreglo[k] = aux;
	}
	
}

void regArregloCaracteres(char *arreglo, int tam, string nombre){
	char aux=' ';
	cout<<endl;
	cout<<" E -> Español. \n I -> Inglés. \n F -> Francés. \n P -> Portugués. \n";
	
	for ( int k=0; k<tam; k++){
		cout<<nombre<<"["<<k+1<<"]="<<endl;
		cin>>aux;
		while (aux != 'E' && aux != 'I' && aux != 'F' && aux != 'P'){
			cout<<"Digite correctamente "<<nombre<<"["<<k+1<<"] ="<<endl;
			cin>>aux;
		}
		
		arreglo[k]= aux;
	}
	cout<<"\n ----------------------------\n";
}
void regArregloEnteros (int *arreglo, int tam, string nombre, int val){
	int aux = 0;
	cout<<endl;
	for (int k = 0; k<tam; k++){
		cout<<nombre<<"["<<k+1<<"] = \n";
		cin>>aux;
		while(aux<=val){
			cout<<"Digite correctamente "<<nombre<<"["<<k+1<<"] = \n";
			cin>>aux;
		}
		arreglo [k] = aux;
	}
}

void ordenarPorEstatura (float *arreglo, int tam, float *estOrden){
	cout<<endl;
	float aux = 0;
	for (int i = 0; i<tam; i++){
		estOrden [i]= arreglo [i];
	}
	
	for(int k=0; k<tam; k++){
		for(int n=k+1; n<tam; n++){
			if(estOrden[n]<estOrden[k]){
				aux = estOrden[k];
				estOrden[k] = estOrden[n];
				estOrden [n] = aux;
			}
		}
	}
}

void buscarPosicionActor (int *arreglo, int tam, int buscarIdentidad, int &pos){
	for(int i=0; i<tam; i++){
		if (buscarIdentidad == arreglo[i]){
			pos = i;
			break;
		}else{
			pos = -1;
		}
	}
}

void asignarPeliculaActor (int *arreglo, int posActor, int asig, int tam, char *arreglo2, float *arreglo3){	
	float aux = 0.0;
	aux=arreglo3[posActor];
	if(arreglo[posActor] == 0){
		arreglo [posActor] = asig;
		cout<<"\nPelícula asignada\n";
		if(arreglo2[posActor]=='F' || arreglo2[posActor]=='P'){
			arreglo3[posActor]=arreglo3[posActor]+0.2;
		}else{
			arreglo3[posActor]=arreglo3[posActor]+0.5;
		}
		
	}else{
		cout<<"\nUsted ya asignó una película para el actor\n";
	}
	arreglo[posActor]=asig;
	switch(arreglo2[posActor]){
	case 'F':{
		aux = aux + 0.2;
		break;
	}
	case 'P':{
			aux = aux + 0.2;
			break;
		}
	case 'I':{
			aux = aux + 0.5;
			break;
			}
	case 'E':{
			aux = aux + 0.5;
			break;
				}
	}
	arreglo3[posActor]=aux;
	aux = 0.0;
}
