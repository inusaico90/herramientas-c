/*
NOMBRE DEL PROGRAMA: CODIGO1
NOMBRE ESTUDIANTE: Kevin Erney Acosta Llano
CÓDIGO ESTUDIANTE: 104618011480
CORREO INSTITUCIONAL: erneylla@unicauca.edu.co
*/
#include <stdio.h>
#include <math.h>
int main(){
	int varEmpresa[7];
	int varTrabajadores[150];
	int i,x,varCTN,varSNM,varNE,varNEm,varNHTM,varSBM;
	
	varCTN=0;
	//Esta sección anexa es realizada con el fin de facilitar la prueba de escritorio sin realizar mayores modificaciones modificaciones
		while(varNEm>7){
		printf("Por favor ingrese cuantas empresas quiere calcular (maxmimo 7): ");
		scanf("%i",&varNEm);
		}
		//Fin del anexo
	for(i=0;i<=varNEm-1;i=i+1){
		//Esta sección anexa es realizada con el fin de facilitar la prueba de escritorio sin realizar mayores modificaciones modificaciones
		varNE=160;
		while(varNE>150){
		printf("Por favor ingrese cuantos trabajadores de la empresa quiere calcular (maxmimo 150): ");
		scanf("%i",&varNE);
	}
		//Fin del anexo
		for(x=0;x<=varNE-1;x=x+1){
			printf("\nPor favor ingrese cuantas horas laboro el trabajador: %i en la empresa N: %i\n", x+1,i+1);
			scanf("%i",&varTrabajadores[x]);
			varSBM = varTrabajadores[x]*750000;
			printf("El SBM del empleado es: %i\n",varSBM);
			varSNM=varSBM-((varSBM*0.05)+(varSBM*0.03));
			printf("El SNM del empleado es: %i\n",varSNM);
			varCTN= varCTN + varSNM;
		};
		/*system("clear");
		system("cls");*/
		printf("El CNT de la empresa %i es de: %i\n\n",i+1,varCTN);
	};
}
/*PRUEBA DE ESCRITORIO:
	NEm:3
	EMPRESA 1:							EMPRESA 2:								EMPRESA 3:
	Trabajadores a calcular:3			Trabajadores a calcular:3				Trabajadores a calcular:3
		trabajadro 1:						trabajadro 1:							trabajadro 1:
			HORAS trabajadas:10					HORAS trabajadas:100					HORAS trabajadas:99
			SBM:7500000							SBM:75000000							SBM:74250000
			SNM:6900000							SNM: 69000000							SNM:68310000
		trabajadro 2:						trabajadro 2:							trabajadro 2:
			HORAS trabajadas:20					HORAS trabajadas:200					HORAS trabajadas:80
			SBM: 15000000						SBM:150000000							SBM:60000000
			SNM: 13800000						SNM:138000000							SNM:55200000
		trabajadro 3:						trabajadro 3:							trabajadro 3:
			HORAS trabajadas:40					HORAS trabajadas:0						HORAS trabajadas:9
			SBM:30000000						SBM:0									SBM:6750000
			SNM:27600000						SNM:0									SNM:6210000
			
		CNT1:48300000							CNT2:255300000							CNT3:385020000
*/
