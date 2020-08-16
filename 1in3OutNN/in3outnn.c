#include "in3outnn.h"
///
/// \brief agirlikli_toplam
/// \param input
/// \param agirlik
/// \param LEN
/// \return
///
double agirlikli_toplam(double * input, double * agirlik, int LEN){
    double output = 0.0;
    for (int i = 0 ; i < LEN; i++){
        output += input[i]*agirlik[i];
    }
    return output;
}

double multiInSingleOut(double * input, double * agirlik, int LEN){
    double predicted_value = 0.0;

    predicted_value = agirlikli_toplam(input,agirlik,LEN);
    return predicted_value;
}
/////////////////////////////////////////////////////////////////////////////////////////
/// \brief element_wise_multi
/// \param input
/// \param agirlik_vec
/// \param out_vec
/// \param LEN
///
///

void element_wise_multi(double input, double * agirlik_vec, double * out_vec, int LEN){
    for (int i = 0; i < LEN; i++) {
        out_vec[i]= input*agirlik_vec[i];
    }
}

void sinInMultiOutNN(double input, double * agirlik_vec, double * out_vec, int LEN){
    element_wise_multi(input, agirlik_vec, out_vec, LEN);
}
