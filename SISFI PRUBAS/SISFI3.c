#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#define longitud_linea
//Inicio de declaracion de variable
//Funcion para obtener la fecha
void getdate(int *dia, int *mes, int *anio, int *horas, int *minutos, int *segundos) {
    // Obtener la hora y fecha actuales
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

void admins(int *admin_check, int *horario_n, int *admin, char horarios[50][200], int *mode) 
{
    system("cls");
    printf("Registro de horarios\n\n");
    *admin_check=0;
    while (*admin_check < *horario_n)
    {
        printf("%s", horarios[*admin_check]);
        (*admin_check)++;
    }
    sleep(4);
    printf ("\nQuiere volver a main\? (30)\nQuiere apagar el programa\? (40)\n");
    scanf ("%i",&(*admin));
        switch (*admin){
        case 30:
            *mode=1;
            break;
        case 40:
            *mode=304;
            break;
        default:
            printf ("Opcion no valida");
            sleep(2);
            *mode=1;
            break;}
    system("cls");
}

int main (){
int operacion;
int horario_n=0;
int admin_check=0;
int mode=1;
int z=0;
int admin=0;
char huella_data[100], registro_tem[4][50],horarios[50][200];
char huella_data_base[3][20]={
"Mauricio Hernandez",
"12345678",
"Matematicas"};
// variables para almacenar los componentes de fecha y hora
int horas, minutos, segundos, dia, mes, anio;
//Fin de la declaracion de variables
//Algoritmo
while (mode != 304)
{
    while (mode==1)
    { 
        system("cls");
        printf ("Entrada (10) / Salida (20)\n");
        if (scanf("%i", &operacion) != 1)
        {
        while (getchar() != '\n');
        }
        //
        if (operacion==666)
        {
            admins(&admin_check, &horario_n, &admin, horarios, &mode);
        }
        //
        switch (operacion)
        {
        case 10:
            printf ("Registro de entrada\n");
            mode=2;  //mode = 1 es menu y 2 es carga
            sleep(2);
            system("cls");
            break;
        case 20:
            printf ("Registro de salida\n");
            mode=2;  //mode = 1 es menu y 2 es carga
            sleep(2);
            system("cls");
            break;
        default:
            printf ("Redirigiendo a main\n");
            operacion=0;
            mode=1;
            sleep(2);
            break;
        }
        //
        if (operacion==304){
            mode = 304;
        }
    }
    
    while (mode==2)
    {
        printf("Esperando registro de huella, tiene 30 segundos para hacerlo /la huella es 12345678/\n");
        scanf ("%s",&huella_data);
        if (strcmp(huella_data, huella_data_base[1]) == 0)
        {
            strcpy(huella_data, "");
            getdate(&dia, &mes, &anio, &horas, &minutos, &segundos);
            if (operacion==10)
            {
                printf ("%s . Entrada registrada con exito a las %02d:%02d:%02d\n",huella_data_base[0],horas, minutos, segundos);
                strcpy(registro_tem[0],"Entrada ");
                strcpy(registro_tem[1],huella_data_base[0]);
                sprintf(registro_tem[2], " %02d/%02d/%d ", dia, mes, anio);
                sprintf(registro_tem[3], "%02d:%02d:%02d\n", horas, minutos, segundos);
            }
            else 
            {
                printf ("%s . Salida registrada con exito a las %02d:%02d:%02d\n",huella_data_base[0],horas, minutos, segundos);
                strcpy(registro_tem[0],"Salida ");
                strcpy(registro_tem[1],huella_data_base[0]);
                sprintf(registro_tem[2], " %02d/%02d/%d ", dia, mes, anio);
                sprintf(registro_tem[3], "%02d:%02d:%02d  \n",horas, minutos, segundos);
            }
            
            for (z=0;z<4;z++)
            {
                strcat(huella_data,registro_tem[z]);
            }
            
            strcpy(horarios[horario_n],huella_data);
            horario_n ++;
        }
        
        else 
        {
            printf ("Huella no valida\n");
        }
        mode = 1;
        sleep(3);
        system("cls");
    }
}
printf("EXIT");
//Fin del algoritmo
return 0;
}