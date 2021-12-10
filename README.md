# ErrorAnalysis: `get_pValue` and `get_pError`
C++ functions used to perform automatic error propagation using function evaluation in point .

## Requirements
This library is based upon [ROOT](https://root.cern/) public framework, mainly `TFormula` class.

## Usage
Two main functions:
- `Double_t get_pValue(fFormula sFormula, Double_t* values)`
- `Double_t get_pError(fFormula sFormula, Double_t* values, Double_t* errors)`
### Arguments
- `fFormula sFormula`: (`typedef std::string fFormula` passed) is the formula used to compute error.\
Its implementation is the same as in the TFormula ROOT class. It recognise standard c++ math operators as sqrt(), pow(), etc...\

The class `TFormula` supports unlimited number of variables and parameters. By default the names which can be used for the variables are x,y,z,t or x[0],x[1],x[2],x[3],....x[N] for N-dimensional formulas.
Formulas may also contain other user-defined ROOT functions defined with a TFormula, eg, where f1 is defined on one x-dimension and 2 parameters:
```
f1(x, [omega], [phi])
f1([0..1])
f1([1], [0])
f1(y)
```

- `Double_t* values`:  Array of variables (its dimension need to be exactly the same as the function dimension)
- `Double_t* errors`:  Array of variable's errors (its dimension need to be exactly the same as the function dimension)


## Future implementations
- It does work if only variables are passed as arguments to function, maybe add a version where the function takes `Double_t* params` as argument.
- Add implementation for COV matrix for when it's needed.
