#include <stdio.h>
#include "stdlib.h"
#include "string.h"
void permutate(int);
int isUp(int *, int);
int find1(int *arr, int n);
int find2(int *arr, int n, int index_i);
void swap(int *a, int *b);
void reverse(int *arr, int a, int z);
void print(int *arr, int n);
int main() {
	permutate(4);
	return 0;
}
void permutate(int n) {
	int *arr = (int *)malloc(sizeof(int) * n);
	int i;
	for (i = 0; i < n; ++i) {
		printf("%d ", i + 1);
		arr[i] = i + 1;
	}
	printf("\n");
	while (isUp(arr, n)) {
		int index_i = find1(arr, n);
		int index_j = find2(arr, n, index_i);
		swap(&arr[index_i], &arr[index_j]);
		reverse(arr, index_i + 1 , n - 1);
		print(arr, n);
	}
	free(arr);
}
int isUp(int *arr, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		if (arr[i] < arr[i + 1]) {
			return 1;
		}
	}
	return 0;
}
int find1(int *arr, int n) {
	int i;
	for (i = n - 2; i >= 0; --i) {
		if (arr[i] < arr[i + 1])
			return i;
	}
}
int find2(int *arr, int n, int index_i) {
	int j;
	for (j = n - 1; j >= index_i + 1; --j) {
		if (arr[index_i] < arr[j]) {
			return j;
		}
	}
}
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void reverse(int *arr, int a, int z) {
	int i;
	for (i = a; i < (a + z) / 2 + 1; ++i) {
		swap(&arr[i], &arr[z + a - i]);
	}
}
void print(int *arr, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}