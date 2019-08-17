#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("Numeric value of char: %d\n", CHAR_BIT);
	printf("Signed max. numeric value of char: %d\n", SCHAR_MAX);
	printf("Signed min. numeric value of char: %d\n", SCHAR_MIN);
	printf("Max. numeric value of char: %d\n", CHAR_MAX);
	printf("Unsigned max. numeric value of char: %u\n", UCHAR_MAX);
	printf("---\n");
	printf("Max. numeric value of int: %d\n", INT_MAX);
	printf("Min. numeric value of int: %d\n", INT_MIN);
	printf("Unsigned max. numeric value of int: %u\n", UINT_MAX);
	printf("---\n");
	printf("Max. numeric value of long: %ld\n", LONG_MAX);
	printf("Min. numeric value of long: %ld\n", LONG_MIN);
	printf("Unsigned max. numeric value of long: %lu\n", ULONG_MAX);
	printf("---\n");
	printf("Max. numeric value of short: %d\n", SHRT_MAX);
	printf("Min. numeric value of short: %d\n", SHRT_MIN);
	printf("Unsigned max. numeric value of short: %u\n", USHRT_MAX);
	printf("---\n");
	printf("Max. numeric value of float: %f\n", FLT_MAX);
    printf("Min. numeric value of float: %.130f\n",  FLT_MIN);
    printf("Max. numeric value of float exponent: %d\n", FLT_MAX_EXP);
    printf("Min. numeric value of float exponent: %d\n", FLT_MIN_EXP);
    printf("Mantissa digit exponent value for float: %d\n", FLT_MANT_DIG);
    printf("Numeric value for float epsilon: %.23f\n", FLT_EPSILON);
	printf("---\n");
    printf("Max. numeric value of double: %g\n", DBL_MAX);
    printf("Min. numeric value of double: %g\n", DBL_MIN);
    printf("Max. numeric value of double exponent: %d\n", DBL_MAX_EXP);
    printf("Min. numeric value of double exponent: %d\n", DBL_MIN_EXP);
    printf("Mantissa digit exponent value for double: %d\n", DBL_MANT_DIG);
    printf("Numeric value for double epsilon: %g\n", DBL_EPSILON);
	return 0;
}
