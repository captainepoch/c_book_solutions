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

unsigned int rightrot(unsigned int x, unsigned int n)
{
	while(n > 0) {
		x = (x >> 1) | (~(~0U >> (x & 1)));
		--n;
	}
	return x;
}

int main()
{
	unsigned int x = 8234;
	printf("x:\t%x\t%d\n", x, x);
	printf("Bits of x: ");
	showbits(x);

	unsigned int r = rightrot(x, 2);
	printf("Result:\t%x\t%d\n", r, r);
	printf("Bits of r: ");
	showbits(r);

	return 0;
}
