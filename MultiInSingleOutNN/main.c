#include <stdio.h>
#include "multiinsingleout.h"


double TEMP[]={10,20,30,40,50,60,70};
double HUMD[]={23,56,89,12,45,78,86};
double AIRQ[]={98,65,32,21,54,87,81};
double weigth[3]= {5,8,4};

#define LEN 3

int main()
{
int size = sizeof(TEMP) / sizeof(TEMP[0]);
    printf("Hello Deep Learning!\n");
    for (int i = 0; i < size; i++)
    printf("Personel Mood is : %f\n", multiInSingleOut(&TEMP[i],&HUMD[i],LEN));

    return 0;
}
