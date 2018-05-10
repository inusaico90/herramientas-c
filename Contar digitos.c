#include <stdio.h>
#include <stdlib.h>
 /*
 Programa que cuenta los digitos de un numero ingresado
 */
int contarDigitos(int Num){
int Contador, Num2;
        Num2 = Num;
        Contador = 0;
        while(Num != 0){
            Contador++;
            Num=(Num / 10);
        }
    printf("La cantidad de digitos del Numero [%d] es = %d\n",Num2,Contador);
 }
int main(){
int Num;
    printf("Ingresa un numero : ");
    scanf("%d",&Num);
    printf("------\n");
    contarDigitos(Num);
    system("pause");
}
