#include <stdio.h>

void lower(char s[])
{
	int i;
	i = 0;
	while(s[i] != '\0') {
		s[i] = ((s[i] >= 'A' && s[i] <= 'Z' ? (s[i] + 'a' - 'A') : s[i]));
		++i;
	}
}

int main()
{
	char s[] = "helLo WOrLD";
	lower(s);
	printf("%s\n", s);
	return 0;
}
