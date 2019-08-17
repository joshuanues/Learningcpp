//
// Created by joshua on 12/08/2019.
//

#include "matrix.h"

int main(){
    Matrix<int> m1(2,2);

    //m1.fill(1);

    m1.set(0,0,2);
    m1.set(1,1,3);
    m1.set(1,0,-1);
    m1.set(0,1,0);

    int a = m1.get(0,0);

    //m1.set(0,1,a);
    //m1.fill(1);
    m1.disp();

    Matrix<int> m2(2,2);

    m2.set(0,0,2);
    m2.set(1,1,3);
    m2.set(1,0,-1);
    m2.set(0,1,0);

    bool t = m1.equals(&m2);
    /* imprime el maximo y minimo*/
    int max = m1.max();
    std::cout<< "max: " << max << std::endl;

    int min = m1.min();
    std::cout<< "min: "<< min << std::endl;

    int det = m1.det();
    std::cout<< "det: " << det << std::endl;

    std::cout<< "t o f: " << t << std::endl;

}
