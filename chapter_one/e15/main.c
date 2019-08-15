#include <stdio.h>

float conversion(float fahr)
{
	float celsius;
	celsius = (5.0/9.0) * (fahr - 32.0);
	return celsius;
}

int main()
{
	float fahr, celsius;
	int lower = 0, upper = 300, step = 20;

	fahr = lower;
	printf("Fahr\tCelsius\n");
	while(fahr <= upper) {
		celsius = conversion(fahr);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
