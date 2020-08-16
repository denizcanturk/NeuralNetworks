#ifndef MUL_IN_MUL_OUT_H
#define MUL_IN_MUL_OUT_H
/////////////////////////////////
/// \brief vector_matrix_multiply
/// \param input_vector
/// \param INPUT_LEN
/// \param output_vector
/// \param OUTPUT_LEN
/// \param weights_vector
///
void vector_matrix_multiply(double * input_vector,
                            int INPUT_LEN,
                            double * output_vector,
                            int OUTPUT_LEN,
                            double weights_vector[OUTPUT_LEN][INPUT_LEN]);

///////////////////////////
/// \brief mul_in_mul_out
/// \param input_vector
/// \param INPUT_LEN
/// \param output_vector
/// \param OUTPUT_LEN
/// \param weights_vector
///
void mul_in_mul_out(double * input_vector,
                    int INPUT_LEN,
                    double * output_vector,
                    int OUTPUT_LEN,
                    double weights_vector[OUTPUT_LEN][INPUT_LEN]);

#endif // MUL_IN_MUL_OUT_H
