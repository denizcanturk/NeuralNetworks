#include "simple_neural_networks.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EULAR 1.2548
int LEN=3;

double single_in_single_out(double input, double weight){
    return (input * weight);
}

double weighted_sum(double * input_vector, double * weigth_vector, int LEN){
   double output=0;

   for (int i = 0; i < LEN; i++){
       output += input_vector[i] * weigth_vector[i];
   }
   return output;
}

double multiple_input_single_output_nn(double * input_vector, double * weigth_vector, int LEN){ //This is just a wrapper
  return weighted_sum(input_vector, weigth_vector, LEN);
}

void elementwise_multiply(double input_scalar,
                          double * weight_vector,
                          double * output_vector,
                          int LEN){
    for (int i = 0; i < LEN; i++){
        output_vector[i] = input_scalar * weight_vector[i];
    }
}

void single_input_multiple_output(double input_scalar,
                                    double * weight_vector,
                                    double * output_vector,
                                    int LEN){
    elementwise_multiply(input_scalar,weight_vector,output_vector,LEN);

}


void vector_matrix_multiply(double * input_vector,
                            int INPUT_LEN,
                            double * output_vector,
                            int OUTPUT_LEN,
                            double weights_vector[OUTPUT_LEN][INPUT_LEN]){

    for (int i = 0; i < OUTPUT_LEN; i++){
        for (int j = 0; j < INPUT_LEN; j++)
        output_vector[i] += weighted_sum(&input_vector[j],&weights_vector[i][j], LEN);
    }
}

void multiple_input_multiple_output_nn(double * input_vector,
                                       int INPUT_LEN,
                                       double * output_vector,
                                       int OUTPUT_LEN,
                                       double weights_vector[OUTPUT_LEN][INPUT_LEN]){

    vector_matrix_multiply(input_vector,INPUT_LEN,output_vector,OUTPUT_LEN,weights_vector);
}

void hidden_layer_nn(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LEN,
                     double in_to_Hid_Weights[HIDDEN_LEN][INPUT_LEN],
                     int OUTPUT_LEN,
                     double hid_to_out_weights[OUTPUT_LEN][HIDDEN_LEN],
                     double * output_vector){
    double hidden_perdicted_output[HIDDEN_LEN];

    vector_matrix_multiply(input_vector,INPUT_LEN,hidden_perdicted_output,HIDDEN_LEN,in_to_Hid_Weights);
    vector_matrix_multiply(hidden_perdicted_output, HIDDEN_LEN,output_vector,OUTPUT_LEN,hid_to_out_weights);


}

double find_error(double input, double weight, double expected_value){
    return powf(((input*weight)-expected_value),2);
}

double find_error_simple(double predicted_value, double expected_value){
    return powf((predicted_value-expected_value),2);
}

void brute_force_learning(double inputs,
                          double weights,
                          double expected_value,
                          double step_amount,
                          double EPOCH){
    double  prediction,error,
            up_prediction, up_error,
            down_prediction, down_error;

    for (int i = 0; i < EPOCH; i++){
        prediction = inputs * weights;
        error = powf((prediction - expected_value),2);
        printf("[%d]\tError : %f, \tprediction : %f, \t\tWeight Changed to : %f\r\n", i+1, error,prediction, weights);
usleep(9998);
        up_prediction = inputs * (weights + step_amount);
        up_error = powf((expected_value - up_prediction),2);

        down_prediction = inputs * (weights - step_amount);
        down_error = powf((expected_value - down_prediction),2);

        if (down_error < up_error)
            weights = weights - step_amount;

        if (down_error > up_error)
            weights = weights + step_amount;
    }
}

void normalize_data(double * data_set,
                    double * normalized_data,
                    int LEN){
    int i;
    double max = data_set[0];
    /* Finding the max*/
    for (i = 1; i < LEN; i++){
        if (data_set[i] > max)
            max = data_set[i];
    }
    /* Normalization */
    for (int i = 0; i < LEN; i++){
        normalized_data[i] = data_set[i] / max;
    }

}

void weight_random_initialize(int HIDDEN_LEN,
                              int INPUT_LEN,
                              double weight_matrix[HIDDEN_LEN][INPUT_LEN]){
    /* Seeding random Number Generation */
    double d_rand;
    srand(2);
    for(int i = 0; i < HIDDEN_LEN; i++){
        for (int j = 0; j< INPUT_LEN; j++){
            //weight_matrix[i][j] = (rand()%10)/10;
            d_rand = (rand()%10);
            d_rand /= 10;
            weight_matrix[i][j] = d_rand;
        }
    }
}

void normalize_data_2d(int ROW, int COL,
                       double input_matrix[ROW][COL],
                       double output_matriX[ROW][COL]){
    double max = input_matrix[0][0];
    /* Finding the max*/
    for (int i = 1; i < ROW; i++){
        for (int j = 0; j < COL; j++ )
        if (input_matrix[i][j] > max)
            max = input_matrix[i][j];
    }

    /* Normalize the Shit Out Of It */
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++ ){
        output_matriX[i][j] = input_matrix[i][j] / max;
        //printf("%f\n", output_matriX[i][j]);
        }
    }
}

void weight_random_initialize_1D(double * output_vector,
                                 int LEN){
    /* Seeding random Number Generation */
    double d_rand;
    srand(2);
    printf("1 D Initilization : \n");
    for(int i = 0; i < LEN; i++){
            d_rand = (rand()%10);
            d_rand /= 10;
            output_vector[i] = d_rand;
            //printf("%f,%d\t", output_vector[i],i);
    }
}


double sigmoid(double x){
    double result = 1 / (1 + exp(-x));
    return result;
}

void vector_sigmoid(double * input_vector,
                    double * output_vector,
                    int LEN){
    for (int i = 0; i < LEN; i++){
        output_vector[i] = sigmoid(input_vector[i]);
    }
}
