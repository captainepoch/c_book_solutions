#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    for (k = 0; s2[k] != '\0'; ++k) {
        for (i = j = 0; s1[i] != '\0'; ++i) {
            if (s1[i] != s2[k]) {
                s1[j++] = s1[i];
			}
		}
		s1[j] = '\0';
    }
}

int main(void)
{
	char s1[] = "aJKuaaPP";
	char s2[] = "aAeEiIoOuU";
	/* char s2[] = "jJkKpP"; */

	printf("String before: %s\n", s1);
	squeeze(s1, s2);
	printf("String after: %s\n", s1);

	return 0;
}
