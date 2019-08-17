#include <stdio.h>
#include <ctype.h>

long htoi(char l[]);

int main()
{
	printf("%ld\n", htoi("0xAAAA"));
	printf("%ld\n", htoi("0xF832"));
	printf("%ld\n", htoi("0xFFFF"));
	printf("%ld\n", htoi("0x1111"));
	printf("%ld\n", htoi("0X76AD"));
	printf("%ld\n", htoi("0X1234"));

	return 0;
}

long htoi(char l[])
{
	unsigned long number = 0;
	int i, c;
	for(i = 0; l[i] != '\0'; ++i) {
		c = tolower(l[i]);
		if(c == '0' && (tolower(l[i + 1]) == 'x')) {
			++i;
		} else if(isdigit(c)) {
			number = (number * 16) + (c - '0');
		} else if(c >= 'a' && c <= 'f') {
			number = (number * 16) + (c - 'a' + 10);
		}
	}
	return number;
}
