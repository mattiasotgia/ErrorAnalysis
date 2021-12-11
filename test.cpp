/*
    ErrorAnalysis - error propagation toolset - C++
    Author: Mattia Sotgia
    Version: 0.0 alpha
*/

#include<iostream>
#include"ErrorAnalysis.h"

int main(){

    double param[2] = {62.00, 1.60};
    double err[2] = {0.12, 0.02};

    std::cout << "Valore g = " << get_pValue("4*pi*x/pow(y, 2)", param) << " +- " << get_pError("4*pi*x/pow(y, 2)", param, err) << std::endl;
    return 0;
}

