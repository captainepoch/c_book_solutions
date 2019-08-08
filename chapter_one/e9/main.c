#include <stdio.h>

int main()
{
	int c;
	int pc = EOF;
	while((c = getchar()) != EOF) {
		if((c == ' ' && pc != ' ') || (c != ' ')) {
			putchar(c);
		}
		pc = c;
	}
	return 0;
}
