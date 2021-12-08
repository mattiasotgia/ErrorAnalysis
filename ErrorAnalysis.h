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

Double_t get_pValue(fFormula sFormula, Double_t* values, Double_t* errors){
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
    Double_t    evalF_inpoint;
    Double_t    evalF_after, evalF_before;
    Double_t    diff_fAfter, diff_fBefore;
    Double_t    errMax;
    Double_t   *vChanged_i_component_after;
    Double_t   *vChanged_i_component_before;

    Int_t fNdim = tFormula->GetNdim();
    if(fNdim==1) exit(1);

    // tFormula->Eval(0,0,0,0); ** PROBLEMA => come fare per valutare funzioni n-dimensionali?
    // FIXED: found that method TFormula::EvalPar() passes an array `Double_t *x` for values

    for(int i=0; i<fNdim; i++){
        evalF_inpoint = tFormula->EvalPar(values);
        for(int j=0; j<fNdim; j++){
            vChanged_i_component_after[j] = (j!=i)? (values[j]):(values[j] + errors[j]);
            vChanged_i_component_before[j] = (j!=i)? (values[j]):(values[j] - errors[j]);
        }
        evalF_after = tFormula->EvalPar(vChanged_i_component_after);
        diff_fAfter = abs(evalF_inpoint-evalF_after);
        evalF_before = tFormula->EvalPar(vChanged_i_component_before);
        diff_fBefore = abs(evalF_inpoint-evalF_before);
        errMax = (diff_fAfter>diff_fBefore)? diff_fAfter:diff_fBefore;

        eSquareSum+=pow(errMax, 2);
    }

    pError = sqrt(eSquareSum);
    return pError;
}

#endif