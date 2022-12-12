/* File DTensor.h
    Realization of Tensor structure
    Done by Evgeny Hapoyunyuk (group 2)
    Headers for Tensor struct
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// TensorInit overloading (spent 3 hours on this...)
#define TENSOR_INIT_1_ARGS(x) TensorInitOne(x)
#define TENSOR_INIT_2_ARGS(x, y) TensorInitZero(x, y)
#define TENSOR_INIT_3_ARGS(x, y, z) TensorInitFull(x, y, z)

#define GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4
#define TENSOR_INIT_MACRO_CHOOSER(...) GET_4TH_ARG(__VA_ARGS__, TENSOR_INIT_3_ARGS, TENSOR_INIT_2_ARGS, TENSOR_INIT_1_ARGS, )

#define TensorInit(...) TENSOR_INIT_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

/* Structure for tensor's elements */
typedef struct LinkedList LinkedList;
struct LinkedList{
    double value;
    LinkedList *next; 
};

/* Base structure of tensor */
typedef struct Tensor Tensor;
struct Tensor {
    int number_dim;
    LinkedList *mArray;
    int *mShape;
};

/**
 * Functions for work with LinkedList elements (we use it in tensor as *mArray)
    @param int dimension - tensor's dimension
    @param const int *shape - tensor's shape list
    @param int dimLevel - level of tensor (0 for default)
*/
LinkedList* create_ndim_array(int dimension, const int *shape, int dimLevel);

void delete_ndim_array(LinkedList* array, int dimension, const int *shape, int dimLevel);

LinkedList* copy_ndim_array(LinkedList *array, int dimension, const int *shape, int dimLevel);

/**
 * Main constructor, from technical task
 * 
 * @param LinkedList* масив даних тензору
 * @param int dimension: натуральне число – кількість N розмірностей тензору; 
 * @param const int *shape: вказівник на натуральні числа, - це масив з N чисел, величини першоЇ, другої … N-тої розмірності даного тензору
*/
Tensor TensorInitFull(LinkedList* array, int dimension, const int *shape);

Tensor TensorInitZero(int dimension, const int *shape);

Tensor TensorInitOne(double element);

/**
 * Function for getitem
    @param Tensor tensor - what tensor we use for get element
    @param int i - element index
    @return Tensor element
*/
Tensor at(Tensor tensor, int i);

int *shape(Tensor tensor);

/**
 * Functions for work with chain (list af tensor's double elements)
    @param Tensor tensor - what tensor we use for create/get/fill chain
    @param LinkedList* array - array for fill or creat
    @param int dimLevel - level of tensor (0 for default)
*/

void create_chain(Tensor tensor, LinkedList* array, int dimLevel, double *resArray, int startIndex);

double* chain(Tensor tensor);

void fill_array_from_chain(Tensor tensor, LinkedList* array, int dimLevel, double *_chain, int startIndex);

/**
 * Reshape tensor
 *
 * @param new dimension and new shape, nothing special 
 */
Tensor reshape(Tensor tensor, int new_dimension, const int *new_shape);

// Copy object
Tensor copy(Tensor tensor);

void print_ndim_array(LinkedList* array, int dimension, int *shape, int dimLevel);

void print(Tensor tensor);

/**
 * Function unary operation
    @param Tensor tensor - what tensor we use for get element
    @param double (*ptr2Func)(double, double) - function for operation
    @param LinkedList* array - tensor's elements
    @param double singleElement - element for make operation with tensor
    @param LinkedList* resArray - array after operation
    @param int dimension, const int *shape, int dimLevel - base of tensor
    @noreturn
*/
void unary_operation(Tensor tensor, double (*ptr2Func)(double, double), LinkedList* array, double singleElement, LinkedList* resArray, int dimension, const int *shape, int dimLevel);

/**
 * Function binary operation
    @param Tensor tensor - what tensor we use for get element
    @param double (*ptr2Func)(double, double) - function for operation
    @param LinkedList* array - tensor's elements
    @param LinkedList* array2 - other tensor's elements
    @param LinkedList* resArray - array after operation
    @param int dimension, const int *shape, int dimLevel - base of tensor
    @noreturn
*/
void binary_operation(Tensor tensor, double (*ptr2Func)(double, double ), LinkedList* array1, LinkedList* array2, LinkedList* resArray, int dimensional, const int *shape, int dimLevel);

/**
 * Function for check if we can do operations with tensors
    @param int dim1 - dimension of first tensor
    @param int dim2 - dimension of second tensor
    @param const int *shape1 - first tensor's shape
    @param const int *shape2 - second tensor's shape
    @return int/bool if it is true
*/
int check_same(int dim1, int dim2, const int *shape1, const int *shape2);

/**
 * Function for check if two tensors are equal
    @param LinkedList* array1 - first tensor's elements
    @param LinkedList* array2 - second tensor's elements
    @param int dimension, const int *shape, int dimLevel - base of tensor
    @return int/bool if it is true
*/
int is_equal(LinkedList* array1, LinkedList* array2, int dimensional, const int *shape, int dimLevel);

void set_marray(Tensor tensor, LinkedList* new_marray);

/**
 * Function load tensor in binary file
    @param Tensor tensor - tensor to load
    @param const char filename[] - file name (.dte)
*/
void to_file(Tensor tensor, const char filename[]);

/**
 * Function get tensor from binary file
    @param const char filename[] - file name (.dte)
*/
Tensor from_file(const char filename[]);
