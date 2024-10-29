#include <stdio.h>
#include <stdlib.h>

//creamos la estructura de los datos del alumno
typedef struct{
	int dni;
	int codCarrera;
	char codGenero;
	int edad;
}tDatosAlumno;

void iniciarArchivo();
void grabarAlumno();
void finalizarArchivo();
void ingresarAlumno();


tDatosAlumno alumno;
FILE * archivoFacena;

int main(){
	iniciarArchivo();
	grabarAlumno();
	finalizarArchivo();
	return 0;
}


void iniciarArchivo(){
	archivoFacena = fopen("alumnosFacena.dat", "wb");

	if(archivoFacena == NULL){
		printf("\nError!\n");
		exit(EXIT_FAILURE);
	}else{
		printf("\nArchivo abierto para agregar registros!\n");
	}
}

void grabarAlumno(){
	//funcion para grabar los datos de los alumnos en el archivo alumnosFacena.dat
	char opcion;
	
	printf("\nDesea agregar un alumno?(s/n): ");
	scanf(" %c", &opcion);


	while(opcion == 's' || opcion == 'S'){
		//llamamos a la funcion con el formulario
		ingresarAlumno();
  		
		//guardamos los datos en el archivo
		fwrite(&alumno, sizeof(tDatosAlumno), 1, archivoFacena); 
		printf("\nAlumno agregado!\n");

		//input para continuar con el bucle
		printf("\nDesea ingresar otro alumno?(s/n): ");
		scanf(" %c", &opcion);
	}
}

void finalizarArchivo(){
	fclose(archivoFacena);
	printf("\nCerrando programa!");
}

void ingresarAlumno(){
	//funcion con el formulario de datos del alumno
	printf("\n***Ingreso de alumno***\n");
	
	printf("\nIngrese el DNI: ");
	scanf("%d", &alumno.dni);
	
	printf("\nIngrese el codigo de carrera: ");
	scanf("%d", &alumno.codCarrera);
	
	printf("\nIngrese el codigo de genero: ");
	scanf("%s", &alumno.codGenero);
	
	printf("\nIngrese la edad del alumno: ");
	scanf("%d", &alumno.edad);
}

