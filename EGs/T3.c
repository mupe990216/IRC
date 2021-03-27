/*
	Instituto de Educacion Superior Rosario Castellanos
	Programación 
	Muñoz Primero Elías
	Problema: Cosecha de un terreno
*/

#include <stdio.h>
#include <stdlib.h>

int main (void){
	printf("\n\n------ Instituto de Educacion Superior Rosario Castellanos -------\n");
	printf("------ \t\tProgramacion Uno \t\t\t     -----\n");
	printf("------ \t\tMunoz Primero Elias \t\t\t     -----\n");
	printf("------ \t\tProblema: Cosecha de un terreno \t     -----\n");
	printf("------------------------------------------------------------------\n\n");
	//Datos de entrada	
	int Num_Paralelogramos;
	float Base_Terrero, Altura_Terrero, Tiempo_Cosecha;
	//Datos de salida
	int Cant_Reguladores, Cant_Bulbos;
	float Area_Total, Altura_Paralelo, Base_Paralelo, Area_Paralelo, Metros_Tuberia, 
		  Costo_Tuberias, Costo_Reguladores, Costo_Bulbos, Costo_Total, Presupuesto;
	

	//Inicializamos el presupuesto propuesto por el problema
	Presupuesto = 800000.00;

	printf("** Ingrese los siguientes datos de manera prudente,\n tome en cuenta que no existen medidas ni meses negativos.\n\n");

	//Ingresamos Datos de Entrada
	printf("\n Numero de paralelogramos >  ");
	scanf("%d",&Num_Paralelogramos);
	while( (Num_Paralelogramos < 1) || (Num_Paralelogramos % 4 != 0) ){
		printf("\n *** Valor no permitido ***");
		printf("\n *** Solo se permiten valores positivos y multiplos de cuatro ***");
		printf("\n Numero de paralelogramos >  ");
		scanf("%d",&Num_Paralelogramos);
	}	

	printf("\n Base Terreno (metros)    >  ");
	scanf("%f",&Base_Terrero);
	while( Base_Terrero < 0.0001 ){
		printf("\n *** Valor no permitido ***");
		printf("\n *** Solo se permiten valores positivos ***");
		printf("\n Base Terreno (metros)    >  ");
		scanf("%f",&Base_Terrero);
	}

	printf("\n Altura Terreno (metros)  >  ");
	scanf("%f",&Altura_Terrero);
	while( Altura_Terrero < 0.0001 ){
		printf("\n *** Valor no permitido ***");
		printf("\n *** Solo se permiten valores positivos ***");
		printf("\n Altura Terreno (metros)  >  ");
		scanf("%f",&Altura_Terrero);
	}

	printf("\n Tiempo Cosecha (meses)   >  ");
	scanf("%f",&Tiempo_Cosecha);
	while( Tiempo_Cosecha < 0.0001 ){
		printf("\n *** Valor no permitido ***");
		printf("\n *** Solo se permiten valores positivos ***");
		printf("\n Tiempo Cosecha (meses)   >  ");
		scanf("%f",&Tiempo_Cosecha);
	}	

	//Procesamos Datos de entrada y calculamos nuevos datos
	Area_Total = (Base_Terrero)*(Altura_Terrero);
	Altura_Paralelo = (Altura_Terrero)/( ((float)Num_Paralelogramos) /2);
	Base_Paralelo = (Base_Terrero)/( ((float)Num_Paralelogramos) /2);
	Area_Paralelo = (Altura_Paralelo)*(Base_Paralelo);
	Metros_Tuberia = (2)*(Area_Total);
	Cant_Reguladores = (2)*(Area_Total);
	Cant_Bulbos = (Tiempo_Cosecha/3)*(10)*(Area_Total);
	Costo_Tuberias = (Metros_Tuberia)*(100);
	Costo_Reguladores = (Cant_Reguladores)*(300);
	Costo_Bulbos = (Cant_Bulbos)*(250);
	Costo_Total = Costo_Tuberias+Costo_Reguladores+Costo_Bulbos;

	
	//Nota: se implementa esta estructura como requisito de las instrucciones	
	int factible;
	do
	{
		if(Costo_Total<=Presupuesto){
			printf("\n\t ====== Con base en el presupuesto el proyecto es factible ====== \n");
			factible=1;
		}
		else{
			printf("\n\t ====== Con base en el presupuesto el proyecto es no factible ====== \n");
			factible=0;
		}
		break;
	} while (1);

	if(factible==1){
		//Una vez validados los datos de entrada y sus calculos se despliega el menu
		int opc;
		for(;;){
			printf("\n Con base en el siguiente menu elija la opcion deseada: \n");
			printf("\n 1) Metros cuadrados de cada paralelogramo.");
			printf("\n 2) Metros cuadrados de todo el terreno.");
			printf("\n 3) Metros de tuberia necesarios.");
			printf("\n 4) Cantidad de reguladores necesarios.");
			printf("\n 5) Cantidad de bulbos necesarios.");
			printf("\n 6) Costo de tuberias.");
			printf("\n 7) Costo de reguladores.");
			printf("\n 8) Costo de bulbos.");
			printf("\n 9) Costo total.");
			printf("\n 10) Salir.");
			printf("\n Ingrese una opcion (numero) > ");
			scanf("%d",&opc);

			while( (opc<1) || (opc>10) ){
				printf("\n *** Opcion no valida, solo se aceptan numeros enteros del siguiente rango: 1-10 \n");
				printf("\n Ingrese una opcion (numero) > ");
				scanf("%d",&opc);
			}

			//Imprimimos Datos de salida
			switch (opc){
				case 1:
					printf("\n\t =======================================================");
					printf("\n\t Altura de cada paralelogramo >  %.2f (metros)",Altura_Paralelo);
					printf("\n\t Base de cada paralelogramo   >  %.2f (metros)",Base_Paralelo);
					printf("\n\t Area de cada paralelogramo   >  %.2f (metros^2)",Area_Paralelo);
					printf("\n\t =======================================================");
					break;
				case 2:
					printf("\n\t =======================================================");
					printf("\n\t Area total del terreno       >  %.2f (metros^2)",Area_Total);
					printf("\n\t =======================================================");
					break;
				case 3:
					printf("\n\t =======================================================");
					printf("\n\t Metros de tuberia            >  %.2f (metros)",Metros_Tuberia);
					printf("\n\t =======================================================");
					break;
				case 4:
					printf("\n\t =======================================================");
					printf("\n\t Cantidad de reguladores      >  %d   (piezas)",Cant_Reguladores);
					printf("\n\t =======================================================");
					break;
				case 5:
					printf("\n\t =======================================================");
					printf("\n\t Cantidad de bulbos           >  %d   (piezas)",Cant_Bulbos);
					printf("\n\t =======================================================");
					break;
				case 6:
					printf("\n\t =======================================================");
					printf("\n\t Costo de tuberia             >  $%.2f (mxn)",Costo_Tuberias);
					printf("\n\t =======================================================");				
					break;
				case 7:
					printf("\n\t =======================================================");				
					printf("\n\t Costo de reguladores         >  $%.2f (mxn)",Costo_Reguladores);
					printf("\n\t =======================================================");				
					break;
				case 8:
					printf("\n\t =======================================================");				
					printf("\n\t Costo de bulbos              >  $%.2f (mxn)",Costo_Bulbos);
					printf("\n\t =======================================================");				
					break;
				case 9:
					printf("\n\t =======================================================");				
					printf("\n\t Costo total                  >  $%.2f (mxn)",Costo_Total);
					printf("\n\t =======================================================");				
					break;
				case 10:
					printf("\n Adios. \n\n\n");
					exit(0);
					break;
				default:
					perror("\n\n ---- Error en la validacion para el switch ---- \n");
					exit(-1);
					break;
			}	
			printf("\n\n");
		}
	}else{
		printf("\n\n Lo sentimos, como el proyecto ingresado no es factible no podemos mostrarle un menu.\n\n");
		exit(0);
	}		

	return 0;
}