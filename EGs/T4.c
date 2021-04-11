/*
	Instituto de Educacion Superior Rosario Castellanos
	Programación 
	Muñoz Primero Elías
	Problema: Cosecha de un terreno con estructuras
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Estructura_cosecha{
	//Datos de entrada		
	float Base_Terrero, Altura_Terrero, Tiempo_Cosecha;
	//Datos de salida
	int Num_Paralelogramos,Cant_Reguladores, Cant_Bulbos;
	float Area_Total, Altura_Paralelo, Base_Paralelo, Area_Paralelo, Metros_Tuberia, 
	Costo_Tuberias, Costo_Reguladores, Costo_Bulbos, Costo_Total, Presupuesto;
}cosecha;

void ingresa_Datos(cosecha *ptr);
void muestra_Datos(cosecha *ptr);
void calcula_Datos(cosecha *ptr);

int main (void){
	printf("\n\n------ Instituto de Educacion Superior Rosario Castellanos -------\n");
	printf("------ \t\tProgramacion Uno \t\t\t     -----\n");
	printf("------ \t\tMunoz Primero Elias \t\t\t     -----\n");
	printf("------ \t\tProblema: Cosecha de un terreno \t     -----\n");
	printf("------------------------------------------------------------------\n\n");
	short int opc;
	printf(" Numero de terrenos a calcular: >  ");
	scanf("%d",&opc);
	cosecha Arreglo_cosecha[opc],*ptr_cosecha;
	//ptr_cosecha->Num_Paralelogramos = opc;
	
	for(ptr_cosecha = &Arreglo_cosecha[0]; ptr_cosecha < &Arreglo_cosecha[opc] ; ptr_cosecha+=1){
		printf("\n *************************** Cosecha %d ***************************",(ptr_cosecha-&Arreglo_cosecha[0])+1);		
		ingresa_Datos(ptr_cosecha);
		calcula_Datos(ptr_cosecha);
		muestra_Datos(ptr_cosecha);
	}

	return 0;
}
/*
	Funcion ingresa_Datos: Encargada de solicitar los datos de entrada del problema
	Entradas: Se le ingresa un apuntador del tipo cosecha
	Salidas: Void - No regresa ningun dato
*/
void ingresa_Datos(cosecha *ptr){
	//Inicializamos presupuesto y paralelogramos propuestos por el problema
	ptr->Presupuesto = 800000.00;
	ptr->Num_Paralelogramos=4;

	//Ingresamos Datos de Entrada	
	printf("\n Base Terreno (metros)    >  ");
	scanf("%f",&ptr->Base_Terrero);

	printf("\n Altura Terreno (metros)  >  ");
	scanf("%f",&ptr->Altura_Terrero);

	printf("\n Tiempo Cosecha (meses)   >  ");
	scanf("%f",&ptr->Tiempo_Cosecha);
}

/*
	Funcion muestra_Datos: Encargada de mostrar los datos del problema
	Entradas: Se le ingresa un apuntador del tipo cosecha
	Salidas: Void - No regresa ningun dato
*/
void muestra_Datos(cosecha *ptr){
	printf("\n\t Altura de cada paralelogramo >  %.2f (metros)",ptr->Altura_Paralelo);
	printf("\n\t Base de cada paralelogramo   >  %.2f (metros)",ptr->Base_Paralelo);
	printf("\n\t Area de cada paralelogramo   >  %.2f (metros^2)",ptr->Area_Paralelo);
	printf("\n\t Area total del terreno       >  %.2f (metros^2)",ptr->Area_Total);
	printf("\n\t Metros de tuberia            >  %.2f (metros)",ptr->Metros_Tuberia);
	printf("\n\t Cantidad de reguladores      >  %d   (piezas)",ptr->Cant_Reguladores);
	printf("\n\t Cantidad de bulbos           >  %d   (piezas)",ptr->Cant_Bulbos);
	printf("\n\t Costo de tuberia             >  $%.2f (mxn)",ptr->Costo_Tuberias);
	printf("\n\t Costo de reguladores         >  $%.2f (mxn)",ptr->Costo_Reguladores);
	printf("\n\t Costo de bulbos              >  $%.2f (mxn)",ptr->Costo_Bulbos);
	printf("\n\t Costo total                  >  $%.2f (mxn)",ptr->Costo_Total);	
	printf("\n\n\t ==================================================== \n\n");	
}

/*
	Funcion calcula_Datos: Encargada de calcular los datos de salida del problema
	Entradas: Se le ingresa un apuntador del tipo cosecha
	Salidas: Void - No regresa ningun dato
*/
void calcula_Datos(cosecha *ptr){
	//Calculamos los datos del problema propuesto	
	ptr->Area_Total = (ptr->Base_Terrero)*(ptr->Altura_Terrero);
	ptr->Altura_Paralelo = (ptr->Altura_Terrero)/( ((float)ptr->Num_Paralelogramos) /2);
	ptr->Base_Paralelo = (ptr->Base_Terrero)/( ((float)ptr->Num_Paralelogramos) /2);
	ptr->Area_Paralelo = (ptr->Altura_Paralelo)*(ptr->Base_Paralelo);
	ptr->Metros_Tuberia = (2)*(ptr->Area_Total);
	ptr->Cant_Reguladores = (2)*(ptr->Area_Total);
	ptr->Cant_Bulbos = (ptr->Tiempo_Cosecha/3)*(10)*(ptr->Area_Total);
	ptr->Costo_Tuberias = (ptr->Metros_Tuberia)*(100);
	ptr->Costo_Reguladores = (ptr->Cant_Reguladores)*(300);
	ptr->Costo_Bulbos = (ptr->Cant_Bulbos)*(250);
	ptr->Costo_Total = (ptr->Costo_Tuberias)+(ptr->Costo_Reguladores)+(ptr->Costo_Bulbos);
	if((ptr->Costo_Total)<=(ptr->Presupuesto))
		printf("\n\t ===== El presupuesto el proyecto SI es factible ===== \n");
	else
		printf("\n\t ===== El presupuesto el proyecto NO es factible ===== \n");
}