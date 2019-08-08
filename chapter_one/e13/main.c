#include <stdio.h>

#define MAX_LENGTH 10

int main()
{
	int lengths[MAX_LENGTH + 1];

	int c = 0;
	for(c = 0; c < (MAX_LENGTH + 1); ++c) {
		lengths[c] = 0;
	}

	int count = 0;
	// 0 - Out of a word
	// 1 - Into a word
	int state = 1;
	while((c = getchar()) != EOF) {
		++count;
		if(c == ' ' || c == '\n' || c == '\t') {
			// Pos. 0 means length 1
			++lengths[0];
			state = 0;
			--count;
		}
		if(state == 0) {
			if(count != 0 && count <= MAX_LENGTH) {
				++lengths[count - 1];
			} else if(count != 0 && count > MAX_LENGTH) {
				++lengths[MAX_LENGTH];
			}
			state = 1;
			count = 0;
		}
	}

	int i;
	for(c = 0; c < MAX_LENGTH; ++c) {
		printf("|%d|\t", (c + 1));
		for(i = 0; i < lengths[c]; ++i) {
			putchar('*');
		}
		putchar('\n');
	}
	// >10
	printf("|\t>10|\t");
	for(c = 0; c < lengths[MAX_LENGTH]; ++c) {
		putchar('*');
	}
	putchar('\n');
	return 0;
}
