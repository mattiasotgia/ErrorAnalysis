# ErrorAnalysis: `get_pValue` and `get_pError`
C++ functions used to perform automatic error propagation using function evaluation in point .

## Requirements
This library is based upon [ROOT](https://root.cern/) public framework, mainly `TFormula` class.

## Usage

### Arguments

- `fFormula sFormula`: (`typedef std::string fFormula` passed) is the formula used to compute error.\
Its implementation is the same as in the TFormula ROOT class. It recognise standard c++ math operators as sqrt(), pow(), etc...\
If only 4 variables are used (x, y, z, t) the function might be written as f(x, y, z, t).\
If more are used the function need to be wirtten as f(x[1], x[2], ..., x[N]).

- `Double_t* values`:  Array of variables (its dimension need to be exactly the same as the function dimension)
- `Double_t* errors`:  Array of variable's errors (its dimension need to be exactly the same as the function dimension)


## Future implementations
- It does work if only variables are passed as arguments to function, maybe add a version where the function takes `Double_t* params` as argument.
- Add implementation for COV matrix for when it's needed.
