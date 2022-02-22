#pragma once

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct complex_t
{
    long double real;
    long double imag;
} complex_t;

#if !defined(_COMPLEX_H_) && !defined(complex) && !defined(__cplusplus)
typedef complex_t complex;
#endif

char *ctoa(complex_t num);

complex_t cadd(complex_t num1, complex_t num2);
complex_t cdiff(complex_t num1, complex_t num2);
complex_t cdivide(complex_t num1, complex_t num2);
complex_t cmultiply(complex_t num1, complex_t num2);
complex_t conj(complex_t num);
complex_t cpower(complex_t num, long double power);
complex_t csqrt(complex_t num);
complex_t cvalue(long double real, long double imag);

long double degangle(complex_t num);
long double degtorad(long double deg);
long double radangle(complex_t num);
long double radtodeg(long double rad);

long double cabs(complex_t num);
long double imag(complex_t num);

long double real(complex_t num);

#include "complex.c"
