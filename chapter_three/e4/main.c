/*
 * Due to the range of the two-complement representation, which is
 * [(-2^n), (2^n) - 1], the max. value of an integer cannot be
 * represented.
 *
 * If, at line 36, the number were kept in a signed integer, for example
 * -(INT_MIN) would cause a overflow, so it cannot be represented.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 1000

void reverse(char string[], int len)
{
	char c;
	int i, j;
	j = len - 1;
	/* Remove the \n */
	for(i = 0; i < j; ++i) {
		c = string[i];
		string[i] = string[j];
		string[j] = c;
		--j;
	}
	string[len] = '\0';
}

void itoa(int n, char s[])
{
	int i, sign;
	/* It stored the unsigned number */
	unsigned int number;
	if((sign = n) < 0) {
		number = -n;
	} else {
		number = n;
	}
	i = 0;
	do {
		s[i++] = (number % 10) + '0';
	} while(number /= 10);
	if(sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s, i);
}

int main()
{
	char s[MAX];
	itoa(INT_MIN, s);
	printf("Number: %s\n", s);
	itoa(INT_MAX, s);
	printf("Number: %s\n", s);
	return 0;
}
