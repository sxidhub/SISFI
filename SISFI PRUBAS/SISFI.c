#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
int main ()
{
int operacion;
int horario_n=0,admin_check=0, verdadero=5,mode=2, z=0,n=0;
char huella_data[100], registro_tem[4][50],horarios[50][200];
char huella_data_base[3][20]={
"Mauricio Hernandez",
"12345678",
"Matematicas"};
printf ("Tu huella dactilar es %s\n",huella_data_base[1]);
while (verdadero == 5){
    while (mode==2){ 
        printf ("Entrada (10) / Salida (20)\n");
        scanf ("%i",&operacion);
        if (operacion==666){
            admin_check=0;
            while (admin_check < horario_n){
                printf ("\n\n%s\n\n",horarios[admin_check]);
                admin_check ++;
            }
        Sleep (10000);
        }
        if (operacion==10 || operacion==20){
            mode=3;  //mode = 3 es Carga y 2 es Menu
            if (operacion==10){
                printf ("Registro de entrada\n");}
            else {
                printf ("Registro de salida\n");}
        }
        Sleep (2000);
        system("cls");
    }
    while (mode==3){
        printf("Esperando registro de huella, tiene 30 segundos para hacerlo\n");
        scanf ("%s",huella_data);
        if (strcmp(huella_data, huella_data_base[1]) == 0){
            strcpy(huella_data, "");
            if (operacion==10){
                printf ("%s . Entrada registrada con exito a las 2:00 pm\n",huella_data_base[0]);
                strcpy(registro_tem[0],"Entrada ");
                strcpy(registro_tem[1],huella_data_base[0]);
                strcpy(registro_tem[0],"12 de Septiembre");
                strcpy(registro_tem[1]," 2:00 PM\n");
            }
            else {
                printf ("%s . Salida registrada con exito a las 2:00 pm\n",huella_data_base[0]);
                strcpy(registro_tem[0],"Salida ");
                strcpy(registro_tem[1],huella_data_base[0]);
                strcpy(registro_tem[0],"12 de Septiembre");
                strcpy(registro_tem[1]," 2:00 PM\n");
            }
            z=0;
            while (z<4)
            {
                strcat(huella_data,registro_tem[z]);
                z++;}
            strcpy(horarios[horario_n],huella_data);
            horario_n ++;
            mode=2;
            Sleep (3000);
            system("cls");}
        else {
            printf ("Huella no valida\n");
            mode=2;
            Sleep (3000);
            system("cls");}
    }
}
return 0;
}