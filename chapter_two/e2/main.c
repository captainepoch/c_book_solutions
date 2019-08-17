#include <stdio.h>

#define MAXLINE 1024

int getl(char l[]);

int main()
{
	int len;
	char line[MAXLINE];

	while((len = getl(line)) > 0) {
		printf("Line (len: %d):\n%s", len, line);
	}
	return 0;
}

int getl(char l[])
{
	int c, i;
	i = 0;
	while((c = getchar()) != '\n') {
		if(c == EOF) {
			break;
		} else if(i > MAXLINE) {
			break;
		} else {
			l[i] = c;
			++i;
		}
	}
	if(c == '\n') {
		l[i] = c;
		++i;
	}
	l[i] = '\0';
	return i;
}
