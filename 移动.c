// make 0 at the end of the array, and others forward
// by P
// 2018.1.11
#include <stdio.h>
void sort(int *list, int n) {
	int j = 0;
	int i;
	for (i = 0; i < n; ++i) {
		if (list[i] != 0) {
			list[j++] = list[i];
		}
	}
	for (j; j < n; ++j) {
		list[j] = 0;
	}
}
int main() {
	int list[5] = {0, 1, 0, 3, 12};
	sort(list, 5);
	int i;
	for (i = 0; i < 5; ++i) {
		printf("%d\n", list[i]);
	}
}
