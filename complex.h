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


/* Various library functions */
long double real(complex_t num);
long double imag(complex_t num);
complex_t cvalue(long double real, long double imag);
char *ctoa(complex_t num);

/* Angle conversion functions */
long double degtorad(long double deg);
long double radtodeg(long double rad);

/* Basic complex number functions */
long double cabs(complex_t num);
long double carg(complex_t num);
complex_t conj(complex_t num);

/* Elementary operations */
complex_t cadd(complex_t num1, complex_t num2);
complex_t cdiff(complex_t num1, complex_t num2);
complex_t cmultiply(complex_t num1, complex_t num2);
complex_t cdivide(complex_t num1, complex_t num2);

/* Trigonometry */
complex_t csin(complex_t num);
complex_t ccos(complex_t num);
complex_t ctan(complex_t num);
complex_t ccsc(complex_t num);
complex_t csec(complex_t num);
complex_t ccot(complex_t num);

/* Hyperbolic trigonometry */
complex_t csinh(complex_t num);
complex_t ccosh(complex_t num);
complex_t ctanh(complex_t num);
complex_t ccsch(complex_t num);
complex_t csech(complex_t num);
complex_t ccoth(complex_t num);

/* Powers */
complex_t cexp(complex_t num);
complex_t cpower(complex_t num, complex_t power);
complex_t csqrt(complex_t num);

/* Logarithms */
complex_t clog(complex_t num);
complex_t clogbase(complex_t base, complex_t num);
complex_t clog10(complex_t num);

#include "complex.c"
