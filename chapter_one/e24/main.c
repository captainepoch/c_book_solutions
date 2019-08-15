#include <stdio.h>

#define MAXLINE 1000
#define FALSE 0
#define TRUE 1

int getl(void);

char line[MAXLINE];

int main()
{
	extern char line[];
	int len, par, bra, brac, quote, d_quote, t, normal_comment,
		block_comment, escape_quote, escape_d_quote;
	while((len = getl()) > 0) {
		t  = par = bra = brac = quote = d_quote =
			normal_comment = block_comment = escape_quote =
			escape_d_quote = FALSE;
		while(t < len) {
			if(line[t] == '/' && !quote && !d_quote
			   && !normal_comment && !block_comment) {
				if(line[t + 1] == '/') {
					normal_comment = TRUE;
				} else if(line[t + 1] == '*') {
					block_comment = TRUE;
				} else if(line[t + 1] == '\n') {
					normal_comment = block_comment = TRUE;
				}
			} else if(line[t] == '\n' && normal_comment && !block_comment) {
				normal_comment = FALSE;
				++t;
			} else if(line[t] == '*' && line[t + 1] == '/' &&
					  block_comment && !normal_comment) {
				block_comment = FALSE;
				++t;
			}
			if(!normal_comment && !block_comment) {
				if(line[t] == '[') {
					++bra;
				} else if(line[t] == ']') {
					--bra;
				} else if(line[t] == '(') {
					++par;
				} else if(line[t] == ')') {
					--par;
				} else if(line[t] == '{') {
					++brac;
				} else if(line[t] == '}') {
					--brac;
				} else if(line[t] == '\'' || escape_quote) {
					if((line[t + 1] == '\\' && line[t + 2] == '\'')
					   || (line[t + 1] == '\'')) {
						escape_quote = TRUE;
					} else {
						escape_quote = FALSE;
					}
					quote = !quote;
				} else if(line[t] == '"') {
					if(line[t - 1] == '\'' && line[t + 1] == '\'') {
						escape_d_quote = TRUE;
					} else {
						escape_d_quote = FALSE;
					}
					if(!escape_d_quote) {
						d_quote = !d_quote;
					}
				}
			}
			++t;
		}
		if(!par && !bra && !brac && !quote && !d_quote &&
		   !normal_comment && !block_comment) {
			printf("All seems to be balanced!\n");
		} else if(par > 0) {
			printf("Parenthesis are unbalanced\n");
		} else if(bra > 0) {
			printf("Brackets are unbalanced\n");
		} else if(brac > 0) {
			printf("Braces are unbalanced\n");
		} else if(quote > 0) {
			printf("Single quotes are unbalanced\n");
		} else if(d_quote > 0) {
			printf("Double quotes are unbalanced\n");
		} else if(normal_comment && block_comment) {
			printf("Comments sections are started but not finished\n");
		}else if(normal_comment) {
			printf("Comments are unbalanced\n");
		} else if(block_comment) {
			printf("Block comments are unfinished\n");
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
