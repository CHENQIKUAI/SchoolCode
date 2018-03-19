#include <stdio.h>
int gcd(int m, int n) {
	if (n == 0) {
		return m;
	} else {
		return gcd(n, m % n);
	}
}
int prime(int n) {
	int i;
	for (i = 2; i < n; ++i) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int inverseElement(int K) {
	int i;
	for (i = 0; i < 26; ++i) {
		if ((i * 26 + 1) % K == 0) {
			return (i * 26 + 1) / K;
		}
	}
	return -1000;
}
void output() {
	int i;
	for (i = 1; i <= 26; ++i) {
		if (gcd(i, 26) == 1) {
			if (prime(i) == 1) {
				// printf("%d\n", i);
				printf("%d's inverseElement is: %d\n", i, inverseElement(i));
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	// printf("%d\n", inverseElement(3));
	output();
	// printf("%d\n", gcd(2, 3));
	return 0;
}