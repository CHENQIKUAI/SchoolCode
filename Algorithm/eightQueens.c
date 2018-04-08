#include <stdio.h>
#define MAX 8
int count = 0;
int queens[MAX];
void print(int max) {
	int i;
	for (i = 0; i < max; ++i) {
		printf("%d ", queens[i]);
	}
	printf("\n");
	count++;
}
int check(int n) {
	int i;
	if (n == 0)
		return 1;
	for (i = 0; i < n; ++i) {
		if (queens[i] == queens[n] || queens[i] == queens[n] + n - i || queens[i] == queens[n] + i - n)
			return 0;
	}
	return 1;
}
int fn(int n) {//n means n row;
	int i;
	for (i = 0; i < MAX; ++i) {//mean the queens[i] have queen;
		queens[n] = i;
		if (check(n)) {
			if (n == MAX - 1) {
				print(MAX);
			} else {
				fn(n + 1);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	fn(0);
	printf("%d\n", count);

	return 0;
}