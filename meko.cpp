#include <windows.h>
#include <iostream>
#include <locale.h>//Librearía para leer ñ y acentos

char Texto1[100], Texto2[100], Texto3[100];

void Concatenar()
{ int i, k;
  for(i=0; Texto1[i]!=0; i++)
    Texto3[i] = Texto1[i];
  Texto3[i] = 32; i++;
  for(k=0; Texto2[k]!=0; k++)
    Texto3[i+k] = Texto2[k];
  Texto3[i+k] = 0;
}

void Inicio(int p, int x)
{ int l=0, i, t=0;
  while(Texto1[l]!=0)
    l++;
  for(i=l+x; i>=p+x; i--)
    Texto1[i] = Texto1[i-x];
  for(i=0; i<p+x; i++)
    { Texto1[i] =  Texto2[t];
    t++; 
  }
}

void Insertar(int p, int x)
{ int l=0, i, t=0;
  while(Texto1[l]!=0)
    l++;
  for(i=l+x; i>=p+x; i--)
    Texto1[i] = Texto1[i-x];
  for(i=p; i<p+x; i++)
  { Texto1[i] =  Texto2[t];
    t++; 
  }
}

void Extraer(int x)
{ int l=0, i, t=0;
  while(Texto1[l]!=0)
    l++;
  for(i=l-x; i<l; i++)
  { Texto3[t] = Texto1[i];
    t++; 
  }
  Texto3[t]=0;
}

main(){
	setlocale(LC_CTYPE,"Spanish");//Linea para leer ñ y acentos 
	int op, p, n;
	printf("Ingrese la cadena 1: ");
	scanf("%s", &Texto1);
	printf("Ingrese la cadena 2: ");
  	scanf("%s", &Texto2);
  	menu:
  	system("cls");
	printf("Texto1: %s\n", Texto1);
    printf("Texto2: %s\n", Texto2);
    printf("Texto3: %s\n", Texto3);
    printf("\nPROGRAMA CADENAS\n\n");
    printf("1. Concatenar 2 cadenas\n");
    printf("2. Insertar al inicio\n");
    printf("3. Insertar en medio\n");
    printf("4. Insertar al final\n");
    printf("5. Extraer desde el inicio\n");
    printf("6. Extraer desde el medio\n");
    printf("7. Extraer desde el final\n");
    printf("8. Salir\n");
    printf("Ingrese su Opcion: \n"); scanf("%d", &op);
    switch(op){
		case 1:
        	Concatenar();
        	goto menu;
        	break;
		case 2:
        	Insertar(p,n);
        	goto menu;
        	break;
		case 3:
        	printf("Ingrese la posicion de insercion: ");
        	scanf("%d", &p);
        	printf("Ingrese la cantidad de caracteres: ");
        	scanf("%d", &n);
        	Insertar(p, n);
        	goto menu;
        	break;
    	case 7:
        	printf("Ingrese la cantidad de caracteres a extraer: ");
        	scanf("%d", &n);
        	Extraer(n);
        	goto menu;
        	break;
        case 8:
        	goto fin;
        	break;
        default:
        	printf("Opción no valida\n");
        	system("pause");
        	goto menu;
        	break;
    }
    fin:
    	printf("Fin del proceso");
}
