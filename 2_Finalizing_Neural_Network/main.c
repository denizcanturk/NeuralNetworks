#include "simple_neural_networks.h"
#include <stdio.h>
#include <utime.h>


#define INPUT_LEN 3
#define OUTPUT_LEN 3
#define HID_LEN 3

#define INPUT 0.9

#define SAD_IDX 0
#define SICK_IDX 1
#define ACT_IDX 2

#define NUM_OF_FEATURES 2
#define NUM_OF_HID_NODES 3
#define NUM_OF_OUT_NODES 1

double temp[]={12,23,50,-10,16};
double humidity[]= {60,67,50,65,63};
double air_quality[] = {60,47,167,187,94};

double weight[] = {-20,95,201};
double eg1[INPUT_LEN];


//Multiple İnput Multiple Output -> INPUT Vector
double input_vector[]={25,36,45};
double predicted_results[HID_LEN];

double expected_values[OUTPUT_LEN] = {600,10,-90};
double weight_ = 1.5;
double input_ = 0.9;
double expected_value_ = 0.1;
double step_amount = 0.001;

#define NUM_OF_FEATURES 2
#define NUM_OF_EXAMPLES 3

/* Hours Of Work Out*/

double working_hours[NUM_OF_EXAMPLES] = {2,5,1};
double normalized_working_hours[NUM_OF_EXAMPLES];

double hours_resting[NUM_OF_EXAMPLES] = {8,5,8};
double normalized_hours_resting[NUM_OF_EXAMPLES];

/* Muscle Gain Expected... */

double muscle_gain[NUM_OF_EXAMPLES] = {200,90,190};
double normalized_muscle_gain[NUM_OF_EXAMPLES];
double weight_matrix[HID_LEN][INPUT_LEN]; //This will be discarded...

double syn0[NUM_OF_HID_NODES][NUM_OF_FEATURES];
double syn1[NUM_OF_HID_NODES];

/* Training Example */
double raw_x[NUM_OF_FEATURES][NUM_OF_EXAMPLES]= {{2,5,1},
                                                 {8,5,8}};
double raw_y[1][NUM_OF_EXAMPLES] = {{200,90,190}};

/* Training x
    2/8   5/8   8/8
    8/8   5/8   8/8
     dim = nx  X m
*/
double train_x[NUM_OF_FEATURES][NUM_OF_EXAMPLES];
/*
 * 200/200 90/200 190/200
*/
double train_y[1][NUM_OF_EXAMPLES];

double train_x_eg1[NUM_OF_FEATURES];
double train_y_eg1;
double z1_eg1[NUM_OF_HID_NODES];
double a1_eg1[NUM_OF_HID_NODES];
double z2_eg1;
double yhat_eg1;

int main(){
    printf("Hello AI World!\n\r\n");

    normalize_data_2d(NUM_OF_FEATURES, NUM_OF_EXAMPLES, raw_x, train_x);
    normalize_data_2d(1,NUM_OF_EXAMPLES, raw_y, train_y);

    train_x_eg1[0] = train_x[0][0];
    train_x_eg1[1] = train_x[1][0];

    train_y_eg1 = train_y[0][0];

    printf("Train x Eg1 : [%f %f]", train_x_eg1[0], train_x_eg1[1] );
    printf("\n\n\r");
    printf("Training Y Eg1 : [%f]", train_y_eg1);
    printf("\n\n\r");
    weight_random_initialize(NUM_OF_HID_NODES, NUM_OF_FEATURES, syn0);

    printf("Syn0 weights : \n");
    for (int i = 0; i < NUM_OF_HID_NODES; i++){
        for (int j = 0; j < NUM_OF_FEATURES; j++){
            printf("%f\t", syn0[i][j]);
        }
        printf("\n");
    }

    weight_random_initialize_1D(syn1,NUM_OF_HID_NODES);
    printf("\nSyn1\n");
    for (int i = 0; i < NUM_OF_OUT_NODES; i++){
        printf("%f\t%f\t%f", syn1[0], syn1[1], syn1[2]);
        printf("\n");
    }
    printf("\n");

    multiple_input_multiple_output_nn(train_x_eg1, NUM_OF_FEATURES, z1_eg1, NUM_OF_HID_NODES, syn0);

    printf("Z1 of Eg1 : [%f] - [%f] - [%f]\n\n", z1_eg1[0],z1_eg1[1], z1_eg1[2]);
    printf("\n\n\r");

    /* Sigmoid Calculation is done for a1 */

    vector_sigmoid(z1_eg1, a1_eg1, NUM_OF_HID_NODES);
    printf("A1 of Eg1 : [%f] - [%f] - [%f]\n\n", a1_eg1[0],a1_eg1[1], a1_eg1[2]);
    printf("\n\n\r");

    /* z2 computation */
    z2_eg1 = multiple_input_single_output_nn(a1_eg1, syn1,NUM_OF_HID_NODES);

    printf("Result of Prediction : \n");
    printf("Z2 of Eg1 : %f\n\n", z2_eg1);
    yhat_eg1 = sigmoid(z2_eg1);
    printf("YHat Value is : %f\n\n", yhat_eg1);
    return 0;
}

