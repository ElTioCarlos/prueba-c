#include <stdio.h>

typedef char string[50];

typedef struct{
	int dni;
	int codCarrera;
	char codGenero;
	int edad;
}tDatosAlumno;

void inicializarProceso();
void mostrarAlumnos();
void finalizarProceso();

tDatosAlumno alumno;
FILE * archivoFacena;

int main(){
	inicializarProceso();
	mostrarAlumnos();
	finalizarProceso();
	return 0;
}

void inicializarProceso(){
	archivoFacena = fopen("alumnosFacena.dat", "rb");

}

void mostrarAlumnos(){
	fread(&alumno, sizeof(tDatosAlumno), 1, archivoFacena);
	
	while(!feof(archivoFacena)){
		printf("\n-----alumno-----\n");
		printf("%d", alumno.dni);
		printf("\n");
		printf("%d", alumno.edad);
		printf("\n");
		printf("%d", alumno.codCarrera);
		printf("\n");
		printf("%c", alumno.codGenero);
		
		fread(&alumno, sizeof(tDatosAlumno), 1, archivoFacena);
	}
}

void finalizarProceso(){
	fclose(archivoFacena);
}

