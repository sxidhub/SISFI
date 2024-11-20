#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

//Declaracion de variables
typedef struct
{
    int operacion_temp;
    int mode_temp;
}menu_temp;
typedef struct
{
    char huella_data_temp[200];
    int mode_temp;
    int validador_temp;
    int horario_n_temp;
}entrsal_temp;
typedef struct
{
    char profe [60];
    char huellas_profe[50];
    char materia[50];
}GUARDADO;
char profe[50][50];
char huellas[50][50];
char horarios[50][200];

// Fin de la declaracion de variables


//Procedimiento abrir archivo
void ARCHIVO1(char PRUEBA[50][50],char PRUEBA2[50][50]){
    FILE *informacion;
    char linea[100];
    char *campo;
    int num_profe=0;
    GUARDADO guardados[20];
    num_profe=0;
    informacion = fopen ("E:\\VISUAL STUDIO\\ELSISFI\\INFORMACION.txt","r");
    if(informacion==NULL)
    {
        printf ("Error al abrir archivo\n");
    }
    while (fgets(linea,100,informacion)!=NULL)
    {
        campo=strtok(linea,",");
        strcpy(guardados[num_profe].profe, campo);
        campo= strtok(NULL,",");
        strcpy(guardados[num_profe].huellas_profe, campo);
        campo= strtok(NULL,",");
        strcpy(guardados[num_profe].materia, campo);
        num_profe++;
    }
    fclose(informacion);
    for (int i=0; i < num_profe; i++)
    {
        strcpy(PRUEBA[i], guardados[i].huellas_profe);
        strcpy(PRUEBA2[i], guardados[i].profe);
    }
}
//Procedimiento guardar en archivo
void GUARDAR_ARCHIVO(int nhorario){
    FILE *registros;
    registros = fopen ("E:\\VISUAL STUDIO\\ELSISFI\\REGISTROS.txt","a");
    if(registros==NULL)
    {
        printf ("Error al abrir archivo\n");
    }
    fprintf(registros,"%s",horarios[nhorario]);
    fclose(registros);
}
//Funcion para obtener la hora y fecha actual
void obtener_fecha(int *dia, int *mes, int *anio, int *horas, int *minutos, int *segundos) {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    *horas = local->tm_hour;         // obtener horas desde la medianoche (0-23)
    *minutos = local->tm_min;        // obtener minutos pasados después de la hora (0-59)
    *segundos = local->tm_sec;        // obtener segundos pasados después de un minuto (0-59)
    *dia = local->tm_mday;           // obtener el día del mes (1 a 31)
    *mes = local->tm_mon + 1;      // obtener el mes del año (0 a 11)
    *anio = local->tm_year + 1900;   // obtener el año desde 1900
}

//Función ver registro de horarios con 666
int admins(int *horario_n, char horarios[50][200], int mode) 
{
    int admin_check=0,admin;
    system("cls");
    printf("Registro de horarios\n");
    while (admin_check <= *horario_n)
    {
        printf("%s", horarios[admin_check]);
        (admin_check)++;
    }
    sleep(4);
    printf ("\nQuiere volver a main\? (30)\nQuiere apagar el programa\? (40)\n");
    scanf ("%i",&(admin));
        switch (admin){
        case 30:
            mode=1;
            break;
        case 40:
            mode=304;
            break;
        default:
            printf ("Opcion no valida");
            sleep(2);
            mode=1;
            break;}
    system("cls");
    return mode;
}

//Funcion Menú
menu_temp menu(int mode,int horario_n)
{
    menu_temp Return_Menu;
    int operacion;

    while (mode==1)
    { 
        system("cls");
        printf ("Entrada (10) / Salida (20)\n");
        operacion = 0;
        if (scanf("%i", &operacion) != 1)
        {
            while (getchar() != '\n');
        }
        Return_Menu.operacion_temp = operacion;

        switch (operacion)
        {
            case 10:
                printf ("Registro de entrada\n");
                mode = 2;  //mode = 1 es menu y 2 es carga
                sleep(2);
                system("cls");
                break;
            case 20:
                printf ("Registro de salida\n");
                mode = 2;  //mode = 1 es menu y 2 es carga
                sleep(2);
                system("cls");
                break;
            case 304:    //Salir codigo
                mode = 304;
                break;
            case 666:   //Admin cheks
                mode = admins(&horario_n, horarios, mode);
                break;
            default:
                printf ("Redirigiendo a main\n");
                sleep(2);
                break;
        }
    }
    Return_Menu.mode_temp = mode;
    return Return_Menu;
}

