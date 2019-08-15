#include <stdio.h>

#define MAXLINE 1000
#define MAXLENGTH 81

int getl(char l[], int lim);
void copy_array(char to[], char from[]);

int main()
{
	int len, max;
	char line[MAXLINE], longest[MAXLINE];

	max = 0;
	while((len = getl(line, MAXLINE)) > 0) {
		if(len > max) {
			max = len;
			copy_array(longest, line);
		}
		if(len > MAXLINE) {
			printf("Storage limit exceded: %d (max. %d)\n", len, MAXLINE);
		}
		if(len >= MAXLENGTH) {
			printf("Line (>=80):\n%s", longest);
		}
		printf("Length of the line: %d\n", len);
	}
	return 0;
}

int getl(char l[], int lim)
{
	int c, i;
	for(i = 0; i < (lim - 1) && ((c = getchar()) != EOF)
			&& c != '\n'; ++i) {
		l[i] = c;
	}
	if(c == '\n') {
		l[i] = c;
		++i;
	}
	l[i] = '\0';
	return i;
}

void copy_array(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0') {
		++i;
	}
}
