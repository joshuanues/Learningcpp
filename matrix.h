#include <iostream>
#include <string>
#include <stdexcept>

template<class T>
class Matrix {
private:
    T *mat; // Store the matrix
    int n = 0; // Number of columns
    int m = 0; // Number of rows
public:
	Matrix(); // Copy constructor
    Matrix(int n); // Constructor, vector like [1xn]
    Matrix(int n, int m); // Constructor [nxm]
    ~Matrix(); // Destructor

    // Setters and gettersc
    void set(int i, int j, T value); // Set value to (i,j) <row,column>
    T get(int i, int j) const; // Get value from (i,j) <row,column>
    void fill(T value); // Fill all the matrix with a value

    // Dimensions
    int *size() const; // Returns [n, m] as a int vector
    int length() const; // Return max dimension, usefull for vectors

    // Values
    T max() const; // Maximum value of the matrix
    T min() const; // Minimum value of the matrix
    T det() const; // Calculate determinant
    T norm() const; // Get norm of vector

    // Utilitary functions
    void disp() const; // Display matrix to console
    void save_to_file(std::string filename) const; // Save
    Matrix<T> *clone() const; // Clone the matrix

    // Booleans
    bool equals(Matrix<T> *mat) const; // Matrix has same values as another
    bool is_diag() const; // Matrix is diagonal
    bool is_identity() const; // Check if matrix is identity
    bool is_symmetric() const; // Check if matrix is symmetric
    bool is_square() const; // Check if matrix is square nxn
    bool is_vector() const; // Check if matrix is vector
    bool operator==(const Matrix<T> &matrix) const; // Equal operator
    bool operator!=(const Matrix<T> &matrix) const; // Not equal operator

    // Mathematical operation
    Matrix<T> *transpose() const; // Transpose the matrix and return a new matrix
    Matrix<T> &operator*=(const Matrix<T> &matrix); // Multiplication with self
    Matrix<T> *operator*=(const Matrix<T> &matrix) const; // Return a new matrix
    Matrix<T> &operator*=(T a); // Multiply a constant with self
    Matrix<T> *operator*=(T a) const; // Multiply matrix by a constant and return new matrix
    Matrix<T> &operator+=(const Matrix<T> *matrix); // Add a matrix with self
    Matrix<T> *operator+(const Matrix<T> &matrix) const; // Add and return a new matrix
    Matrix<T> &operator-=(const Matrix<T> *matrix); // Substract a matrix with self
    Matrix<T> *operator-(const Matrix<T> &matrix) const; // Substract and return a new matrix
    void normalize(); // Normalize the matrix

    // Bonus (1pt), returns inverse of the Matrix
    Matrix<T> inverse() const;
};