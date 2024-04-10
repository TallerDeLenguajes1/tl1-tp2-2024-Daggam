#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct compu{
    int velocidad; // [1,3]
    int anio; // [2015,2023]
    int cantidad; // [1,8]
    char*tipo_cpu; //valores del arreglo
}Compu;
void mostrarCompu(Compu *ArregloPC);
void mostrarCaracteristicas(Compu *ArregloPC);
void mostrarPCMasVieja(Compu *ArregloPC);
void mostrarPCMasRapida(Compu *ArregloPC);

void main(){
    char tipos[6][10] = {"Intel","AMD","Celeron","Athlon","Core","Pentium"};
    int opcion;
    srand(time(NULL));

    Compu Arreglo_PC[5];
    printf("--- CARGA DE DATOS ---");
    for (int i = 0; i < 5; i++)
    {
        printf("COMPU %d:\n",i+1);
        do
        {
            printf("- Velocidad [1,3]: ");
            scanf("%d",&(Arreglo_PC[i].velocidad));
            if(Arreglo_PC[i].velocidad < 1 || Arreglo_PC[i].velocidad > 3) printf("Numero ingresado no valido. Intente de nuevo.\n");
        } while (Arreglo_PC[i].velocidad < 1 || Arreglo_PC[i].velocidad > 3);
        
        do
        {
            printf("- Anio [2015,2023]: ");
            scanf("%d",&(Arreglo_PC[i].anio));
            if(Arreglo_PC[i].anio < 2015 || Arreglo_PC[i].anio > 2023) printf("Numero ingresado no valido. Intente de nuevo.\n");
        } while (Arreglo_PC[i].anio < 2015 || Arreglo_PC[i].anio > 2023);
        
        do
        {
            printf("- Cantidad [1,8]: ");
            scanf("%d",&(Arreglo_PC[i].cantidad));
            if(Arreglo_PC[i].cantidad < 1 || Arreglo_PC[i].cantidad > 8) printf("Numero ingresado no valido. Intente de nuevo.\n");
        } while (Arreglo_PC[i].cantidad < 1 || Arreglo_PC[i].cantidad > 8);

        do
        {
        
            printf("- Tipo de CPU (0-5): \n");
            printf("0 - Intel\n");
            printf("1 - AMD\n");
            printf("2 - Celeron\n");
            printf("3 - Athlon\n");
            printf("4 - Core\n");
            printf("5 - Pentium\n");
            printf("Opcion: ");
            scanf("%d",&opcion);
            if(opcion < 0 || opcion > 5){
                printf("Numero ingresado no valido. Intente de nuevo.\n");
            }else{
                Arreglo_PC[i].tipo_cpu = tipos[opcion];
            }
        } while (opcion < 0 || opcion > 5);
       
    }

    mostrarCaracteristicas(Arreglo_PC);
    mostrarPCMasVieja(Arreglo_PC);
    mostrarPCMasRapida(Arreglo_PC);
}

void mostrarCompu(Compu *ArregloPC){
    printf("- Velocidad: %d\n",ArregloPC->velocidad);
    printf("- Anio: %d\n",ArregloPC->anio);
    printf("- CPU: %s\n",ArregloPC->tipo_cpu);
    printf("- Cantidad de nucleos: %d\n\n",ArregloPC->cantidad);
}
void mostrarCaracteristicas(Compu *ArregloPC){
    for (int i = 0; i < 5; i++)
    {
        printf("---- COMPU %d ----\n",i+1);
        mostrarCompu(ArregloPC);
        ArregloPC++;
    }
    
}
void mostrarPCMasVieja(Compu *ArregloPC){
    Compu* PCMasVieja = ArregloPC;
    for (int i = 0; i < 5; i++)
    {
        if(ArregloPC->anio < PCMasVieja->anio)
        {
            PCMasVieja = ArregloPC;
        }
        ArregloPC++;
    }

    printf("---- LA PC MAS VIEJA ES ----\n");
    mostrarCompu(PCMasVieja);
}
void mostrarPCMasRapida(Compu *ArregloPC){
    Compu* PCMasRapida = ArregloPC;
    for (int i = 0; i < 5; i++)
    {
        if(ArregloPC->velocidad > PCMasRapida->velocidad)
        {
            PCMasRapida = ArregloPC;
        }
        ArregloPC++;
    }

    printf("---- LA PC MAS RAPIDA ES ----\n");
    mostrarCompu(PCMasRapida);
}