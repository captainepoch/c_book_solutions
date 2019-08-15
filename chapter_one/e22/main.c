#include <stdio.h>

#define MAXLINE 1000
#define FOLDING 72

char line[MAXLINE];

int getl(void);

int main()
{
	int len;
	extern char line[];

	int location, breakline, count;
	while((len = getl()) > 0) {
		location = breakline = count = 0;
		while(count < len) {
			if(line[count] == ' ') {
				breakline = count;
			}
			if(location == FOLDING) {
				line[breakline] = '\n';
				location = 0;
			}
			++count;
			++location;
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
