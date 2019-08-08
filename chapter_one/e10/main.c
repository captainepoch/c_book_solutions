#include <stdio.h>

int main()
{
	int c;
	int changed = 0;
	while((c = getchar()) != EOF) {
		if(c == '\b') {
			putchar('\\');
			putchar('b');
			changed = 1;
		} else if(c == '\t') {
			putchar('\\');
			putchar('t');
			changed = 1;
		} else if(c == '\\') {
			putchar('\\');
			putchar('\\');
			changed = 1;
		}
		if(!changed) {
			putchar(c);
		}
		changed = 0;
	}
	return 0;
}
