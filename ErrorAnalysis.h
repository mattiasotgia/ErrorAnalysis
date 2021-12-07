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

/*
    Description
*/
typedef std::string fFormula;
double get_pError(fFormula sFormula, double* values, double* errors){
    double pError;

    TFormula* tFormula = new TFormula("", sFormula.c_str());

    Int_t fNdim = tFormula->GetNdim(); // Voglio lavorare con le dimensioni? 
                                       // magari non preferisco lavorare con i parametri?
    if(fNdim==1) exit(1);
    tFormula->Eval(0,0,0,0); // PROBLEMA => come fare per valutare funzioni n-dimensionali ?


    return pError;
}

#endif