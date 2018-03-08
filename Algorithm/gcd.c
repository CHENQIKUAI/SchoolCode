#include <stdio.h>
#include <stdlib.h>

long gcd(long m, long n) {
	if(m == 0 && n == 0){
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

int main(int argc, char const *argv[])
{
	long a, b;
	scanf("%ld %ld", &a, &b);
	printf("%ld\n", gcd(a, b));
	return 0;
}
