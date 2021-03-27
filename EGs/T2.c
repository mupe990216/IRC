/*
	Instituto de Educacion Superior Rosario Castellanos
	Programación Uno
	Muñoz Primero Elías
	Problema: Cosecha de un terreno
*/

#include <stdio.h>

int main (void){
	printf("\n\n------ Instituto de Educacion Superior Rosario Castellanos ------\n");
	printf("------ \t\tProgramacion Uno \t\t\t     -----\n");
	printf("------ \t\tMunoz Primero Elias \t\t\t     -----\n");
	printf("------ \t\tProblema: Cosecha de un terreno \t     -----\n\n");
	//Datos de entrada
	float Num_Paralelogramos, Base_Terrero, Altura_Terrero, Tiempo_Cosecha;
	//Datos de salida
	float Area_Total, Altura_Paralelo, Base_Paralelo, Area_Paralelo, Metros_Tuberia, 
		  Cant_Reguladores, Cant_Bulbos, Costo_Tuberias, Costo_Reguladores, Costo_Bulbos, Costo_Total;

	//Ingresamos Datos de Entrada
	printf("\n Numero de paralelogramos >  ");
	scanf("%f",&Num_Paralelogramos);
	printf("\n Base Terreno (metros)    >  ");
	scanf("%f",&Base_Terrero);
	printf("\n Altura Terreno (metros)  >  ");
	scanf("%f",&Altura_Terrero);
	printf("\n Tiempo Cosecha (meses)   >  ");
	scanf("%f",&Tiempo_Cosecha);
	printf("\n");

	//Procesamos Datos de entrada y calculamos nuevos datos
	Area_Total = (Base_Terrero)*(Altura_Terrero);
	Altura_Paralelo = (Altura_Terrero)/(Num_Paralelogramos/2);
	Base_Paralelo = (Base_Terrero)/(Num_Paralelogramos/2);
	Area_Paralelo = (Altura_Paralelo)*(Base_Paralelo);
	Metros_Tuberia = (2)*(Area_Total);
	Cant_Reguladores = (2)*(Area_Total);
	Cant_Bulbos = (Tiempo_Cosecha/3)*(10)*(Area_Total);
	Costo_Tuberias = (Metros_Tuberia)*(100);
	Costo_Reguladores = (Cant_Reguladores)*(300);
	Costo_Bulbos = (Cant_Bulbos)*(250);
	Costo_Total = Costo_Tuberias+Costo_Reguladores+Costo_Bulbos;

	//Imprimimos Datos de salida
	printf("\n Altura De Cada Paralelogramo >  %.2f(metros)",Altura_Paralelo);
	printf("\n Base De Cada Paralelogramo   >  %.2f(metros)",Base_Paralelo);
	printf("\n Area De Cada Paralelogramo   >  %.2f(metros^2)",Area_Paralelo);
	printf("\n Area Total Del Terreno       >  %.2f(metros^2)",Area_Total);
	printf("\n Metros De Tuberia            >  %.2f(metros)",Metros_Tuberia);
	printf("\n Cantidad De Reguladores      >  %.2f(piezas)",Cant_Reguladores);
	printf("\n Cantidad De Bulbos           >  %.2f(piezas)",Cant_Bulbos);
	printf("\n Costo De Tuberia             >  $%.2f(mxn)",Costo_Tuberias);
	printf("\n Costo De Reguladores         >  $%.2f(mxn)",Costo_Reguladores);
	printf("\n Costo De Bulbos              >  $%.2f(mxn)",Costo_Bulbos);
	printf("\n Costo Total                  >  $%.2f(mxn)",Costo_Total);
	
	printf("\n\n");
	return 0;
}