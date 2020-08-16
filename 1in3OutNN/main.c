#include <stdio.h>
#include "in3outnn.h"

#define sad 0.9
#define TEMP_IND 0
#define HUM_IND 1
#define AIRQ    2

#define LEN 3


double results[3];
double agirlik[3] = {-20, 95, 201};


int main()
{
    sinInMultiOutNN(sad, agirlik, results,LEN);
    printf("Sıcaklık Tahmini : %f\n", results[TEMP_IND]);
    printf("Hava Nem Tahmini : %f\n", results[HUM_IND]);
    printf("Hava Kalite Tahmini : %f\n", results[AIRQ]);
    return 0;
}
