//Matrix-chain multiplication矩阵链相乘
/*问题：设 A1
, A2 , … , An 为矩阵序列，
Ai 为 Pi-1 X Pi 阶矩阵，
i = 1, 2, … , n.
试确定矩阵的乘法顺序，
使得元素相乘的总次数最少. */

//author: Peter
#include <stdio.h>
#include <stdlib.h>
void print_optimal_parens(int **s, int i, int j) {
	if (i == j) {
		printf("A%d", i);
	} else {
		printf("(");
		print_optimal_parens(s, i, s[i][j]);
		print_optimal_parens(s, s[i][j] + 1, j);
		printf(")");
	}
}

int minCalc(int P[], int n) {
	int m[n + 1][n + 1];
	int **s;
	s = (int**)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; ++i) {
		s[i] = (int*)malloc(sizeof(int) * (n + 1));
	}

	for (int i = 1; i <= n; ++i) {
		m[i][i] = 0;
	}
	for (int j = 2; j <= n; ++j) {
		for (int i = j - 1; i >= 1; --i) {

			s[i][j] = i;
			int temp = m[i][i] + m[i + 1][j] + P[i - 1] * P[i] * P[j];

			for (int k = i + 1; k < j; ++k) {

				int now = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
				if (now < temp) {
					temp = now;
					s[i][j] = k;
				}
			}
			m[i][j] = temp;
		}
	}
	print_optimal_parens(s, 1, n);
	for (int i = n; i >= 1; --i) {
		if (s[i] != NULL) {
			free(s[i]);
			s[i] = NULL;
		}
	}
	return m[1][n];
}


int main(int argc, char const *argv[])
{
	int P[6] = {5, 20, 50, 1, 100};
	printf("%d\n", minCalc(P, 4));

	return 0;
}