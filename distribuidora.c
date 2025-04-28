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

Nodo * NuevaTarea (int tareaID, char *descripcion, int duracion);
void InsertarTareaAlFinal (Nodo ** ListaTareasPendientes, Nodo * NuevaTarea);

int main(){

    Nodo * ListaTareasPendientes = NULL, * ListaTareasRealizadas = NULL;
    int tareaID = 1000, duracion, newTarea = 1;
    char * descripcion;
    descripcion = (char *)malloc(TAMA * sizeof(char));

    printf("--- CARGAR TAREAS ---\n");
    do
    {
        printf("\nTarea %d: ", tareaID);

        printf("\nDescripcion: ");
        fgets(descripcion,TAMA,stdin);
        descripcion[strcspn(descripcion, "\n")] = '\0';

        do
        {
            printf("\nDuracion (10min min a 100min max: ");
            scanf("%d", &duracion);
            while (getchar() != '\n');

            if (duracion > 100)
            {
                printf("\nNO puede ingresar MAS de lo solicitado\n");
            }
            if (10 > duracion)
            {
                printf("\nNO puede ingresar MENOS de lo solicitado\n");
            }    
        } while (duracion > 100 || 10 > duracion);
        
       

        Nodo * Tareas = NuevaTarea(tareaID,descripcion,duracion);
        
        InsertarTareaAlFinal(&ListaTareasPendientes,Tareas);

        printf("\nDesea ingresar una nueva tarea o finalizar la carga");
        do
        {
            printf("\nAGREGAR=1\tFINALIZAR=0\n");
            scanf("%d", &newTarea);
            while (getchar() != '\n');

            if (newTarea !=1 && newTarea !=0)
            {
                printf("\nOpcion incorrecta\n");
            }
            
        } while (newTarea !=1 && newTarea !=0);
        
        

        tareaID++;
    } while (newTarea);
    

    return 0;
}

Nodo * NuevaTarea (int tareaID, char *descripcion, int duracion){
    Nodo * NTarea;
    NTarea = (Nodo *)malloc(sizeof(Nodo));
    NTarea->T.TareaID = tareaID;
    NTarea->T.Descripcion = descripcion;
    NTarea->T.Duracion = duracion;

    return NTarea;
}

void InsertarTareaAlFinal (Nodo ** ListaTareasPendientes, Nodo * NuevaTarea){
    
    if (*ListaTareasPendientes == NULL) {
        
        *ListaTareasPendientes = NuevaTarea;

    } else {
        Nodo * nAux = *ListaTareasPendientes;
        while (nAux->Siguiente) {
            nAux = nAux->Siguiente;
        }
        nAux->Siguiente = NuevaTarea;
    }
    NuevaTarea->Siguiente = NULL;
}