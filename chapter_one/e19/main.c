#include <stdio.h>

#define MAXLINE 1000
#define MAXLENGTH 81

int getl(char l[], int lim);
void reverse(char string[], int len);

int main()
{
	int len;
	char line[MAXLINE];

	while((len = getl(line, MAXLINE)) > 0) {
		if(len > MAXLINE) {
			printf("Storage limit exceded: %d (max. %d)\n", len, MAXLINE);
		}
		printf("Line: %s\n", line);
		reverse(line, len);
		printf("Rev. Line: %s\n", line);
		printf("Length of the line: %d\n", len);
	}
	if(len == -1) {
		printf("All blanks or EOF\n");
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
	int trail_spaces, count;
	count = trail_spaces = 0;
	while(count < i) {
		if(l[count] == ' ') {
			++trail_spaces;
		}
		++count;
	}
	if(trail_spaces == i) {
		return -1;
	}
	// Remove tabs for spaces
	for(count = 0; count < i; ++count) {
		if(l[count] == '\t') {
			l[count] = ' ';
		}
	}
	// Remove trailing spaces
	trail_spaces = 0;
	for(count = i - 1; count > 0; --count) {
		if(l[count] == ' ') {
			++trail_spaces;
		} else {
			count = 0;
		}
	}
	printf("Trail Spaces: %d\n", trail_spaces);
	l[i - trail_spaces] = '\0';
	return i;
}

void reverse(char string[], int len)
{
	char c;
	int i, j;
	j = len - 1;
	// Remove the \n
	for(i = 0; i < j; ++i) {
		c = string[i];
		string[i] = string[j];
		string[j] = c;
		--j;
	}
	string[len] = '\0';
}