//Función Entrada/Salida
entrsal_temp entrsal(int operacion,int horario_n,int *guardar_no)
{
    int horas, minutos, segundos, dia, mes, anio; // Variables para almacenar los componentes de fecha y hora
    int z=0,i=0,validador=0,line=0;
    char huella_data[200],registro_tem[4][50];
    entrsal_temp Return_Entrsal;
    Return_Entrsal.horario_n_temp=0;
        printf("Esperando registro de huella, tiene 30 segundos para hacerlo /la huella es 12345678/\n");
        scanf ("%s",huella_data);
        ARCHIVO1(huellas,profe);
        validador = 0;
        for (i = 0; i < 4; i++)
        {
            if (strcmp (huellas[i],huella_data)==0)
            {
                validador=1;
                line=i;
            }
        }
        if (validador == 1)
        {
            strcpy(huella_data, "");
            obtener_fecha(&dia, &mes, &anio, &horas, &minutos, &segundos);
            if (operacion==10)
            {
                printf ("%s . Entrada registrada con exito a las %02d:%02d:%02d\n",profe[line],horas, minutos, segundos);
                strcpy(registro_tem[0],"Entrada,");
                strcpy(registro_tem[1],profe[line]);
                sprintf(registro_tem[2], ",%02d/%02d/%d", dia, mes, anio);
                sprintf(registro_tem[3], ",%02d:%02d:%02d\n", horas, minutos, segundos);
                horario_n ++;
            }
            else 
            {
                printf ("%s . Salida registrada con exito a las %02d:%02d:%02d\n",profe[line],horas, minutos, segundos);
                strcpy(registro_tem[0],"Salida,");
                strcpy(registro_tem[1],profe[line]);
                sprintf(registro_tem[2], ",%02d/%02d/%d", dia, mes, anio);
                sprintf(registro_tem[3], ",%02d:%02d:%02d  \n",horas, minutos, segundos);
                horario_n ++;
            }
            for (z=0;z<4;z++)
            {
                strcat(huella_data,registro_tem[z]);
            } 
        }
        else 
        {
            printf ("Huella no valida\n");
            *guardar_no=1;
        }
        Return_Entrsal.mode_temp=1;
        strcpy(Return_Entrsal.huella_data_temp, huella_data);
        Return_Entrsal.horario_n_temp = horario_n;
        sleep(3);
        system("cls");
        GUARDAR_ARCHIVO(horario_n);
    return Return_Entrsal;
}

int main (){
    int mode=1,operacion,horario_n=0;
    char huella_data[200];
    // Algoritmo
    while (mode != 304)
    {
        //Funcion main
        if (mode ==1){
        menu_temp Return2_Menu = menu(mode,horario_n);
        mode = Return2_Menu.mode_temp;
        operacion = Return2_Menu.operacion_temp;}
        //Funcion 2 Entrada/Salida
        if (mode ==2)
        {
            int guardar_no=0;
            entrsal_temp Return2_Entrsal = entrsal(operacion,horario_n,&guardar_no);
            strcpy(huella_data, Return2_Entrsal.huella_data_temp);
            mode = Return2_Entrsal.mode_temp;
            horario_n = Return2_Entrsal.horario_n_temp;
            printf("%i",horario_n);
            sleep(2);
            //Copiar
            strcpy(horarios[horario_n],huella_data);
            if (guardar_no==0)
            {
                GUARDAR_ARCHIVO(horario_n);
            }
        }




    }
    printf("EXIT");
    //Fin del algoritmo
    return 0;
}