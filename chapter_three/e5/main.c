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

void itob(int n, char s[], int b)
{
	int i, sign, rest;
	/* It stored the unsigned number */
	unsigned int number;
	if((sign = n) < 0) {
		number = -n;
	} else {
		number = n;
	}
	i = 0;
	do {
		rest = (number % b);
		s[i++] = ((rest > 9) ? ((rest - 10) + 'A') : (rest + '0'));
	} while(number /= b);
	if(sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s, i);
}

int main()
{
	char s[MAX];
	int i, number;
	/* Min/Max Base: 2/32 */
	number = INT_MAX;
	for (i = 2; i <= 32; i++) {
		itob(number, s, i);
		printf("Decimal: %d\nIn base %d : %s\n", number, i, s);
	}
	return 0;
}
