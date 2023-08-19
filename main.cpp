#include "eigen/core.h"
#include <iostream>

int main()
{
    std::cout << "Studying eigen ..." << std::endl;
    Matrix2d mat1;
    MatrixXd mat2(2, 2);
    Matrix2d mat3(mat1);
    Matrix2d mat4;
    mat4 = mat1;
    MatrixXd mat5(mat2);
    MatrixXd mat6(2, 2);
    mat6 = mat2;
    return 0;
}