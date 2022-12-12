# DTensorProject (for KNU, student: Євген Гапонюк)

| File | Description |
| :--- | :--- |
| `DTensor_C/DTensor.h` | All function's variables (for c part) |
| `DTensor_C/DTensor.c` | All functions' definition (for c part) |
| `DTensor_C/DTensor_test.c` | Proof of work (for c part) |
| `DTensor_C/DTensor.h` | All function's variables (for cpp part) |
| `DTensor_C/DTensor.cpp` | All functions' definition (for cpp part) |
| `DTensor_C/DTensor_test.cpp` | Proof of work (for cpp part) |

## Function's description (cpp part)
# Constructors

Tensor item, or 1x1 matrix
```cpp
explicit Tensor(double element); // cpp
```
```c
Tensor TensorInitOne(double element); // c
```
Empty tensor but with right dimension and shape
```cpp
Tensor(int dimension, const int *shape); // cpp
```
```c
Tensor TensorInitZero(int dimension, const int *shape); // c
```
Tensor filled with elements (`LinkedList *array`) with right dimension and shape
```cpp
Tensor(LinkedList *array, int dimension, const int *shape); // cpp
```
```c
Tensor TensorInitFull(LinkedList* array, int dimension, const int *shape); // c
```
But in C all constructors overload to `TensorInit` <br>
Tensor from binary file
```cpp
Tensor from_file(const std::string &filename); // cpp
```
```c
Tensor from_file(const char filename[]); // c
```
# Functions
Reshpe tensor. params: new dimension and new shape, nothing special
```cpp
void reshape(int new_dimension, const int *new_shape); // cpp
```
```c
Tensor reshape(Tensor tensor, int new_dimension, const int *new_shape); // c
```
Return the pointer on list of elements.
```cpp
double* chain(); // cpp
```
```c
double* chain(Tensor tensor); // c
```
Print tensor.
```cpp
void print(); // cpp
```
```c
void print(Tensor tensor); // c
```
Write tensor in some stream (for example in file)
```cpp
void write(std::ostream &stream); // cpp
```
Write tensor to binary file.
```cpp
void to_file(const std::string &filename); // cpp
```
```c
void to_file(Tensor tensor, const char filename[]); // c
```
Copy tensor.
```cpp
Tensor &copy(); // cpp
```
```c
Tensor copy(Tensor tensor); // c
```
Some operators (cpp).
```cpp
Tensor &operator=(const Tensor &other);
Tensor &operator[](int i);
Tensor &operator+(const Tensor &other);
Tensor &operator-(const Tensor &other);
Tensor &operator*(const Tensor &other);
Tensor &operator/(const Tensor &other);
Tensor &operator+(double singleElement);
Tensor &operator-(double singleElement);
Tensor &operator*(double singleElement);
Tensor &operator/(double singleElement);
bool operator==(const Tensor &other);
```

For C we need to add own add/mul/sub.. functions and then use `unary_operation` or `binary_operation`
```c
double sum(double a, double b) {
    return a + b;
}

Tensor add(Tensor tensor, double singleElement) {
    Tensor result = TensorInit(tensor.number_dim, tensor.mShape);
    unary_operation(tensor, sum, tensor.mArray, singleElement, result.mArray, tensor.number_dim, tensor.mShape, 0);
    
    return result;
}
// Tensor test2 = add(test1, 3);
```
