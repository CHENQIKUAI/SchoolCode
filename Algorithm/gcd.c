#include <stdio.h>
#include <stdlib.h>

long gcd(long m, long n) {
	if (m == 0 && n == 0) {
		printf("Input error, you can not input two 0.\n");
		exit(-1);
	}
	long temp;
	while (n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}
	return m;
}
long gcd2(long m, long n) {

	if (m == 0 && n == 0) {
		printf("Input error, you can not input two 0.\n");
		exit(-1);
	}

	long k = m < n ? m : n;
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
long gcd3(long m, long n) {
	long r = 1;
	if (m == 0 && n == 0) {
		printf("Input error, you can not input two 0.\n");
		exit(-1);
	}
	long k = m < n ? m : n;
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
	long a, b;
	printf("Please enter two positive integers!\n");
	// scanf("%ld %ld", &a, &b);
	// printf("The answer is: %ld\n", gcd(a, b));
	int i = 0;
	printf("For test! If there have one 0, then the Algorithm is wrong\n");
	for (i = 0; i < 100; ++i) {
		a = rand() % 100;
		b = rand() % 100;
		printf("%d ", gcd(a, b) == gcd3(a, b));
	}
	return 0;
}
