// Estructuras-Proyecto1B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime> 

using namespace std;

typedef struct Persona {
	char Nombre;
	int Edad;
	int Cedula;
	Persona* Siguiente;
}*PtrPersona;

void InicializarPadron(PtrPersona& Lista)
{
    Lista = NULL;
}
void DestruirPadron(PtrPersona& Lista)
{
    PtrPersona Aux;
    Aux = Lista;
    while (Aux != NULL)
    {
        Lista = Lista->Siguiente;
        delete(Aux);
        Aux = Lista;
    }
}
PtrPersona CrearPersona(char nNombre, int nEdad, int nCedula)
{
    PtrPersona p = new(Persona);
    char buffer[5];

    p->Nombre = nNombre;
    p->Edad = nEdad;
    p->Cedula = nCedula;

    _itoa_s(nCedula, buffer, 10);

    p->Siguiente = NULL;
    return p;
}
void AgregarInicioPadron(PtrPersona& Lista, PtrPersona& Nuevo)
{
    Nuevo->Siguiente = Lista;
    Lista = Nuevo;
}
void AgregarFinalPadron(PtrPersona& Lista, PtrPersona& Nuevo)
{
    PtrPersona Aux;
    Aux = Lista;
    if (Aux != NULL)
    {
        while (Aux->Siguiente != NULL)
        {
            Aux = Aux->Siguiente;
        }

        Aux->Siguiente = Nuevo;
    }
    else
    {
        Lista = Nuevo;
    }


}
void ListarPadron(PtrPersona& Lista)
{
    int Contador = 1;
    PtrPersona Aux;
    Aux = Lista;
    while (Aux != NULL)
    {
        printf(" %d ", Contador);
        printf("%d ", Aux->Cedula);
        printf("%s ", Aux->Nombre);
        printf(" %f\n ", Aux->Edad);
        Aux = Aux->Siguiente;
        Contador++;
    }
}
PtrPersona BuscarPersona(PtrPersona& Lista, int cual)
{
    return Lista;
}


void GuardarPadron(PtrPersona Lista) {
    FILE* archivo;
    fopen_s(&archivo, "ARCHIVO.txt", "w+");
    if (NULL == archivo) {
        printf("No se pudo abrir el archivo.");
    }
    else {
        PtrTArticulo AUX = Lista;
        while (AUX != NULL) {
            fprintf(archivo, "%i\n", AUX->Cedula);
            fprintf(archivo, "%s\n", AUX->Nombre);
            fprintf(archivo, "%f\n", AUX->Edad);
            AUX = AUX->Siguiente;
        }


    }
    fclose(archivo);
}
void CargarPadron(PtrPersona& Lista) {
    PtrPersona Nuevo;
    FILE* archivo;
    fopen_s(&archivo, "ARCHIVO.txt", "r");
    if (NULL == archivo) {
        printf("No se pudo abrir el archivo");
    }
    else {


        while (!feof(archivo)) {
            Nuevo = new(Persona);
            char Cadena[20];
            fscanf_s(archivo, "%i\n", &Nuevo->Cedula);
            fscanf_s(archivo, "%s\n", Cadena, 20);
            fscanf_s(archivo, "%f\n", &Nuevo->Edad);
            strcpy_s(Nuevo->Nombre, Cadena);
            Nuevo->Siguiente = NULL;
            AgregarFinalPadron(Lista, Nuevo);

        }
    }
    fclose(archivo);
}
void main() {
    unsigned t0, t1;

    t0 = clock();
    // Code to execute
    t1 = clock();

    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
}

