// Estructuras-Proyecto1B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef struct Persona {
	char Nombre;
	int Edad;
	int Cedula;
	Persona* Siguiente;
}*PtrPersona;

void InicializarLista(PtrPersona& Lista)
{
    Lista = NULL;
}
void DestruirLista(PtrPersona& Lista)
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
PtrPersona CrearArticulo(int NCodigo, int NDisponible, float NPrecio)
{
    PtrPersona Pieza = new(Persona);
    char buffer[5];

    Pieza->Codigo = NCodigo;
    Pieza->Disponible = NDisponible;
    Pieza->Precio = NPrecio;

    strcpy_s(Pieza->Nombre, "Pieza");
    _itoa_s(NCodigo, buffer, 10);
    strcat_s(Pieza->Nombre, buffer);

    Pieza->Siguiente = NULL;
    return Pieza;
}
void AgregarInicioInventario(PtrPersona& Lista, PtrPersona& Nuevo)
{
    Nuevo->Siguiente = Lista;
    Lista = Nuevo;
}
void AgregarFinalInventario(PtrPersona& Lista, PtrPersona& Nuevo)
{
    PtrTArticulo Aux;
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
void ListarInventario(PtrPersona& Lista)
{
    int Contador = 1;
    PtrTArticulo Aux;
    Aux = Lista;
    while (Aux != NULL)
    {
        printf(" %d ", Contador);
        printf("%d ", Aux->Codigo);
        printf("%s ", Aux->Nombre);
        printf(" %d ", Aux->Disponible);
        printf(" %f\n ", Aux->Precio);
        Aux = Aux->Siguiente;
        Contador++;
    }
}
PtrTArticulo BuscarArticulo(PtrPersona& Lista, int cual)
{
    return Lista;
}


void GuardarInventario(PtrPersona Lista) {
    FILE* archivo;
    fopen_s(&archivo, "ARCHIVO.txt", "w+");
    if (NULL == archivo) {
        printf("No se pudo abrir el archivo.");
    }
    else {
        PtrTArticulo AUX = Lista;
        while (AUX != NULL) {
            fprintf(archivo, "%i\n", AUX->Codigo);
            fprintf(archivo, "%s\n", AUX->Nombre);
            fprintf(archivo, "%i\n", AUX->Disponible);
            fprintf(archivo, "%f\n", AUX->Precio);
            AUX = AUX->Siguiente;
        }


    }
    fclose(archivo);
}
void CargarInventario(PtrPersona& Lista) {
    PtrTArticulo Nuevo;
    FILE* archivo;
    fopen_s(&archivo, "ARCHIVO.txt", "r");
    if (NULL == archivo) {
        printf("No se pudo abrir el archivo");
    }
    else {


        while (!feof(archivo)) {
            Nuevo = new(TArticulo);
            char Cadena[20];
            fscanf_s(archivo, "%i\n", &Nuevo->Codigo);
            fscanf_s(archivo, "%s\n", Cadena, 20);
            fscanf_s(archivo, "%i\n", &Nuevo->Disponible);
            fscanf_s(archivo, "%f\n", &Nuevo->Precio);
            strcpy_s(Nuevo->Nombre, Cadena);
            Nuevo->Siguiente = NULL;
            AgregarFinalInventario(Lista, Nuevo);

        }
    }
    fclose(archivo);

