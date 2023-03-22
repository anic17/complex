# C complex library

Powerful C library to easily work with complex numbers, with a variety of complex implementations of some commonly used functions.  
All angles are calculated in radians, however you can still convert the different units with some built-in functions.

## List of all functions

### Angle conversion functions
 - `long double degtorad(long double)`: Convert degrees to radians.  
 - `long double radtodeg(long double)`: Convert radians to degrees.  

### Conversion functions
 - `char* ctoa(complex_t)`: Convert complex expression to string, in format $a+bi$ or $a-bi$

### Basic complex operations

 - `complex_t cadd(complex_t, complex_t)`: Add 2 complex numbers.
 - `complex_t cdiff(complex_t, complex_t)`: Substract 2 complex numbers.
 - `complex_t cmultiply(complex_t, complex_t)`: Multiply 2 complex numbers.
 - `complex_t cdivide(complex_t, complex_t)`: Divide 2 complex numbers.
 - `complex_t conj(complex_t)`: Conjugate of a complex number.
 - `long double carg(complex_t)`: Complex argument.
 - `long double cabs(complex_t)`: Absolute value of a complex number.  
 - `complex_t cvalue(long double, long double)`: Assign new values to a complex number, and return that value.  
 - `long double imag(complex_t)`: Get the imaginary part of a complex number.  
 - `long double real(complex_t)`: Get the real part of a complex number.

### Powers and logarithms

 - `complex_t cexp(complex_t num)`: Exponential function ($e^{x}$).
 - `complex_t cpower(complex_t, complex_t)`: Raise a complex number to a power.
 - `complex_t csqrt(complex_t)`: Square root of a complex number.
 - `complex_t clog(complex_t)`: Natural logarithm (base e).
 - `complex_t clogbase(complex_t, complex_t)` Logarithm with any base.
 - `complex_t clog10(complex_t)`: Common logarithm (base 10).

### Trigonometric functions

 - `complex_t csin(complex_t)`: Sine.  
 - `complex_t ccos(complex_t)`: Cosine.  
 - `complex_t ctan(complex_t)`: Tangent.  
 - `complex_t ccsc(complex_t)`: Cosecant.  
 - `complex_t csec(complex_t)`: Secant.  
 - `complex_t ccot(complex_t)`: Cotangent.  

### Hyperbolic functions

 - `complex_t csinh(complex_t)`: Hyperbolic sine.  
 - `complex_t ccosh(complex_t)`: Hyperbolic cosine.  
 - `complex_t ctanh(complex_t)`: Hyperbolic tangent.  
 - `complex_t ccsch(complex_t)`: Hyperbolic cosecant.  
 - `complex_t csech(complex_t)`: Hyperbolic secant.  
 - `complex_t ccoth(complex_t)`: Hyperbolic cotangent.  

## Example

```c
// Define the 2 complex numbers, 2 + 3i and 3 + 4i respectively
complex_t num1 = {2, 3}, num2 = {3, 4};

// Natural logarithm
printf("ln(%s)=%s\n", ctoa(num1), ctoa(clog(num1))); // Prints 1.2824747+0.98279372i

// Multiplication
printf("(%s)*(%s)=%s", ctoa(num1), ctoa(num2), ctoa(cmultiply(num1, num2))); // Prints -6+17i

// Hyperbolic cosine
printf("cosh(%s)=%s\n", ctoa(num2), ctoa(ccosh(num2))); // Prints -6.580663-7.5815527i
```

## Usage
To use the library, simply include it with the following line:
```c
#include "complex.h"
```

Furthermore, `ctoa()` has 2 different output formats:
 - Long, which shows the full complex number, including zero-valued parts.
 - Short, which trims all the unnecessary data: if a part is zero, it won't be shown.
 
 This behavior can be modified by changing the value of [`SHORT_CTOA`](https://github.com/anic17/complex/blob/main/complex.c#L15) (defined at line 15, [`complex.c`](https://github.com/anic17/complex/blob/main/complex.c#L15) to either 0 (long output) or 1 (short output).
 Example outputs of both with `cpower(cvalue(0, 1), cvalue(0, 1)))` ( $i^{i}$ )
 #### Long:
 `0.20787958+0i`
 
 #### Short:
 `0.20787958`

## Known issues

Due to long double-precision floats limitations, precision loss may happen.

**Copyright &copy; 2023 anic17 Software**
