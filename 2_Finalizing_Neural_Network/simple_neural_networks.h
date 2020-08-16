#ifndef SIMPLE_NEURAL_NETWORK_H
#define SIMPLE_NEURAL_NETWORK_H


double single_in_single_out(double input, double weight);
double weighted_sum(double * input_vector, double * weigth_vector, int LEN);
double multiple_input_single_output_nn(double * input_vector, double * weigth_vector, int LEN);

void elementwise_multiply(double input,
                          double * weight_vector,
                          double * output_vector,
                          int LEN);

void single_input_multiple_output(double input_scalar,
                                    double * weight_vector,
                                    double * output_vector,
                                    int LEN);

void vector_matrix_multiply(double * input_vector,
                            int INPUT_LEN,
                            double * output_vector,
                            int OUTPUT_LEN,
                            double weights_vector[OUTPUT_LEN][INPUT_LEN]);

void multiple_input_multiple_output_nn(double * input_vector,
                                        int INPUT_LEN,
                                        double * output_vector,
                                        int OUTPUT_LEN,
                                        double weights_vector[OUTPUT_LEN][INPUT_LEN]);


void hidden_layer_nn(double * input_vector,
                     int INPUT_LEN,
                     int HIDDEN_LEN,
                     double in_to_Hid_Weights[HIDDEN_LEN][INPUT_LEN],
                     int OUTPUT_LEN,
                     double hid_to_out_weights[OUTPUT_LEN][HIDDEN_LEN],
                     double * output_vector);

double find_error(double input,
                  double weight,
                  double expected_value);

double find_error_simple(double yhat,
                         double y);

void brute_force_learning(double inputs,
                          double weights,
                          double expected_value,
                          double step_amount,
                          double EPOCH);

void normalize_data(double * data_set,
                    double * normalized_data,
                    int LEN);

void weight_random_initialize(int HIDDEN_LEN,
                              int INPUT_LEN,
                              double weight_matrix[HIDDEN_LEN][INPUT_LEN]);

void normalize_data_2d(int ROW, int COL,
                       double input_matrix[ROW][COL],
                       double output_matriX[ROW][COL]);

void weight_random_initialize_1D(double * output_vector,
                                 int LEN);

double sigmoid(double x);

void vector_sigmoid(double * input_vector,
                    double * output_vector,
                    int LEN);
#endif // SIMPLE_NEURAL_NETWORK_H
