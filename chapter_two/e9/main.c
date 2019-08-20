/*
 * If x is an odd number, then the rightmost bit is one, thus x-1 is a even
 * number with the rightmost bit being 0, then (x & (x - 1)) = (x - 1),
 * because the last bit is one in the first, and 0 in the second.
 *
 * The same occurs if x is even and (x - 1) is odd.
 *
 * Applying the AND operator will delete the rightmost bit if one of the
 * numbers is odd and the other is not.
 */

#include <stdio.h>

int bitcount(unsigned x)
{
	int b;
	b = 0;
	while(x != 0) {
		x &= (x - 1);
		++b;
	}
	return b;
}

int main()
{
	printf("%d\n", bitcount(30));
	return 0;
}
