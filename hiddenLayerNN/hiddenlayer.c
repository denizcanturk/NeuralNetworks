#include "hiddenlayer.h"

void matrix_vector_multiply(double * input_vector,
                            int INPUT_LEN,
                            double * output_vector,
                            int OUTPUT_LEN,
                            double  weights_metrix[OUTPUT_LEN][INPUT_LEN]){

    for (int i = 0 ; i < OUTPUT_LEN ; i++){

        for (int j = 0 ; j < INPUT_LEN ; j++){
            output_vector[i] = input_vector[i]*weights_metrix[i][j];
        }
    }
}

void hidden_layer_NN(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LEN,
                     double input_to_hidden_weights[HIDDEN_LEN][INPUT_LEN],
                     int OUTPUT_LEN,
                     double hidden_to_output_weights[OUTPUT_LEN][HIDDEN_LEN],
                     double * output_vector)
{


double hidden_predicted_vector[HIDDEN_LEN];
matrix_vector_multiply(input_vector, INPUT_LEN, hidden_predicted_vector,HIDDEN_LEN,input_to_hidden_weights );
matrix_vector_multiply(hidden_predicted_vector, HIDDEN_LEN, output_vector, OUTPUT_LEN, hidden_to_output_weights);

}
