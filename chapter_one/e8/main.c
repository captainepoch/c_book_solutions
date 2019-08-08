#include <stdio.h>

int main()
{
	int c;
	int blank = 0, tab = 0, new = 0;
	while((c = getchar()) != EOF) {
		if(c == '\n') {
			++new;
		} else if(c == '\t') {
			++tab;
		} else if(c == ' ') {
			++blank;
		}
	}
	printf("\nBlanks: %d\nTabs: %d\nNL: %d\n",
		   blank, tab, new);
	return 0;
}
