/* File DTensor_test.c
    Test some DTensor functions
    Done by Evgeny Hapoyunyuk (group 2)
*/
#include "DTensor.h"
#include "DTensor.c"
#include "stdio.h"

double sum(double a, double b) {
    return a + b;
}

Tensor add(Tensor tensor, double singleElement) {
    Tensor result = TensorInit(tensor.number_dim, tensor.mShape);
    unary_operation(tensor, sum, tensor.mArray, singleElement, result.mArray, tensor.number_dim, tensor.mShape, 0);
    
    return result;
}

int main(int argc, char **argv) {
    const int dim = 2;
    const int n = 2;
    const int m = 3;

    int shape[2] = {2, 3};
    int values[6] = {0, 1, 2, 3, 4, 5};
    Tensor test1 = TensorInit(dim, shape);

    Tensor test2 = add(test1, 3);

    to_file(test2, "test2.dte");

    Tensor tensor_from_file = from_file("test2.dte");

    print(tensor_from_file);

    print(test2);
    const int new_shape[2] = {3, 2};
    Tensor test3 = reshape(test2, 2, new_shape);

    print(test3);

    return 0;
}