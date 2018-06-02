#include <stdio.h>
//Problem
//问题：
//求最长公共子序列
#define L1 7
#define L2 7
#define LT 0
#define L -1
#define T  1
char X[L1 + 1] = {' ', 'A', 'B', 'A', 'B', 'D', 'C', 'B'};
char Y[L2 + 1] = {' ', 'D', 'D', 'C', 'B', 'B', 'A', 'C'};
int B[L1 + 1][L2 + 1];
int LCS(char X[], char Y[], int m, int n) {
	int C[m + 1][n + 1];

	for (int i = 0; i <= m; ++i) {
		C[i][0] = 0;
	}
	for (int i = 0; i <= n; ++i) {
		C[0][i] = 0;
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (X[i] == Y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = LT;
			}
			else {
				if (C[i][j - 1] > C[i - 1][j]) {
					C[i][j] = C[i][j - 1];
					B[i][j] = T;
				} else {
					C[i][j] = C[i - 1][j];
					B[i][j] = L;
				}
			}
		}
	}
	return C[m][n];
}
void frontPush(char result[], int n, char ch) {
	for (int i = n - 1; i >= 0; --i) {
		if (result[i] == -10) {
			result[i] = ch;
			break;
		}
	}
}
void Sequence(int i, int j, int n, char result[]) {
	if (i == 0 || j == 0) {
		return;
	}
	if (B[i][j] == LT) {
		// printf("%c ", X[i]);
		frontPush(result, n, X[i]);
		Sequence(i - 1, j - 1, n, result);
	}
	else {
		if (B[i][j] = T) {
			Sequence(i - 1, j, n, result);
		} else {
			Sequence(i, j - 1, n, result);
		}
	}
}

int main(int argc, char const *argv[])
{

	int n = LCS(X, Y, L1, L2);
	char result[n];
	for (int i = 0; i < n; ++i)
		result[i] = -10;

	Sequence(L1, L2, n, result);
	printf("%d\n", n);
	for(int i = 0; i < n; ++i){
		printf("%c ", result[i]);
	}
	return 0;
}