#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H


void matrix_vector_multiply(double * input_vector,
                            int INPUT_LEN,
                            double * output_vector,
                            int OUTPUT_LEN,
                            double  weights_metrix[OUTPUT_LEN][INPUT_LEN]);



void hidden_layer_NN(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LEN,
                     double input_to_hidden_weights[HIDDEN_LEN][INPUT_LEN],
                     int OUTPUT_LEN,
                     double hidden_to_output_weights[OUTPUT_LEN][HIDDEN_LEN],
                     double * output_vector);



#endif // HIDDENLAYER_H
