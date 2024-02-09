#include <string.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>

#define SIZE 10

// Variables globales
 
char s[SIZE]; 
int num; // Esta va para el archivo asociado a las funciones de la parte 1


// Funciones - parte 1

void saludo(void);
void incrementar_num(void);
int tam(const char *);

// Funciones - parte 2
void incrementar_num2(int);
void obtener_hora_actual(void);



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

// Definicion de funciones

// Funciones - parte 1
void saludo(void) {
    printf("Hola mundo\n");
}

void incrementar_num(void) {
    num++;
}

int tam(const char *str) {
    return strlen(str);
}


// Funciones - parte 2
void incrementar_num2(int x) {
    num += x;
}

void obtener_hora_actual(void) {
    struct timeval tv;
    struct tm *timeinfo;

    gettimeofday(&tv, NULL);
    timeinfo = localtime(&tv.tv_sec);

    // Obtencion de hours, minutes, and seconds
    int hours = timeinfo->tm_hour;
    int minutes = timeinfo->tm_min;
    int seconds = timeinfo->tm_sec;

    printf("Son las [Hora actual]: %02d:%02d:%02d\n", hours, minutes, seconds);
}