#include <stdio.h>

int main()
{
	printf("Press ENTER...\n");
	printf("Result: %d\n", (getchar() != EOF));
	printf("EOP\n");
	return 0;
}
