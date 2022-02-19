#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

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
    char *buf = (char *)malloc(sizeof(char) * (CHAR_BIT * sizeof(long double) + 1));
    char sign = '+';
    if(fabs(num.imag) != num.imag)
    {
        sign = '-';
    } 
    snprintf(buf, sizeof(char) * (CHAR_BIT * sizeof(long double) + 3), "%.8Lg%c%.8Lgi", num.real, sign, fabs(num.imag)); // +3 to account for the ',' and 'i'
    return buf;
}

complex_t cpower(complex_t num, long double power)
{
    complex_t result;
    result.real = pow(num.real, power);
    result.imag = pow(num.imag, power);
    return result;
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

complex_t csqrt(complex_t num) // Calculate sqrt of a complex number, with the real and the imaginary results.
{
    complex_t result;

    long double a = num.real * num.real;
    long double b = num.imag * num.imag;

    long double rep = cos(0.5 * atan2(num.imag, num.real));
    long double imp = sin(0.5 * atan2(num.imag, num.real));

    result.real = pow(a + b, 0.25) * rep;
    result.imag = pow(a + b, 0.25) * imp;

    return result;
}

long double radangle(complex_t num)
{

    long double angle = atan2(num.imag, num.real);
    return angle;
}

long double degangle(complex_t num)
{
    long double angle = radangle(num) * 180 / M_PI;
    return angle;
}

complex_t conj(complex_t num)
{
    complex_t result;
    result.real = num.real;
    result.imag = -num.imag;
    return result;
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
    return cadd(num1, conj(num2)); // num1 - num2
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

/* int main()
{
    complex_t my_complex = {4.0, 3.0};
    printf("%s\n", ctoa(my_complex));
    printf("Sqrt of %s is %s\n", ctoa(my_complex), ctoa(csqrt(my_complex)));
    printf("(2+3i)^2 = %s\n", ctoa(cpower(my_complex, 2)));
    printf("Angle: %llf\n\n", degangle(my_complex));
    complex_t a = {7.0, -3.0}, b = {0.0, -5.01};
    printf("Sum: %s\nDiff: %s\n", ctoa(cadd(a, b)), ctoa(cdiff(a, b)));
    printf("Multiply: %s\nDivision: %s", ctoa(cmultiply(a, b)), ctoa(cdivide(a, b)));
    
    return 0;
} */