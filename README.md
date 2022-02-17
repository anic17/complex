# C complex library

C library to work with complex numbers. Just wanted to implement my own simple complex number library.

## List of all functions:

### Conversion functions
 - `ctoa`: Convert complex expression to string, in format `a+bi` or `a-bi`
 - `degangle`: Calculate the angle of a complex number, in degrees
 - `degtorad`: Convert degrees to radians
 - `radangle`: Calculate the angle of a complex number, in radians
 - `radtodeg`: Convert radians to degrees

### Complex operations
 - `cabs`: Absolute value of a complex number.
 - `cadd`: Add 2 complex numbers
 - `cdiff`: Substract 2 complex numbers
 - `cdivide`: Divide 2 complex numbers
 - `cmultiply`: Multiply 2 complex numbers
 - `conj`: Conjugate of a number
 - `cpower`: Raise a complex number to a power (power can't be complex)
 - `csqrt`: Square root of a complex number
 - `cvalue`: Assign new values to a complex number, and return that value.

### Other functions
 - `imag`: Get the imaginary part of a complex number, returns 0 if no imaginary part exists.
 - `real`: Get the real part of a complex number, returns 0 if no real part exists.



**Copyright (c) 2022 anic17 Software**
