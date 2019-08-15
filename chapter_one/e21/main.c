#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 4

char line[MAXLINE];

int getl(void);

int main()
{
	int len;
	extern char longest[];

	int spacecount, i, j;
	while((len = getl()) > 0) {
		spacecount = 0;
		for(i = 0; i < len; ++i) {
			if(line[i] == ' ') {
				++spacecount;
			} else {
				spacecount = 0;
			}
			if(spacecount == TABSIZE) {
				// Back 3, because is a tab
				i = i - 3;
				len = len - 3;
				// Put the tab at the first space
				line[i] = '\t';
				// Moving the rest of the chars
				for(j = i + 1; j < len; ++j) {
					line[j] = line[j + 3];
				}
				// Correct char sequence
				line[len] = '\0';
			}
		}
		printf("%s", line);
	}

	return 0;
}

int getl(void)
{
	int c, i;
	extern char line[];

	for(i = 0; i< (MAXLINE - 1)	&& ((c = getchar()) != EOF)
			&& c != '\n'; ++i) {
		line[i] = c;
	}
	if(c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
