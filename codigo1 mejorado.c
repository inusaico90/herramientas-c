//usar matrices
/*
NOMBRE DEL PROGRAMA: CODIGO1-mejorado
NOMBRE ESTUDIANTE: Kevin Erney Acosta Llano
CÓDIGO ESTUDIANTE: 104618011480
CORREO INSTITUCIONAL: erneylla@unicauca.edu.co
*/
#include <stdio.h>
#include <math.h>
void calcular();
int main(){
	int varEmpresa=7;
	int varTrabajadores[]=150;
	int i,x,varCTN,varSNM,varNE,varNEm,varNHTM,varSBM,varGana;
	
	varCTN=0;
	varNE=160;
	while(varNEm>7){
		printf("Por favor ingrese cuantas empresas quiere calcular (maxmimo 7): ");
		scanf("%i",&varNEm);
	}
	void calcular(varNEm);
}

void calcular (int prmNEm){
	for(i=0;i<=prmNEm-1;i=i+1){
		
		while(varNE>150){
		printf("Por favor ingrese cuantos trabajadores de la empresa quiere calcular (maxmimo 150): ");
		scanf("%i",&varNE);}
		
		for(x=0;x<=prmNE-1;x=x+1){
			printf("\nPor favor ingrese cuantas horas laboro el trabajador: %i en la empresa N: %i\n", x+1,i+1);
			scanf("%i",&varTrabajadores[x]);
			printf("\nPor favor ingrese cuanto gana por hora el trabajador: %i en la empresa N: %i\n", x+1,i+1);
			varSBM = varTrabajadores[x]*varGana;
			varSNM=varSBM-((varSBM*0.05)+(varSBM*0.03));
			varCTN= varCTN + varSNM;
			void imprimir(varSBM,varSNM);
		};
		printf("El CNT de la empresa %i es de: %i\n\n",i+1,varCTN);
	};
}

void imprimir (int prmSBM,int prmSNM]){
	printf("El SBM del empleado es: %i\n",prmSBM);
	printf("El SNM del empleado es: %i\n",prmSNM);
	printf("\n\n");
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
