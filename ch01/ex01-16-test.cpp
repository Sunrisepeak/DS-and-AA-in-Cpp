#include <iostream>
#include "ex01-16.h"

int main() {
    Matrix<bool> bM;    //test zero-parameter constructor
    bM.resize(3, 3);    //test resize()
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            bM[i][j] = (i + j) % 2;
        }
    }

    std::cout << "Bool Matrix:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "\t";
        for (int j = 0; j < 3; j++) {
            std::cout << bM[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}