#ifndef IN3OUTNN_H
#define IN3OUTNN_H

double agirlikli_toplam(double * input, double * agirlik, int LEN);
void element_wise_multi(double input, double * agirlik_vec, double * out_vec, int LEN);
void sinInMultiOutNN(double input, double * agirlik_vec, double * out_vec, int LEN);


#endif // IN3OUTNN_H
