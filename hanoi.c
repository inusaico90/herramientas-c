/*Ejercisio que define cuantos son la cantidad minima de movimientos que se pueden realizar
para solucionar el juego de Hanoi con x cantidad de discos definida por el usuario
*/
#include <stdio.h>
int hanoi(int n){
	if (n<=1){
		return 1;
	}
	else {
		return 2 * hanoi(n-1)+1;
	}
}
int main(){
	int disc, mov;
    printf("::TORRES DE HANOI::\n");
    printf("Numero de discos: ");scanf("%i",&disc);
    printf("Movimientos necesarios: %i", hanoi(disc));
    return 0;
}
