#include <stdio.h>

int main()
{
	printf("Visual alert \a\n");
	printf("Back\bspace\n");
	printf("Form\ffeed\n");
	printf("Carriage\rreturn\n");
	printf("Horizontal\ttab\n");
	printf("Vertical\vtab\n");
	// The compiler gives us a warning
	printf("Test with \\c\cin C\n");
	return 0;
}
