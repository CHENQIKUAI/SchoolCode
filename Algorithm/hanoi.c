#include <stdio.h>
void Hanoi(int n, char A, char B, char C) {
	if (n == 1)
		printf("%c-->%c\n", A, C);
	else {
		Hanoi(n - 1, A, C, B);
		printf("%c-->%c\n", A, C);
		Hanoi(n - 1, B, A, C);
	}
}
int main(int argc, char const *argv[])
{
	int a;
	while (scanf("%d", &a)) {
		Hanoi(a, 'A', 'B', 'C');
	}
	return 0;
}