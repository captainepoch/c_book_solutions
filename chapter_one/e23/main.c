#include <stdio.h>

#define MAXLINE 1000
#define FALSE 0
#define TRUE 1

int getl(void);

char line[MAXLINE];

int main()
{
	extern char line[];
	int len, in_quote, in_comment, t;
	in_quote = in_comment = FALSE;
	while((len = getl()) > 0) {
		t = 0;
		while(t < len) {
			if(line[t] == '\'' || line[t] == '"') {
				if(in_quote) {
					in_quote = FALSE;
					putchar(line[t]);
					++t;
				} else {
					in_quote = TRUE;
				}
			}
			if(in_quote == FALSE) {
				if((line[t] == '/' && line[t + 1] == '/') ||
				   (line[t] == '/' && line[t + 1] == '*') ) {
					in_comment = TRUE;
					t = t + 2;
				}
				if(in_comment && line[t] == '\n') {
					in_comment = FALSE;
				} else if(line[t] == '*' && line[t + 1] == '/') {
					in_comment = FALSE;
					t = t + 2;
				}
			}
			if(in_comment == FALSE) {
				putchar(line[t]);
			}
			++t;
		}
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
