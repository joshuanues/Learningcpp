//
// Created by joshua on 20/08/2019.
//
#include <cassert>
#include <sstream>
#include "matrix.h"

void _setget_test();
void _boolean_test();
void _mult_test();
void _suma_test();
void _resta_test();
void _det_test();

int main(){
    _boolean_test();
    _setget_test();
    _boolean_test();
    _mult_test();
    _suma_test();
    _resta_test();
    _det_test();
    return 0;
}

void _setget_test() {
    Matrix<int> m1(2,2);
    Matrix<int> m2(2,2);
    Matrix<int> m3(3,3);

    m1.set(1,1,3);
    m1.set(0,0,2);
    m1.set(1,0,-1);
    m1.set(0,1,0);

    m2.set(0,0,2);
    m2.set(1,1,3);
    m2.set(1,0,-1);
    m2.set(0,1,0);

    m3.set(0,0,3);
    m3.set(0,1,5);
    m3.set(0,2,7);
    m3.set(1,0,2);
    m3.set(1,1,6);
    m3.set(1,2,4);
    m3.set(2,0,0);
    m3.set(2,1,2);
    m3.set(2,2,8);

    //Assert
    int max = m1.max();
    bool t = m1.equals(&m2);
    int norm = m3.norm();

    assert(max == 3);//Assert max()
    assert(t);//assert equals(), set()
    assert(norm == 19);//assert norm()


}

void _boolean_test(){
    Matrix<int> m1(2,2);
    Matrix<int> m2(2,2);
    Matrix<int> m3(3,3);

    m1.set(1,1,3);
    m1.set(0,0,2);
    m1.set(1,0,-1);
    m1.set(0,1,0);

    m2.set(0,0,2);
    m2.set(1,1,3);
    m2.set(1,0,-1);
    m2.set(0,1,0);

    m3.set(0,0,3);
    m3.set(0,1,5);
    m3.set(0,2,7);
    m3.set(1,0,2);
    m3.set(1,1,6);
    m3.set(1,2,4);
    m3.set(2,0,0);
    m3.set(2,1,2);
    m3.set(2,2,8);

    Matrix<int> m4(2,2);
    m4.set(1,1,5);
    m4.set(0,0,5);
    m4.set(1,0,5);
    m4.set(0,1,5);

    m1.fill(5);//para assert fill()

    assert(m1.equals(&m4));//assert fill() llena m1 y compara con una matriz llena del mismo valor

    Matrix<int> m6(m1);//constructor copia

    assert(m1.equals(&m6));//assert constructor copia

    assert(m1.get(1,1) == 5);//assert get

    assert(m1.length() == 2);//assert length()

    assert(m2.min() == -1);//assert min()


    Matrix<int> m7(1,1);

    m7.set(0,0,1);

    m7.save_to_file("test.txt");//guardar matriz en archivo

    std::ifstream file;
    std::string expression;
    expression = "/**1**/";

    file.open("test.txt");
    std::string fread;
    std::string tread;
    while(!file.eof()){
        std::getline(file, fread);
        tread += fread;
    }
    file.close();

    assert(expression == tread);//testea que efectivamente este la matriz en el txt

    m1.disp();//muestra m1

    //Assert booleans

    Matrix<int> id(2,2);
    id.set(0,0,1);
    id.set(1,1,1);

    assert(id.is_identity());//assert is_identity()
    assert(id.is_diag());//assert is_diag()
    assert(id.is_symmetric());//assert is_symmetric()
    assert(id.is_square());//assert is_square()

    Matrix<int> vec(1, 0);

    assert(vec.is_vector());//assert is_vector()
    assert(m1 == m4);
    assert(m1 != m2);
}

void _mult_test(){
    Matrix<int> m3(3,3);
    m3.set(0,0,3);
    m3.set(0,1,5);
    m3.set(0,2,7);
    m3.set(1,0,2);
    m3.set(1,1,6);
    m3.set(1,2,4);
    m3.set(2,0,0);
    m3.set(2,1,2);
    m3.set(2,2,8);
    //Assert operations
    m3 *= (5);
    m3.disp();

    const Matrix<int> mult = m3*=(5);
    mult.disp();

    m3 += &m3;//suma consigo misma
    m3.disp();

    m3 -= &m3;
    m3.disp();

    m3.fill(2);
    m3.disp();
    m3 *= m3;
    m3.disp();
}

void _suma_test(){
    Matrix<int> m1(2,2);

    m1.set(1,1,3);
    m1.set(0,0,2);
    m1.set(1,0,-1);
    m1.set(0,1,0);
    m1 += &m1;//suma consigo misma
    m1.disp();
}

void _resta_test(){
    Matrix<int> m1(2,2);

    m1.set(1,1,3);
    m1.set(0,0,2);
    m1.set(1,0,-1);
    m1.set(0,1,0);
    m1 -= &m1;

    Matrix<int> zeros(2,2);
    m1.disp();
    assert(m1 == zeros);//verifica que m1-m1 es una matriz de ceros.

    Matrix<double> zeros2(6,6);
    Matrix<double> ones(6,6);
    ones.fill(1);
    Matrix<double> test(6,6);
    test.fill(-1);
    zeros2 -= &ones;
    assert(test == zeros2);


}

void _det_test() {
    Matrix<int> m1(2,2);

    m1.set(1,1,3);
    m1.set(0,0,2);
    m1.set(1,0,-1);
    m1.set(0,1,0);

    int det = m1.det();
    assert(det == 6);//assert det()
}

