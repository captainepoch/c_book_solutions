#include <stdio.h>

#define MAXLINE 1024

int getl(char l[]);

int check_dashes(char l[], int i)
{
	while(l[i] == '-') {
		++i;
	}
	return i;
}

int main()
{
	char line[MAXLINE];
	char result[MAXLINE];
	int len, i, j;
	len = getl(line);
	printf("Len: %d\n", len);
	printf("Petition: %s\n", line);
	i = j = 0;
	/* Check leading - */
	if(line[i] == '-') {
		result[i] = '-';
		++i;
		++j;
	}
	int first, last;
	while(line[i] != '\0') {
		i = check_dashes(line, i);
		first = line[i];
		i = check_dashes(line, (i + 1));
		last = line[i];
		if(first <= last) {
			while(first <= last) {
				result[j] = first;
				++j;
				++first;
			}
		} else {
			while(first >= last) {
				result[j] = first;
				++j;
				--first;
			}
		}
		++i;
	}
	/* Check trailing - */
	if(line[len - 1] == '-') {
		result[j - 1] = '-';
	}
	result[j] = '\0';
	printf("Result: %s\n", result);
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

	l[i] = '\0';
	return i;
}
