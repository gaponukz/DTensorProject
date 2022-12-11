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
explicit Tensor(double element);
```
Empty tensor but with right dimension and shape
```cpp
Tensor(int dimension, const int *shape);
```
Tensor filled with elements (`LinkedList *array`) with right dimension and shape
```cpp
Tensor(LinkedList *array, int dimension, const int *shape);
```
Tensor from binary file
```cpp
Tensor from_file(const std::string &filename);
```
# Functions
Reshpe tensor. params: new dimension and new shape, nothing special
```cpp
void reshape(int new_dimension, const int *new_shape);
```
Return the pointer on list of elements.
```cpp
double* chain();
```
Print tensor.
```cpp
void print();
```
Write tensor in some stream (for example in file)
```cpp
void write(std::ostream &stream);
```
Write tensor to binary file.
```cpp
void to_file(const std::string &filename);
```
Copy tensor.
```cpp
Tensor &copy();
```
Some operators.
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
