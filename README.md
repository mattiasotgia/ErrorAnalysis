# ErrorAnalysis: `get_pValue` and `get_pError`
C++ functions used to perform automatic error propagation using function evaluation in point .

## Requirements
This library is based upon [ROOT](https://root.cern/) public framework, mainly `TFormula` class.

## Installation

In your ($INSTALL_PATH) directory clone this repository using 
```bash
$ git clone https://github.com/mattiasotgia/ErrorAnalysis.git
```
and compile the shared library using
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ sudo make install
```
Then go to $HOME and create (if non existing!) the `.rootrc` file by doing
```bash
$ touch .rootrc
```
and add the following line:
```
Rint.Logon: ~/rootlogon.C
```

Finally, in your $HOME directory create a file named `rootlogon.C` by doing
```bash
$ touch .rootlogon.C
```
and modify this file adding the following lines
```cpp
{
    gInterpreter->AddIncludePath("/usr/local/include");
    gSystem->Load("/usr/local/lib/libErrorAnalysis");
}
```

Now to load the Library in any program you'll need to
```cpp
#include<ErrorAnalysis.h>
```
### Compiling
If using ROOT macros, no other compiler instruction is needed.
To use this library in compiled c/c++ programs you'll need to do the following: 
```bash
$ g++ file_name.cpp -o exe_name -I/usr/local/include -L/usr/local/lib/ -lErrorAnalysis `root-config --glibs --cflags`
```
where `` `root-config --glibs --cflags` `` is only needed if the code calls for other ROOT specific functions.
### Test example
the `test.cpp` file give an example of this library usage, and can be compiled using:
```bash
$ g++ test.cpp -o test -I/usr/local/include -L/usr/local/lib/ -lErrorAnalysis `root-config --glibs --cflags`
```
and executed via 
```bash
$ ./test
```
## Usage
Two main functions:
- `Double_t get_pValue(fFormula sFormula, Double_t* values)` will evaluate the formula for x, y, z, t (or x[0],..., x[N]) variables, returning a Double_t value.
- `Double_t get_pError(fFormula sFormula, Double_t* values, Double_t* errors)` will evaluate error for (x +/- ex), (y +/- ey), (z +/- ez), (t +/- et) (or (x[0] +/- ex[0]),..., (x[N] +/- ex[N])). See Arguments for further details.
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
