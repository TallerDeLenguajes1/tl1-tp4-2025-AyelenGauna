#include "fn-distribuidora.h"

int main(){

    Nodo * ListaTareasPendientes = NULL, * ListaTareasRealizadas = NULL;
    int tareaID = 1000, duracion, opcion = 1, tareaRealizadaID = 0, tareaRealizada;
    char * descripcion;
    descripcion = (char *)malloc(TAMA * sizeof(char));

    //***** INTERFAZ PARA CARGAR TAREAS *****
    printf("--- CARGAR TAREAS ---\n");
    do
    {
        printf("\nTarea %d: ", tareaID);

        printf("\nDescripcion: ");
        fgets(descripcion,TAMA,stdin);
        descripcion[strcspn(descripcion, "\n")] = '\0';

        do
        {
            printf("Duracion (10min min a 100min max): ");
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

        Nodo * NTareaP = NuevaTarea(tareaID,descripcion,duracion);
        
        InsertarTareaAlFinal(&ListaTareasPendientes,NTareaP);

        printf("\nDesea ingresar una nueva tarea o finalizar la carga");
        do
        {
            printf("\nAGREGAR=1\tFINALIZAR=0\n");
            scanf("%d", &opcion);
            while (getchar() != '\n');

            if (opcion !=1 && opcion !=0)
            {
                printf("\nOpcion incorrecta\n");
            }
            if (opcion == 1)
            {
                tareaID++;
            }     
            
        } while (opcion !=1 && opcion !=0);   

    } while (opcion);
    
    // inicializo "opcion" en 1
    opcion = 1;

    //***** INTERFAZ PARA MOVER TAREAS PENDIENTES A TAREAS REALIZADAS *****
    printf("\n--- TAREAS REALIZADAS ---\n");
    do
    {
       do
       {
            tareaRealizada = tareaRealizadaID;

            printf("\nIngrese el ID de la tarea que ya se realizo: ");
            scanf("%d",&tareaRealizadaID);
            while (getchar() != '\n');
            
            if (1000 > tareaRealizadaID)
            {
                printf("\nEl ID de las tareas son de 1000 en adelante\n");

            }else if (tareaRealizadaID > tareaID)
            {
                printf("\nEl ID ingresado no existe\n");

            }else if (tareaRealizadaID == tareaRealizada)
            {
                printf("\nEl ID ingresado ya se encuentra en la lista de tareas realizadas\n");
            }
                     
        } while (1000 > tareaRealizadaID || tareaRealizadaID > tareaID || tareaRealizadaID == tareaRealizada);

        Nodo * NTareaR = QuitarTarea(&ListaTareasPendientes,tareaRealizadaID);
        
        //Nodo * NTareaR = BuscarTarea(ListaTareasPendientes,tareaRealizadaID);
        
        InsertarTareaAlFinal(&ListaTareasRealizadas,NTareaR);
        
        printf("\nSe realizo alguna otra tarea");
        do
        {
            printf("\nSI=1\tNO=0\n");
            scanf("%d", &opcion);
            while (getchar() != '\n');

            if (opcion !=1 && opcion !=0)
            {
                printf("\nOpcion incorrecta\n");
            }
            
        } while (opcion !=1 && opcion !=0);

    } while (opcion);

    MostrarListas(ListaTareasPendientes,ListaTareasRealizadas);

    printf("\n--- CONSULTAR TAREA ---");
        do
        {
            printf("\nPOR ID: 0\tPOR PALABRA CLAVE: 1\n");
            scanf("%d",&opcion);
            while (getchar() != '\n');
            
            switch (opcion)
            {
                case 0:
                    int id;

                    // BUSCO UNA TAREA POR SU IDENTIFICADOR Y LA MUESTRA EN PANTALLA
                    MostrarBuscarTareaPorId (ListaTareasPendientes,ListaTareasRealizadas,id);
                    
                    break;

                case 1:
                    char *palabra_clave;
                    palabra_clave =(char *)malloc(TAMA * sizeof(char));
                    // INGRESO UNA PALABRA CLAVE PARA BUSCAR UNA TAREA Y MOSTRARLA EN PANTALLA 
                    MostrarBuscarTareaPorPalabra(ListaTareasPendientes,ListaTareasRealizadas,palabra_clave);
                    free(palabra_clave);

                    break;
            
                default:
                    printf("\nOPCION INCORRECTA\n");

                    break;
            }  
        
            printf("\nDesea seguir buscando una tarea");
            do
            {
                printf("\nSI=2\tNO=0\n");
                scanf("%d",&opcion);
                while (getchar() != '\n');

                if (opcion != 2 && opcion != 0)
                {
                    printf("\nOPCION INCORRECTA\n");
                }

                if (opcion == 0)
                {
                    printf("\n***** HASTA LUEGO *****\n");
                }  
                
            } while (opcion != 2 && opcion != 0);

    } while (opcion != 0 && opcion != 1); 

    LiberarMemoria(ListaTareasPendientes);
    LiberarMemoria(ListaTareasRealizadas);

    return 0;
}

