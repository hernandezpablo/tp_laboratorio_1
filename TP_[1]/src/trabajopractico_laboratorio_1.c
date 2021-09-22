#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
	setbuf(stdout, NULL);
    int seguir = 1;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivi;
    int resultadoMulti;
    int primerValor;
    int segundoValor;
    int primerFactorial;
    int segundoFactorial;
    int flagPrimerValor = 0;
    int flagSegundoValor = 0;
    int flagCalculosHechos = 0;

    do{


     switch(menu(flagPrimerValor,primerValor, flagSegundoValor, segundoValor, resultadoSuma, resultadoResta, resultadoDivi, resultadoMulti, primerFactorial, segundoFactorial)){
        case 1:
            ingresarPrimerDato(&primerValor);
            printf("El numero ingresado es igual A=%d\n",primerValor);
            flagPrimerValor = 1;

            break;
        case 2:

            segundoValor = ingresarSegundoDato();
            printf("El segundo numero ingresado es %d\n", segundoValor);
            flagSegundoValor = 1;
            break;
        case 3:
            if(flagPrimerValor == 1 && flagSegundoValor == 1){
           calcularOperaciones(primerValor, segundoValor, &resultadoSuma,&resultadoResta,&resultadoDivi,&resultadoMulti, &primerFactorial, &segundoFactorial);
            printf("Se han realizado todos los calculos\n");
            flagCalculosHechos = 1;
            }else{
            printf("Usted no puede realizar las operaciones sin haber ingresado dos numeros");
            }

            break;
        case 4: if (flagCalculosHechos == 1){
            mostrarCalculos(primerValor,segundoValor, resultadoSuma, resultadoResta, resultadoDivi, resultadoMulti, primerFactorial, segundoFactorial);
            }else{
            printf("No se puede mostrar el resultado sin haber calculado las operaciones antes");
            }
            break;
        case 5:
            seguir = 0;
            break;
        default:
            printf("Opcion invalida\n");
         }
    printf("\n\n\n\n");
    }while(seguir == 1);
    return 0;
}

