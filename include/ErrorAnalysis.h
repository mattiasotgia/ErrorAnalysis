/*
    ErrorAnalysis - error propagation toolset - C++
    Author: Mattia Sotgia
    Version: 0.2 alpha
*/

/**
 * @brief Requirement: 
 * ROOT include-flags -> `root-config --glibs --cflags`
 * If used in ROOT macro, use gSystem->Load()
 */

#ifndef LABTOOLS_ErrorPropagation
#define LABTOOLS_ErrorPropagation

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include<TFormula.h>
#include<TMath.h>

namespace ErrorAnalysis {
    typedef std::string fFormula;

    /**
     * @brief Get the pValue object
     * @a get_pValue(sFormula, *values) - c++ function to compute Median value, or evaluate f in point.
     * 
     * @param sFormula std::string passed, is the formula used to compute error. Its implementation is the same 
     * as in the TFormula ROOT class. It recognise standard c++ math operators as sqrt(), pow(), etc...
     * The class @a TFormula supports unlimited number of variables and parameters. By default 
     * the names which can be used for the variables are x,y,z,t or x[0],x[1],x[2],x[3],....x[N]
     * for N-dimensional formulas.
     * @param values Array of variables (its dimension need to be exactly the same as the function dimension)
     * @return Double_t Value of funtion passed computed in point
     */
    Double_t get_pValue(fFormula sFormula, Double_t* values);

    /**
     * @brief Get the pError object
     * get_pError(sFormula, *values, *errors) - c++ function to compute Error Analysis on a `double* values` array and 
     * relative errors expressed in double* errrors array, return SquareRoot of SqaredSum of errore propagated by 
     * changing every parameter in its error range;
     * 
     * @param sFormula std::string passed, is the formula used to compute error. Its implementation is the same 
     * as in the TFormula ROOT class. It recognise standard c++ math operators as sqrt(), pow(), etc...
     * The class @a TFormula supports unlimited number of variables and parameters. By default 
     * the names which can be used for the variables are x,y,z,t or x[0],x[1],x[2],x[3],....x[N]
     * for N-dimensional formulas.
     * @param values Array of variables (its dimension need to be exactly the same as the function dimension)
     * @param errors Array of variable's errors (its dimension need to be exactly the same as the function dimension)
     * @return Double_t SquareRoot of SqaredSum of errore propagated by changing every parameter in its error range;
     */
    Double_t get_pError(fFormula sFormula, Double_t* values, Double_t* errors);
}; // ErrorAnalysis

#endif
