//
// Created by joshua on 12/08/2019.
//

#include "matrix.h"

int main(){
    Matrix<int> m1(3,3);

    m1.fill(1);

    m1.set(0,0,3);
    m1.set(1,1,2);
    m1.set(2,2,1);

    int a = m1.get(0,0);

    m1.set(0,1,a);

    m1.disp();

    /* imprime el maximo y minimo*/
    int max = m1.max();
    std::cout<< max << std::endl;

    int min = m1.min();
    std::cout<< min << std::endl;

    int det = m1.det();
    std::cout<< det << std::endl;

}
