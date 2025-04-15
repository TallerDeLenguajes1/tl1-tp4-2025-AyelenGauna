#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100

struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea ;

struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
}typedef Nodo;


Nodo *crearNodo(char *desc, int duracion, int id){
    Nodo * nuevo = (Nodo *) malloc (sizeof(Nodo));
    nuevo->T.Descripcion=(char*)malloc(strlen(desc)+1);
    strcpy(nuevo->T.Descripcion, desc );
    nuevo->T.Duracion=duracion;
    nuevo->T.TareaID=id;
    nuevo->Siguiente=NULL;

    return nuevo;
}
void tareasPendientes(Nodo **start, Nodo *Nodo){
    Nodo->Siguiente= *start;
    *start=Nodo;
}

void mostrarTareas( Nodo *pendientes){
   printf("------TAREAS PENDIENTES------");
    while (pendientes!=NULL)
    {
        printf("\nID:%d  //  Descripcion:%s //Duracion:%d", pendientes->T.TareaID, pendientes->T.Descripcion, pendientes->T.Duracion);
        pendientes=pendientes->Siguiente;

    }
    
}
int main (){
    Nodo *pendientes=NULL;
    int id=1000;
    int aux, cont=0;
    char desc[MAX];
    int duracion;

    do
    {
        printf("Ingrese la descripcion de la tarea a realizar:");
        getchar();
        gets(desc);

        printf("Ingrese la duracion de la tarea realizada:");
        scanf("%d", &duracion);

        Nodo *new=crearNodo(desc, duracion, id++);
        tareasPendientes(&pendientes, new);

        printf("¿Quiere otra tarea pediente?(1-SI  0-NO)");
        scanf("%d", &aux);
        cont++;

    } while (aux!=0);
    mostrarTareas( pendientes);

    return 0;
}