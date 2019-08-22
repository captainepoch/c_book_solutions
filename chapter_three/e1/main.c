#include <stdio.h>
/* Apendix B, B10 */
#include <time.h>

#define MAX 50

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high) {
		mid = (low + high) / 2;
		if(x < v[mid]) {
			high = mid - 1;
		} else if(x > v[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int binsearchmod(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low < high) {
		mid = (low + high) / 2;
		(x <= v[mid]) ? (high = mid) : (low = (mid + 1));
	}
	return (x == v[low]) ? low : -1;
}

int main()
{
	int v[MAX];
	int i;
	/* Init. the array in order */
	for(i = 0; i < MAX; ++i) {
		v[i] = i;
	}

	time_t start, end;
	for(i = 0, start = clock(); i < MAX + 5; ++i) {
		printf("Found %d at %d\n", i, binsearch(i, v, MAX));
	}
	end = clock();
	printf("Time to finish (OR_BS): %g (%g s.)\n", difftime(end, start),
		   difftime(end, start) / CLOCKS_PER_SEC);

	for(i = 0, start = clock(); i < MAX + 5; ++i) {
		printf("Found %d at %d\n", i, binsearchmod(i, v, MAX));
	}
	end = clock();
	printf("Time to finish (MOD_BS): %g (%g s.)\n", difftime(end, start),
		   difftime(end, start) / CLOCKS_PER_SEC);
	return 0;
}
