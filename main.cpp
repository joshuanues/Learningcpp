//
// Created by joshua on 12/08/2019.
//

#include "matrix.h"

int main(){
    Matrix<int> m1(3,3);
    m1.set(0,0,3);
    m1.set(1,1,2);
    m1.set(2,2,1);
    int a = m1.get(0,0);
    m1.set(0,1,a);
    m1.disp();
}
