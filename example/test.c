#include <stdio.h>
#include "complex.h"

int main(int argc, char const *argv[])
{
	complex_t num1 = {3, 4};
	complex_t num2 = {1, 2};



	printf("ln(%s)=%s\n", ctoa(num2), ctoa(clog(num2)));
	printf("log_10(%s)=%s\n\n", ctoa(num2), ctoa(clog10(num2)));

	printf("%s^%s=%s\n", ctoa(num1), ctoa(num2), ctoa(cpower(num1, num2)));
	printf("sqrt(%s)=%s\n\n", ctoa(num1), ctoa(csqrt(num1)));

	printf("sin(%s)=%s\n", ctoa(num1), ctoa(csin(num1)));
	printf("cos(%s)=%s\n", ctoa(num1), ctoa(ccos(num1)));
	printf("tan(%s)=%s\n", ctoa(num1), ctoa(ctan(num1)));
	printf("sec(%s)=%s\n", ctoa(num1), ctoa(csec(num1)));
	printf("csc(%s)=%s\n", ctoa(num1), ctoa(ccsc(num1)));
	printf("cot(%s)=%s\n\n", ctoa(num1), ctoa(ccot(num1)));

	printf("sinh(%s)=%s\n", ctoa(num1), ctoa(csinh(num1)));
	printf("cosh(%s)=%s\n", ctoa(num1), ctoa(ccosh(num1)));
	printf("tanh(%s)=%s\n", ctoa(num1), ctoa(ctanh(num1)));
	printf("sech(%s)=%s\n", ctoa(num1), ctoa(csech(num1)));
	printf("csch(%s)=%s\n", ctoa(num1), ctoa(ccsch(num1)));
	printf("coth(%s)=%s\n\n", ctoa(num1), ctoa(ccoth(num1)));
	

	return 0;
}