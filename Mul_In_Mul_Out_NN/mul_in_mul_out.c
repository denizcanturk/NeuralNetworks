#include "mul_in_mul_out.h"

void vector_matrix_multiply(double * input_vector,
                            int INPUT_LEN,
                            double * output_vector,
                            int OUTPUT_LEN,
                            double weights_vector[OUTPUT_LEN][INPUT_LEN]){
    for (int i = 0 ; i < OUTPUT_LEN; i++){

        for (int j = 0 ; j < INPUT_LEN ; j++){
            output_vector[i] += input_vector[j] * weights_vector[i][j];
        }
    }
}

void mul_in_mul_out(double * input_vector,
                    int INPUT_LEN,
                    double * output_vector,
                    int OUTPUT_LEN,
                    double weights_vector[OUTPUT_LEN][INPUT_LEN]){

    vector_matrix_multiply(input_vector,
                           INPUT_LEN,
                           output_vector,
                           OUTPUT_LEN,
                           weights_vector);

}
