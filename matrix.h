#include <iostream>
#include <string>
#include <stdexcept>

template<class T>
class Matrix {
private:
    T **mat; // Store the matrix
    int n = 0; // Number of columns
    int m = 0; // Number of rows
public:
	Matrix(const Matrix &m); // Copy constructor
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

// Constructor to destructor
template <class T>
Matrix<T>::Matrix(const Matrix &m){
    *this = mat;
}

template <class T>
Matrix<T>::Matrix(int n) {
    this->n = n;
    mat = new T*[this->n];
    for(int i = 0; i < n; i++ ){
        mat[i] = 0;
    }
}

template<class T>
Matrix<T>::Matrix(int n, int m) {
    this->n = n;
    this->m = m;
    mat = new T*[this->n];
    for(int i = 0; i < n; i++){
        mat[i] = new T[this->m];
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = 0;
        }
    }
}

template<class T>
Matrix<T>::~Matrix(){
    delete[] mat;
}

//Setters and getters
template<class T>
void Matrix<T>::set(int i, int j, T value) {
    mat[i][j] = value;
}

template<class T>
T Matrix<T>::get(int i, int j) const {
    return mat[i][j];
}

template<class T>
void Matrix<T>::fill(T value) {
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = value;
        }
    }
}

//Dimensions
template<class T>
int *Matrix<T>::size() const {
    int *dimensions = new int[2];
    dimensions[0] = n;
    dimensions[1] = m;
    return dimensions;
}

template<class T>
int Matrix<T>::length() const {
    if(n > m){
        return n;
    }
    else{
        return m;
    }
}

//Values
template<class T>
T Matrix<T>::max() const {
    T candidate = mat[0][0];
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] > candidate){
                candidate = mat[i][j];
            }
        }
    }
    return candidate;
}

template<class T>
T Matrix<T>::min() const {
    T candidate = mat[0][0];
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] < candidate){
                candidate = mat[i][j];
            }
        }
    }
    return candidate;
}

template<class T>
T Matrix<T>::det() const {
    return nullptr;
}

template<class T>
T Matrix<T>::norm() const {
    return nullptr;
}

//utilitary functions
template<class T>
void Matrix<T>::disp() const {
    std::cout<< "/**"<< std::endl;
    for(int i=0; i< this->n; i++){
        for(int j=0; j< this->m; j++) {
            std::cout<< mat[i][j];
        }
        std::cout<< "" <<std::endl;
    }
    std::cout<< "**/"<<std::endl;
}

template<class T>
void Matrix<T>::save_to_file(std::string filename) const {

}

template<class T>
Matrix<T> *Matrix<T>::clone() const {
    return nullptr;
}

//Booleans
template<class T>
bool Matrix<T>::equals(Matrix<T> *mat) const {
    return false;
}

template<class T>
bool Matrix<T>::is_diag() const {
    return false;
}

template<class T>
bool Matrix<T>::is_identity() const {
    return false;
}

template<class T>
bool Matrix<T>::is_symmetric() const {
    return false;
}

template<class T>
bool Matrix<T>::is_square() const {
    return false;
}

template<class T>
bool Matrix<T>::is_vector() const {
    return false;
}

template<class T>
bool Matrix<T>::operator==(const Matrix<T> &matrix) const {
    return false;
}

template<class T>
bool Matrix<T>::operator!=(const Matrix<T> &matrix) const {
    return false;
}


//Mathematical operations
template<class T>
Matrix<T> *Matrix<T>::transpose() const {
    return nullptr;
}

template<class T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &matrix) {
    return 0;
}

template<class T>
Matrix<T> *Matrix<T>::operator*=(const Matrix<T> &matrix) const {
    return nullptr;
}

template<class T>
Matrix<T> &Matrix<T>::operator*=(T a) {
    return 0;
}

template<class T>
Matrix<T> *Matrix<T>::operator*=(T a) const {
    return nullptr;
}

template<class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> *matrix) {
    return 0;
}

template<class T>
Matrix<T> *Matrix<T>::operator+(const Matrix<T> &matrix) const {
    return nullptr;
}

template<class T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> *matrix) {
    return 0;
}

template<class T>
Matrix<T> *Matrix<T>::operator-(const Matrix<T> &matrix) const {
    return nullptr;
}

template<class T>
void Matrix<T>::normalize() {

}

//Bonus
template<class T>
Matrix<T> Matrix<T>::inverse() const {
    return Matrix<T>();
}
