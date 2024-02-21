#include "helper2.h"
#include <stdio.h>      
#include <sys/time.h>
#include <time.h>

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