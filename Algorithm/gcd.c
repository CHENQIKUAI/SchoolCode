#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n) {
	if (m == 0 && n == 0) {
		fprintf(stderr, "Input error, you can not input two 0.\n");
		exit(-1);
	}
	int temp;
	while (n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}
	return m;
}
int gcd2(int m, int n) {

	if (m == 0 && n == 0) {
		fprintf(stderr,"Input error, you can not input two 0.\n");
		exit(-1);
	}

	int k = m < n ? m : n;
	if (k == 0) {
		return m > n ? m : n;
	}

	int i;
	for (i = k; i >= 1; --i) {
		if (m % i == 0 && n % i == 0) {
			return i;
		}
	}
}
int gcd3(int m, int n) {
	int r = 1;
	if (m == 0 && n == 0) {
		fprintf(stderr,"Input error, you can not input two 0.\n");
		exit(-1);
	}
	int k = m < n ? m : n;
	if (k == 0) {
		return m > n ? m : n;
	}
	int *array = (int*)malloc(sizeof(int) * (k + 1));
	int i;
	for (i = 1; i <= k; ++i) {
		array[i] = 1;
	}
	array[0] = 0;
	array[1] = 0;
	for (i = 2; i <= k; ++i) {
		int j;
		if (array[i] == 1) {
			for (j = i * 2; j <= k; j += i) {
				array[j] = 0;
			}
		}
	}

	for (i = 2; i <= k; ++i) {
		if (array[i] == 1) {
			if (m % i == 0 && n % i == 0) {
				r *= i;
				m /= i;
				n /= i;
				i -= 1;
			}
		}
	}
	free(array);
	return r;
}

int main(int argc, char const *argv[])
{
	int a, b;
	printf("Please enter two positive integers!\n");
	scanf("%d %d", &a, &b);
	printf("The answer is: %d\n", gcd3(a, b));
	return 0;
}
