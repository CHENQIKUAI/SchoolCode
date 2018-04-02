#include <stdio.h>
typedef struct element E;
typedef struct element * pE;
struct element
{
	int value;
	int direction;
};
void permutation(int);
void JT(int);
void initialize(int, pE);
int exist(pE, int);
void swap(pE , int);
void print(pE, int);
void reverse(pE, int, int);

int main(int argc, char const *argv[])
{
	permutation(6);
	return 0;
}
void permutation(int n) {
	int i;
	for (i = 1; i <= n; ++i) {
		printf("%d ", i);
	}
	printf("\n");
	JT(n);
}

void JT(int n) {
	E arr[n];
	initialize(n, arr);
	int count = 1;
	while (exist(arr, n) != -1000) {
		count++;
		int index_k =  exist(arr, n);
		int value_k = arr[index_k].value;
		swap(arr , index_k);
		reverse(arr, n, value_k);
		print(arr, n);
	}
	printf("%d\n", count);
}

void initialize(int n, pE arr) {
	int i;
	for (i = 0; i < n; ++i) {
		arr[i].value = i + 1;
		arr[i].direction = -1;
	}
}
int exist(pE arr, int n) {
	int i;
	int max = -1000;
	int max_value = -1000;
	if (arr[0].direction == 1 && arr[0].value > arr[1].value) {
		max = 0;
		max_value = arr[0].value;
	}

	if (arr[n - 1].direction == -1 && arr[n - 1].value > arr[n - 2].value) {
		max = max_value > arr[n - 1].value ? max : (n - 1);
		max_value = max_value > arr[n - 1].value ? max_value : arr[n - 1].value;
	}

	for (i = 1; i < n - 1; ++i)
		if (arr[i].value > arr[i + arr[i].direction].value) {
			max = max_value > arr[i].value ? max : i;
			max_value = max_value > arr[i].value ? max_value : arr[i].value;
		}

	return max;
}

void swap(pE arr , int index_k) {
	int tempV = arr[index_k].value;
	int tempD = arr[index_k].direction;
	arr[index_k].value = arr[index_k + arr[index_k].direction].value;
	arr[index_k].direction = arr[index_k + arr[index_k].direction].direction;
	arr[index_k + tempD].value = tempV;
	arr[index_k + tempD].direction = tempD;
}
void print(pE arr, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		printf("%d ", arr[i].value);
	}
	printf("\n");
}
void reverse(pE arr, int n, int value_k) {
	int i;
	for (i = 0; i < n; ++i) {
		if (arr[i].value > value_k) {
			arr[i].direction *= -1;
		}
	}
}