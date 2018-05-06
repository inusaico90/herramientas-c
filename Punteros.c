//ejemplo cambio
#include <stdio.h>
void cambio (int *a, int *b, int c);
int main (){
	int x, y,z;
	
	x=4;
	y=10;
	z=20;
	cambio(&x,&y,z);
	
	printf("el valor de x es= %i.\ny el valor de y es= %i\nel valor final es= %i",x,y,z);
	
	return 0;
}

void cambio(int *a, int *b, int c){//a = &x y por tanto *a sera lo mismo que x además C, es independiente
	int aux;
	
	aux =*a;
	*a = *b;
	*b = aux;
}
