//
// Created by joshua on 20/08/2019.
//
#include <cassert>
#include "matrix.h"

int main(){
    //inicializar
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

    //Assert
    int max = m1.max();

    int det = m1.det();
    bool t = m1.equals(&m2);
    int norm = m3.norm();

    assert(max == 3);//Assert max()
    assert(t);//assert equals()
    assert(det == 6);//assert det()
    assert(norm == 19);//assert norm()

    m1.fill(5);//para assert fill()

    assert(m1.equals(&m4));//assert fill() llena m1 y compara con una matriz llena del mismo valor
}

