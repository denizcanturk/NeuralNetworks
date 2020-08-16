#include "simple_neural_networks.h"
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


int main()
{
    printf("Hello AI World with Inference...");

    const int nips = 256;
    const int nops = 10;

    const Data final_predict = build("test.data", nips, nops);
    const NeuralNetwork_Type loaded_model = NNload("mymodel.nn");

    const float * const in = final_predict.in[1];
    const float * const pd = NNpredict(loaded_model, in);

    NNprint(pd, final_predict.nops);
    NNfree(loaded_model);
    dfree(final_predict);

   return 0;
}
