#include <stdio.h>

int any(char s1[], char s2[]) {
    int i, k;
    for (k = 0; s2[k] != '\0'; ++k) {
        for (i  = 0; s1[i] != '\0'; ++i) {
            if (s1[i] == s2[k]) {
                return i;
			}
		}
    }
	return -1;
}

int main(void)
{
	char s1[] = "aJKuaaPP";
	char s2[] = "aAeEiIoOuU";
	/* char s2[] = "jJkKpP"; */
	/* char s2[] = "zZ"; */

	int index;
	index = any(s1, s2);
	if(index < 0) {
		printf("There is not any char in s1 from s2\n");
	} else {
		printf("Index of the char %c in s1: %d\n", s1[index], index);
	}

	return 0;
}
