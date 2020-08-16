#include <stdio.h>
#include "mul_in_mul_out.h"


#define INPUT_LEN  3
#define OUTPUT_LEN 3

#define SAD_PREDICTION_IDX    0
#define SICK_PREDICTION_IDX   1
#define ACTIVE_PREDICTION_IDX 2

double predicted_output[3];
double input_vector[INPUT_LEN] = {-2, 9.5, 2.01};

double weigths_vector[OUTPUT_LEN][INPUT_LEN] = {{-2,      9.5,    2.01},
                                                {-0.8,    7.2,    6.3},
                                                {-0.5,    0.45,   0.9}};


int main()
{
    printf("Hello Deep Learning!\n\n");

    mul_in_mul_out(input_vector, INPUT_LEN, predicted_output, OUTPUT_LEN, weigths_vector);

    printf("Sadness Indicator is\t: %f\r\n", predicted_output[SAD_PREDICTION_IDX]);
    printf("Sickness Indicator is\t: %f\r\n", predicted_output[SICK_PREDICTION_IDX]);
    printf("Actness Indicator is\t: %f\r\n", predicted_output[ACTIVE_PREDICTION_IDX]);

    return 0;
}
