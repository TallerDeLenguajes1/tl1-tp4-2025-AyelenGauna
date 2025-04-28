#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMA 100

typedef struct { 
    int TareaID;//Numérico autoincremental comenzando en 1000 
    char *Descripcion;       
    int Duracion; // entre 10 – 100  
}Tarea;  

typedef struct Nodo{
    Tarea T;
    struct Nodo * Siguiente;
}Nodo;

// ***** PROTOTIPOS DE FUNCIONES *****

Nodo * NuevaTarea (int tareaID, char *descripcion, int duracion);
void InsertarTareaAlFinal (Nodo ** ListaTareas, Nodo * NuevaTarea);
Nodo * BuscarTarea (Nodo * ListaTareas, int tareaID);
Nodo * QuitarTarea (Nodo ** ListaTareas, int tareaID);
void EliminarTareaDeLista (Nodo * Tarea);

// ***** FUNCIONES *****
Nodo * NuevaTarea (int tareaID, char *descripcion, int duracion){
    Nodo * NTarea;
    NTarea = (Nodo *)malloc(sizeof(Nodo));
    NTarea->T.TareaID = tareaID;
    NTarea->T.Descripcion = descripcion;
    NTarea->T.Duracion = duracion;

    return NTarea;
}

void InsertarTareaAlFinal (Nodo ** ListaTareas, Nodo * NuevaTarea){
    
    if (*ListaTareas == NULL) {
        
        *ListaTareas = NuevaTarea;

    } else {
        Nodo * nAux = *ListaTareas;
        while (nAux->Siguiente) {
            nAux = nAux->Siguiente;
        }
        nAux->Siguiente = NuevaTarea;
    }
    NuevaTarea->Siguiente = NULL;
}

Nodo * BuscarTarea (Nodo * ListaTareas, int tareaID){
    Nodo *nAux = ListaTareas;

    while (nAux && nAux->T.TareaID != tareaID)
    {
        nAux = nAux->Siguiente;
    }
    
    return nAux;
}

Nodo * QuitarTarea (Nodo ** ListaTareas, int tareaID){
    Nodo *nAux = * ListaTareas, *TareaAnterior = NULL;
    while (nAux != NULL && nAux->T.TareaID != tareaID)
    {
        TareaAnterior = nAux;
        nAux = nAux->Siguiente;
    }

    if (nAux != NULL)
    {
        if (nAux == (*ListaTareas))
        {
            * ListaTareas = nAux->Siguiente;
        }else
        {
            TareaAnterior->Siguiente = nAux->Siguiente;    
        }
        
        nAux->Siguiente = NULL;

    }  
    
    return nAux;
}

void EliminarTareaDeLista (Nodo * Tarea){
    if (Tarea)
    {
        free(Tarea);
    }
}