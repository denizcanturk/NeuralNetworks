#include "multiinsingleout.h"

///
/// \brief weighted_sum
/// \param input
/// \param weight
/// \param LEN
/// \return
///
double weighted_sum(double * input, double * weight, int LEN){
    double results= 0.0;
    for (int i =0; i< LEN; i++){
            results+= input[i]*weight[i];
    }
    return results;
}

double multiInSingleOut(double * input, double * weight, int LEN){
    double predicted_result = 0.0;
    predicted_result = weighted_sum(input, weight, LEN);
    return predicted_result;
}
