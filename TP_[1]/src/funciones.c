#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int menu(int flagPrimerValor, int primerValor, int flagSegundoValor, int segundoValor, int resultadoSuma, int resultadoResta, float resultadoDivi, int resultadoMulti, int primerFactorial, int segundoFactorial){
    int opcion;
    printf("Menu de opciones\n\n");
        if (flagPrimerValor == 0){
        printf("1) Ingresar 1er operando\n");
        }else {
        printf("1) Ingresar 1er operando A=%d \n", primerValor);}
        if (flagSegundoValor == 0){
        printf("2) Ingresar 2do operando\n");}
        else{printf("2) Ingresar el 2do operando B=%d\n", segundoValor);

        }
        printf("3) Calcular las operaciones\n");
        printf("4) Informar resultado\n");

            printf("5) Salir\n");
            printf("\nIndique opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);


return opcion;
}
void calcularOperaciones(int primerValor, int segundoValor, int* resultadoSuma, int* resultadoResta, float* resultadoDivi,int* resultadoMulti,int* primerFactorial, int* segundoFactorial){

        *resultadoSuma = suma(primerValor,segundoValor);
        *resultadoResta = resta(primerValor, segundoValor);
        if (segundoValor != 0){
        *resultadoDivi = division( primerValor, segundoValor);
        }
        *resultadoMulti = multiplicacion( primerValor, segundoValor);
        *primerFactorial = factorial(primerValor);
        *segundoFactorial = factorial(segundoValor);



}
void mostrarCalculos(int primerValor, int segundoValor, int resultadoSuma, int resultadoResta, float resultadoDivi, int resultadoMulti, int primerFactorial, int segundoFactorial){


        printf("4a) El resultado de A+B es: %d\n", resultadoSuma);
        printf("4b) El resultado de A-B es: %d\n", resultadoResta);
        if(segundoValor == 0){

            printf("4c) No es posible dividir por 0\n");
        }else{
            printf("4c)El resultado de A/B es: %.2f\n",resultadoDivi);
        }
        printf("4d) El resultado de A*B es: %d\n",resultadoMulti);
        if ((primerValor <0 && segundoValor < 0) || (primerValor>12 && segundoValor >12)){
            printf("4e) No se pueden realizar factoriales de numeros negativos o mayores a 12\n");
        } else if((primerValor <0 || primerValor> 12)&& segundoValor>=0 && segundoValor <=12){
        printf("4e) No se puede realizar el factorial de A, el factorial de B=%d\n", segundoFactorial);
        } else if(primerValor>=0 && primerValor <=12 && (segundoValor<0 || segundoValor>12 )){
            printf("4e) No se puede realizar el factorial de B, el factorial de A=%d\n", primerFactorial);
        }else{
            printf("4e) El resultado del factorial de A=%d y el factorial de B=%d\n", primerFactorial, segundoFactorial);
            }


}


void ingresarPrimerDato(int* primerDato){
 int resultado;
 printf("Ingrese el primer operando\n");
 scanf("%d",&resultado);
 *primerDato = resultado;
}

int ingresarSegundoDato(){
int resultado;
printf("Ingrese el segundo operando\n");
 scanf("%d",&resultado);
 return resultado;
}

int suma(int primerValor, int segundoValor){
int resultadoSuma;

resultadoSuma = primerValor + segundoValor;

return resultadoSuma;
}

int resta(int primerValor, int segundoValor){
int resultadoResta;

resultadoResta = primerValor - segundoValor;

return resultadoResta;
}

float division(int primerValor, int segundoValor){
float resultadoDivi;

resultadoDivi = (float) primerValor / segundoValor;

return resultadoDivi;
}

int multiplicacion(int primerValor, int segundoValor){
int resultadoMulti;

resultadoMulti = primerValor * segundoValor;

return resultadoMulti;
}
int factorial(int valor){
int i;
int resultado=1;

for(i=1;i<=valor;i++){
    resultado = resultado  * i;
}
return resultado;

}
