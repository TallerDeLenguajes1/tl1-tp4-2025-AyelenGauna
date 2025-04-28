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
Nodo * BuscarTareaPorId (Nodo * ListaTareas, int tareaID);
Nodo * BuscarTareaPorPalabra (Nodo * ListaTareas, char * palabra_clave);
void MostrarBuscarTareaPorId (Nodo * Lista1,Nodo * Lista2, int tareaID);
void MostrarBuscarTareaPorPalabra (Nodo * Lista1,Nodo * Lista2, char * palabra_clave);
Nodo * QuitarTarea (Nodo ** ListaTareas, int tareaID);
void MostrarListas (Nodo *ListaTareasPendientes, Nodo * ListaTareasRealizadas);
void LiberarMemoria (Nodo *Lista);

// ***** FUNCIONES *****
Nodo * NuevaTarea (int tareaID, char *descripcion, int duracion){
    Nodo * NTarea;
    NTarea = (Nodo *)malloc(sizeof(Nodo));
    NTarea->T.TareaID = tareaID;
    NTarea->T.Descripcion = strdup(descripcion);
    NTarea->T.Duracion = duracion;
    NTarea->Siguiente = NULL;

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

Nodo * BuscarTareaPorId (Nodo * ListaTareas, int tareaID){
    Nodo *nAux = ListaTareas;

    while (nAux && nAux->T.TareaID != tareaID)
    {
        nAux = nAux->Siguiente;
    }
    
    return nAux;
}

Nodo * BuscarTareaPorPalabra (Nodo * ListaTareas, char * palabra_clave){
    Nodo *nAux = ListaTareas;
    
    while (nAux)
    {
        if (strstr(nAux->T.Descripcion,palabra_clave) != NULL)
        {
            return nAux;
        }
        nAux = nAux->Siguiente; 
    }
    
    return nAux;
}

void MostrarBuscarTareaPorId (Nodo * Lista1, Nodo * Lista2, int tareaID){
    int buscar = 1;
    do
    {
        printf("\nIngrese el ID de la tarea que desea buscar: ");
        scanf("%d", &tareaID);
        while (getchar() != '\n');
          
        Nodo * Tarea1 = BuscarTareaPorId(Lista1,tareaID);
        Nodo * Tarea2 = BuscarTareaPorId(Lista2,tareaID);
        if (Tarea1 != NULL)
        {
            printf("\nTAREA PENDIENTE %d\nDescripcion: %s\nDuracion: %d\n",Tarea1->T.TareaID,Tarea1->T.Descripcion,Tarea1->T.Duracion);
        }
        if (Tarea2 != NULL)
        {
            printf("\nTAREA REALIZADA %d\nDescripcion: %s\nDuracion: %d\n",Tarea2->T.TareaID,Tarea2->T.Descripcion,Tarea2->T.Duracion);
        }
        if (Tarea1 == NULL && Tarea2 == NULL)
        {
            printf("\nNo se encontro tareas con ese ID\n");
        }

        printf("\nDesea seguir buscando tareas por ID");
        do
        {
            printf("\nSI=1\tNO=0\n");
            scanf("%d",&buscar);
            while (getchar() != '\n');

            if (buscar != 1 && buscar != 0)
            {
                printf("\nOPCION INCORRECTA\n");
            }
            
        } while (buscar != 1 && buscar != 0);
        
    } while (buscar);
            
}

void MostrarBuscarTareaPorPalabra (Nodo * Lista1,Nodo * Lista2, char * palabra_clave){
    int buscar = 1;
    do
    {
        printf("\nIngrese una palabra clave para encontrar la tarea que desee: ");
        fgets(palabra_clave,TAMA,stdin);
        palabra_clave[strcspn(palabra_clave, "\n")] = '\0';

        Nodo * Tarea1 = BuscarTareaPorPalabra(Lista1,palabra_clave);
        Nodo * Tarea2 = BuscarTareaPorPalabra(Lista2,palabra_clave);
        if (Tarea1 != NULL)
        {
            printf("\nTAREA PENDIENTE %d\nDescripcion: %s\nDuracion: %d\n",Tarea1->T.TareaID,Tarea1->T.Descripcion,Tarea1->T.Duracion);
        }
        if (Tarea2 != NULL)
        {
            printf("\nTAREA REALIZADA %d\nDescripcion: %s\nDuracion: %d\n",Tarea2->T.TareaID,Tarea2->T.Descripcion,Tarea2->T.Duracion);
        }
        if (Tarea1 == NULL && Tarea2 == NULL)
        {
            printf("\nNo se encontro tareas con ese palabra\n");
        }

        printf("\nDesea seguir buscando por palabra clave");
        do
        {
            printf("\nSI=1\tNO=0\n");
            scanf("%d",&buscar);
            while (getchar() != '\n');

            if (buscar != 1 && buscar != 0)
            {
                printf("\nOPCION INCORRECTA\n");
            }
            
        } while (buscar != 1 && buscar != 0);
        
    } while (buscar);
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

void MostrarListas (Nodo *ListaTareasPendientes, Nodo * ListaTareasRealizadas){

    printf("\n--- LISTA DE TAREAS PENDIENTES ---\n");
    while (ListaTareasPendientes)
    {
        printf("\nTAREA %d\nDescripcion: %s\tDuracion: %d",ListaTareasPendientes->T.TareaID,ListaTareasPendientes->T.Descripcion,ListaTareasPendientes->T.Duracion);
        ListaTareasPendientes = ListaTareasPendientes->Siguiente;
    }

    printf("\n--- LISTA DE TAREAS REALIZADAS ---\n");
    while (ListaTareasRealizadas)
    {
        printf("\nTAREA %d\nDescripcion: %s\tDuracion: %d\n", ListaTareasRealizadas->T.TareaID,ListaTareasRealizadas->T.Descripcion,ListaTareasRealizadas->T.Duracion);
        ListaTareasRealizadas = ListaTareasRealizadas->Siguiente;
    } 
}

void LiberarMemoria (Nodo *Lista){
    Nodo *aux;
    while (Lista) 
    {
        aux = Lista->Siguiente;  
        free(Lista->T.Descripcion);
        free(Lista);             
        Lista = aux;              
    }
}