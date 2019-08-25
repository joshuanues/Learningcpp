#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

template<class T>
class Matrix {
private:
    T **mat; // Store the matrix
    int n = 0; // Number of columns
    int m = 0; // Number of rows
public:
	Matrix(const Matrix &m); // Copy constructor
	Matrix();//Void contructor
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
    void save_to_file(const std::string& filename) const; // Save
    Matrix<T> *clone() const; // Clone the matrix

    // Booleans
    bool equals(Matrix<T> *matrix) const; // Matrix has same values as another
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
    int *a = m.size();
    n = a[0];
    this->m = a[1];
    mat = m.mat;
}

template <class T>
Matrix<T>::Matrix(int n) {
    this->n = n;
    this->m = 0;
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
    if (n == 2)
    {
        return (mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0]);
    }
    else
    {
        int Actual = 0;
        int k = 0;
        int Numero = 0;
        short Multiplicador;

        Matrix<T> matt(n-1 ,n-1);

        for (int i = 0; i<(n-1); i++)
            matt.mat[i] = new int[n-1];

        for (int l = 0; l < n; l++) // Desarrollo por filas
        {
            for (int j = 1; j < n; j++) // Creo una nueva matriz adjunta
            {
                for (int i = 0; i < n; i++)
                {
                    if (i != l)
                    {
                        matt.mat[k][j-1] = mat[i][j];
                        k++;
                    }
                }
                k = 0;
            }

            if ( l % 2 != 0)
                Multiplicador = -1;
            else
                Multiplicador = 1;
            Numero += (mat[l][0]*matt.det()*Multiplicador);
        }
        return Numero;
    }
}

template<class T>
T Matrix<T>::norm() const {
    int pret = 0;
    int pret2;
    for(int i = 0; i < m; i++){
        pret2 = 0;
        for(int j = 0; j < n; j++){
            pret2 += mat[j][i];
        }
        if(pret2 > pret){
            pret = pret2;
        }
    }
    return pret;
}

//utilitary functions
template<class T>
void Matrix<T>::disp() const {
    std::string expression;
    expression = "/**\n";
    for(int i=0; i< this->n; i++){
        for(int j=0; j< this->m; j++) {
            expression += std::to_string(mat[i][j])+" ";
        }
        expression+="\n";
    }
    expression += "**/";
    std::cout << expression << std::endl;
}

template<class T>
void Matrix<T>::save_to_file(const std::string& filename) const{
    std::ofstream archivo;
    std::string expression;
    expression = "/**\n";
    for(int i=0; i< this->n; i++){
        for(int j=0; j< this->m; j++) {
            expression += std::to_string(mat[i][j]);
        }
        expression+="\n";
    }
    expression += "**/";
    archivo.open(filename);
    archivo << expression << std::endl;
    archivo.close();
}

template<class T>
Matrix<T> *Matrix<T>::clone() const {
    Matrix<T> matrix(n ,m);
    matrix.mat = mat;
    return matrix;
}

//Booleans
template<class T>
bool Matrix<T>::equals(Matrix<T> *matrix) const {
    if(matrix->size()[0] != n || matrix->size()[1] != m){
        return false;
    }
    else{
        for(int i= 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != matrix->mat[i][j]){
                    return false;
                }
            }
        }
    }
    return true;
}

template<class T>
bool Matrix<T>::is_diag() const {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i != j){
                if(mat[i][j] != 0){
                    return false;
                }
            }
        }
    }
    return true;
}

template<class T>
bool Matrix<T>::is_identity() const {
    if(this->is_diag()){
        for(int i = 0; i < n; i++){
            if(mat[i][i] != 1){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

template<class T>
bool Matrix<T>::is_symmetric() const {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(mat[i][j] != mat[j][i]){
                return false;
            }
        }
    }
    return true;
}

template<class T>
bool Matrix<T>::is_square() const {
    return n == m;
}

template<class T>
bool Matrix<T>::is_vector() const {
    return m == 0 && n > 0;
}

template<class T>
bool Matrix<T>::operator==(const Matrix<T> &matrix) const {
    if(n != matrix.size()[0] || m != matrix.size()[1]){
        return false;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] != matrix.get(i,j)){
                return false;
            }

        }
    }
    return true;
}

template<class T>
bool Matrix<T>::operator!=(const Matrix<T> &matrix) const {
    if(n != matrix.size()[0] || m != matrix.size()[1]){
        return true;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] != matrix.get(i,j)){
                return true;
            }
        }
    }
    return false;
}

//Mathematical operations
template<class T>
Matrix<T> *Matrix<T>::transpose() const {
    Matrix<T> matrix(n,m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix.mat[i][j] = mat[j][i];
        }
    }
    return &matrix;
}

template<class T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &matrix) {
    Matrix<T> matt(n, m);
    T sol = 0;
    for(int i = 0; i < n; i++){
        for( int j = 0; j < matrix.size()[1]; j++){
            for(int k = 0; k < m; k++){
                sol += mat[i][k] * matrix.mat[k][j];
            }
            matt.mat[i][j] = sol;
            sol = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            this->set(i,j, matt.get(i,j));
        }
    }
    return *this;
}

template<class T>
Matrix<T> *Matrix<T>::operator*=(const Matrix<T> &matrix) const {
    Matrix<T> matt(n, m);
    T sol = 0;
    for(int i = 0; i < n; i++){
        for( int j = 0; j < matrix.size()[1]; j++){
            for(int k = 0; k < m; k++){
                sol += mat[i][k] * matrix.mat[k][j];
            }
            matt.mat[i][j] = sol;
            sol = 0;
        }
    }
    return matt;
}

template<class T>
Matrix<T> &Matrix<T>::operator*=(T a) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] *= a;
        }
    }
    return *this;
}

template<class T>
Matrix<T> *Matrix<T>::operator*=(T a) const {
    Matrix<T> matrix(n , m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix.mat = mat[i][j]*a;
        }
    }
    return matrix;
}

template<class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> *matrix) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] += matrix->mat[i][j];
        }
    }
    return *this;
}

template<class T>
Matrix<T> *Matrix<T>::operator+(const Matrix<T> &matrix) const {
    Matrix<T> matt(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matt->mat[i][j] = mat[i][j] + matrix->mat[i][j];
        }
    }
    return this;
}

template<class T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> *matrix) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] -= matrix->mat[i][j];
        }
    }
    return *this;
}

template<class T>
Matrix<T> *Matrix<T>::operator-(const Matrix<T> &matrix) const {
    Matrix<T> matt(n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matt->mat[i][j] = mat[i][j] - matrix->mat[i][j];
        }
    }
    return this;
}

template<class T>
void Matrix<T>::normalize() {
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] == mat[i][j]/this->norm();
        }
    }
}

//Bonus
template<class T>
Matrix<T> Matrix<T>::inverse() const {
    return Matrix<T>();
}

template<class T>
Matrix<T>::Matrix() {
    n = 0;
    m = 0;
}
