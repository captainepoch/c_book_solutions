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

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	int mask = ~(~0 << n);
	int x_disp = x & ~(mask << (p - n +1));
	int y_disp = (y & mask) << (p - n + 1);
	return x_disp | y_disp;
}

int main()
{
	unsigned int x = 8234;
	printf("x:\t%x\t%d\n", x, x);
	printf("Bits of x: ");
	showbits(x);

	unsigned int y = 2426;
	printf("y:\t%x\t%d\n", y, y);
	printf("Bits of y: ");
	showbits(y);

	unsigned int result = setbits(x, 15, 7, y);
	printf("Result:\t%x\t%d\n", result, result);
	printf("Bits: ");
	showbits(result);

	return 0;
}
