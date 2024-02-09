#include <string.h>
#include <stdio.h>
#include <math.h>
#include "helper1.h"
#include "helper2.h"
#define SIZE 10

// Variables globales
extern int num; // num se definio en helper1.c
char s[SIZE];

int main() {
    // Variables locales
    double degrees = 45.0;
    double radians = degrees * ( M_PI / 180.0 );
    double result;

    printf("Hello, World!\n");
    obtener_hora_actual();
    printf("num = %d\n",num);
    saludo();
    incrementar_num();
    saludo();
    printf("num = %d\n",num);
    strcpy(s,"hola");
    int t = tam(s);
    printf("tam = %d\n",t);
    incrementar_num2(30);
    printf("num = %d\n",num);
    result = tan(radians);
    printf("The tangent of %0.2lf is %0.2lf \n", degrees, result);
    return 0;
}