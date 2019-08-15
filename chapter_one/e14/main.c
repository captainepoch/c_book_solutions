#include <stdio.h>

// Dif is also the min (char 32 = Space)
#define DIF 32
#define MAX 126

int main()
{
	int freq[MAX - DIF];
	int c;
	for(c = 0; c < (MAX - DIF); ++c) {
		freq[c] = 0;
	}
	while((c = getchar()) != EOF) {
		if(c >= DIF && c <= MAX) {
			++freq[c - DIF];
		}
	}
	int i;
	for(c = DIF; c <= MAX; ++c) {
		printf("|%c| ", c);
		for(i = 0; i < freq[c - DIF]; ++i) {
			putchar('+');
		}
		putchar('\n');
	}
	return 0;
}
