#pragma once

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.141592653589793
#endif
#ifndef M_E
#define M_E 2.718281828459045
#endif

#define SHORT_CTOA 1

long double real(complex_t num)
{
    return num.real;
}

long double imag(complex_t num)
{
    return num.imag;
}

char *ctoa(complex_t num)
{
    /* This function is very badly written. Contributions to improve it are highly appreciated */
    size_t allocsize = sizeof(char) * 2 * (8 * sizeof(long double) + 1);
    size_t len = 0;
    char *buf = calloc(allocsize, 1);
    char sign = '+';
    if (num.imag < 0.0L)
    {
        sign = '-';
    }
    if(fabs(num.real) < 1e-15)
    {
        num.real = 0;
    }
    if(fabs(num.imag) < 1e-15)
    {
        num.imag = 0;
    }
    if (SHORT_CTOA)
    {
        if (num.real != 0)
        {
            snprintf(buf, allocsize, "%.8Lg", num.real);
            len = strlen(buf);
        }
        if (num.imag != 0)
        {
            if (num.real != 0 || sign == '-')
            {
                snprintf(buf + len, allocsize, "%c%.8Lgi", sign, fabs(num.imag));
            }
            else
            {
                snprintf(buf + len, allocsize, "%.8Lgi", num.imag);
            }
            len = strlen(buf);
        }
        if(buf[0] == '\0')
        {
            buf[0] = '0';
        }
    }
    else
    {
        snprintf(buf, allocsize, "%.8Lg%c%.8Lgi", num.real, sign, fabs(num.imag)); // +3 to account for the ',' and 'i'
    }
    return buf;
}

long double cabs(complex_t num)
{
    return sqrt(num.real * num.real + num.imag * num.imag);
}

complex_t cvalue(long double real, long double imag) // Change values of a complex function
{
    complex_t result = {real, imag};
    return result;
}

long double carg(complex_t num)
{
    return atan2(num.imag, num.real); // arg(z) = atan(y/x)
}

complex_t conj(complex_t num)
{
    complex_t result = {num.real, -num.imag};
    return result;
}

complex_t clog(complex_t num)
{
    long double modulus = cabs(num), arg = carg(num);
    complex_t c_log = {log(modulus), arg};
    return c_log;
}

long double degtorad(long double deg)
{
    long double rad = deg * M_PI / 180;
    return rad;
}
long double radtodeg(long double rad)
{
    long double deg = rad * 180 / M_PI;
    return deg;
}

complex_t cadd(complex_t num1, complex_t num2)
{
    complex_t result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

complex_t cdiff(complex_t num1, complex_t num2)
{
    complex_t result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    return result;
}

complex_t cmultiply(complex_t num1, complex_t num2)
{
    complex_t result;
    result.real = num1.real * num2.real - num1.imag * num2.imag;
    result.imag = num1.real * num2.imag + num1.imag * num2.real;
    return result;
}

complex_t cdivide(complex_t num1, complex_t num2)
{
    complex_t result;
    long double denominator = num2.real * num2.real + num2.imag * num2.imag;
    result.real = (num1.real * num2.real + num1.imag * num2.imag) / denominator;
    result.imag = (num1.imag * num2.real - num1.real * num2.imag) / denominator;
    return result;
}

complex_t cexp(complex_t num)
{
    complex_t result;
    complex_t tmp = cvalue(num.real, num.imag);
    result.real = pow(M_E, num.real) * cos(num.imag);
    result.imag = pow(M_E, num.real) * sin(num.imag);
    return result;
}

complex_t ccosh(complex_t num)
{
    complex_t exp1 = cexp(num);
    complex_t exp2 = cexp(cvalue(-num.real, -num.imag));
    complex_t result = cdivide(cadd(exp1, exp2), cvalue(2, 0));
    return result;
}

complex_t csinh(complex_t num)
{
    complex_t exp1 = cexp(num);
    complex_t exp2 = cexp(cvalue(-num.real, -num.imag));
    complex_t result = cdivide(cdiff(exp1, exp2), cvalue(2, 0));
    return result;
}

complex_t ccos(complex_t num)
{
    complex_t result;
    result.real = cos(num.real) * cosh(num.imag);
    result.imag = -sin(num.real) * sinh(num.imag);
    return result;
}

complex_t csin(complex_t num)
{
    complex_t result;
    result.real = sin(num.real) * cosh(num.imag);
    result.imag = cos(num.real) * sinh(num.imag);

    return result;
}

complex_t ctan(complex_t num)
{
    complex_t result = cdivide(csin(num), ccos(num));
    return result;
}

complex_t ctanh(complex_t num)
{
    complex_t result = cdivide(csinh(num), ccosh(num));
    return result;
}

complex_t csec(complex_t num) // Inverse of cosine
{
    complex_t result = cdivide(cvalue(1, 0), ccos(num));
    return result;
}

complex_t ccsc(complex_t num) // Inverse of sine
{
    complex_t result = cdivide(cvalue(1, 0), csin(num));
    return result;
}

complex_t ccot(complex_t num)
{
    complex_t result = cdivide(cvalue(1, 0), ctan(num));
    return result;
}

complex_t csech(complex_t num)
{
    complex_t result = cdivide(cvalue(1, 0), ccosh(num));
    return result;
}

complex_t ccsch(complex_t num)
{
    complex_t result = cdivide(cvalue(1, 0), csinh(num));
    return result;
}

complex_t ccoth(complex_t num)
{
    complex_t result = cdivide(cvalue(1, 0), ctanh(num));
    return result;
}

complex_t cpower(complex_t num, complex_t power)
{
    complex_t result;
    complex_t exponent = cmultiply(power, clog(num));
    result = cexp(exponent);

    return result;
}

complex_t clogbase(complex_t base, complex_t num)
{
    complex_t result = cdivide(clog(num), clog(base));
    return result;
}

complex_t clog10(complex_t num)
{
    return clogbase(cvalue(10, 0), num);
}

complex_t csqrt(complex_t num)
{
    return cpower(num, cvalue(0.5, 0)); // Convert square root to fraction exponent (1/2)
}

#ifndef j
#define j cvalue
#endif