// Estructuras-Proyecto1B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef struct Persona {
	char Nombre;
	int Edad;
	int Cedula;
	Persona* Siguiente;
}*PtrPersona;

