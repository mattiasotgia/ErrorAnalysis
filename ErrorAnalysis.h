/*
    ErrorAnalysis - error propagation toolset - C++
    Author: Mattia Sotgia
    Version: 0.0 alpha
*/

/*
    Requirement: 
    ** ROOT include-flags -> `root-config --glibs --cflags`
    ** If used in ROOT macro, use gSystem->Load()
*/

#ifndef LABTOOLS_ErrorPropagation
#define LABTOOLS_ErrorPropagation

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include<TFormula.h>
#include<TMath.h>

typedef std::string fFormula;

Double_t get_pValue(fFormula sFormula, Double_t* values){
    TFormula* tFormula = new TFormula("", sFormula.c_str());
    return tFormula->EvalPar(values);
}

/*
    Description:
        get_pError(sFormula, *values, *errors) - c++ function to compute Error Analysis on a `double* values` array
        and relative errors expressed in double* errrors array, return SquareRoot of SqaredSum of errore porpagates
        by changing every parameter in its error range;
    
    Arguments:

*/
Double_t get_pError(fFormula sFormula, Double_t* values, Double_t* errors){
    double pError;

    TFormula* tFormula = new TFormula("", sFormula.c_str());
    
    Double_t    eSquareSum = 0; //> Initialized squared-summation to zero
    Double_t    evalF_inpoint; //> Evaluate f at point
    Double_t    evalF_before, evalF_after; //> Evaluate f before/after 
    Double_t    diffF_before, diffF_after; //> Evaluate f diff
    Double_t    errMax;

    Int_t fNdim = tFormula->GetNdim();
    if(fNdim==1) exit(1);

    Double_t    vChanged_i_component_before[fNdim];
    Double_t    vChanged_i_component_after[fNdim];

    // tFormula->Eval(0,0,0,0); ** PROBLEMA => come fare per valutare funzioni n-dimensionali?
    // FIXED: found that method TFormula::EvalPar() passes an array `Double_t *x` for values

    for(int i=0; i<fNdim; i++){
        evalF_inpoint = tFormula->EvalPar(values);
        for(int j=0; j<fNdim; j++){
            vChanged_i_component_before[j] = (j!=i)? (values[j]):(values[j] - errors[j]);
            vChanged_i_component_after[j] = (j!=i)? (values[j]):(values[j] + errors[j]);
        }
        evalF_before = tFormula->EvalPar(vChanged_i_component_before);
        evalF_after = tFormula->EvalPar(vChanged_i_component_after);

        diffF_before = abs(evalF_inpoint-evalF_before);
        diffF_after = abs(evalF_inpoint-evalF_after);

        errMax = (diffF_after>diffF_before)? diffF_after:diffF_before;

        eSquareSum+=pow(errMax, 2);
    }

    pError = sqrt(eSquareSum);
    return pError;
}

#endif