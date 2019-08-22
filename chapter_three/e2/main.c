#include <stdio.h>

#define MAX 1000

void escape(char s[], char t[])
{
	int i, j;
	i = j = 0;

	while (t[i] != '\0') {
		switch(t[i]) {
		case '\a':
			s[j++] = '\\';
			s[j] = 'a';
			break;
		case '\b':
			s[j++] = '\\';
			s[j] = 'b';
			break;
		case '\f':
			s[j++] = '\\';
			s[j] = 'f';
			break;
		case '\n':
			s[j++] = '\\';
			s[j] = 'n';
			break;
		case '\r':
			s[j++] = '\\';
			s[j] = 'r';
			break;
		case '\t':
			s[j++] = '\\';
			s[j] = 't';
			break;
		case '\v':
			s[j++] = '\\';
			s[j] = 'v';
			break;
		case '\\':
			s[j++] = '\\';
			s[j] = '\\';
			break;
		case '\"':
			s[j++] = '\\';
			s[j] = '\"';
			break;
		default:
			s[j] = t[i];
			break;
		}
		++i;
		++j;
	}
	/* Null character */
	s[j] = t[i];
}

int main()
{
	char t[MAX] = "\aOriginal text,\n\twith a lot of new\b characters was \"Extra\" 'e'!\n";
	char s[MAX];
	escape(s, t);
	printf("T:\n%s\nS:\n%s", t, s);

	return 0;
}
