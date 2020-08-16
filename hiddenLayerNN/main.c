#include <stdio.h>
#include "hiddenlayer.h"

#define SAD_PRED_IDX    0
#define SCK_PRED_IDX    1
#define ACT_PRED_IDX    2

#define IN_LEN          3
#define OUT_LEN         3
#define HID_LEN         3


double predicted_values[OUT_LEN];

double input_to_hidden_weights[HID_LEN][IN_LEN] = {{-2,     9.5,    2.01},
                                                   {-0.8,   7.2,    6.3},
                                                   {-0.5,   0.45,   0.9}};

double hidden_to_output_weights[OUT_LEN][HID_LEN] = {{-1.0,   1.15,   0.11},
                                                     {-0.18,  0.15,  -0.01},
                                                     {0.25,   -0.25, -0.1}};
double inputs[IN_LEN] = {30,87,110};

int main()
{
    printf("Hello Neural Network World!\n\n");

    hidden_layer_NN(inputs,IN_LEN,HID_LEN, input_to_hidden_weights, OUT_LEN, hidden_to_output_weights, predicted_values);
    printf("Sad Prediction : %f\n",predicted_values[SAD_PRED_IDX]);
    printf("Sick Prediction : %f\n",predicted_values[SCK_PRED_IDX]);
    printf("Act Prediction : %f\n",predicted_values[ACT_PRED_IDX]);
    return 0;
}
