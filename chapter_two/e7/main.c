#include <stdio.h>

/* https://en.wikipedia.org/wiki/Bitwise_operations_in_C#Right_shift_operator_usage */
void showbits(unsigned int x)
{
	int i;
	for (i = (sizeof(int) * 8) - 1; i >= 0; i--) {
		putchar(x & (1u << i) ? '1' : '0');
	}
	printf("\n");
}

unsigned int invert(unsigned int x, int p, int n)
{
	int mask = (~(~0 << n)) << (p - n + 1);
	return (x ^ mask);
}

int main()
{
	unsigned int x = 8234;
	printf("x:\t%x\t%d\n", x, x);
	printf("Bits of x: ");
	showbits(x);

	unsigned int r = invert(x, 15, 7);
	printf("Result:\t%x\t%d\n", r, r);
	printf("Bits of r: ");
	showbits(r);

	return 0;
}
