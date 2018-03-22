#include <stdio.h>
#include <stdlib.h>
typedef struct position P;
struct position
{
	int x;
	int y;
};
void input_xy(P *p, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		scanf("%d", &p->x);
		scanf("%d", &p->y);
		p++;
	}
}
void output_xy(P *p, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		printf("(%d, ", p->x);
		printf("%d)\n", p->y);
		p++;
	}
}
void putIntoP(P *p, int *count_result, int x, int y) {
	p[*count_result].x = x;
	p[*count_result].y = y;
	(*count_result) ++;
}
int In(P *result, int n, int x, int y) {
	int i;
	for (i = 0; i < n; ++i) {
		if (result[i].x == x && result[i].y == y)
			return 1;
	}
	return 0;
}
P *calculate(P *p, int n, int *count_p) {
	int i, j, k;
	int x1, x2, y1, y2;
	int a, b, c;
	int mark = 0;
	P* result = malloc(sizeof(P) * 3);
	int count_result = 0;
	for (i = 0; i < n - 1; ++i) {
		x1 = p[i].x;
		y1 = p[i].y;
		for (j = i + 1; j < n; ++j) {
			x2 = p[j].x;
			y2 = p[j].y;
			a = y2 - y1;
			b = x1 - x2;
			c = x1 * y2 - y1 * x2;
			k = 0;
			int count = 0;
			while (k < n) {
				int F = (p[k].x) * a + (p[k].y) * b - c;
				if (F > 0) {
					count++;
				}
				k++;
			}
			if (count == n - 2 || count == 0) {
				if (count_result == 0) {//The first time when the answer is correct.
					putIntoP(result, &count_result, x1, y1);
					putIntoP(result, &count_result, x2, y2);
				}
				if (!In(result, count_result, x1, y1)) {
					if (count_result >= 3) {
						result = (P*)realloc(result, sizeof(P) * (count_result + 1));
					}
					putIntoP(result, &count_result, x1, y1);
				}
				if (!In(result, count_result, x2, y2)) {
					if (count_result >= 3) {
						result = (P*)realloc(result, sizeof(P) * (count_result + 1));
					}
					putIntoP(result, &count_result, x2, y2);
				}

			}
		}
	}
	*count_p = count_result;
	printf("count%d\n", count_result);
	return result;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	P *p = malloc(sizeof(struct position) * n);
	int count_p;
	input_xy(p, n);
	P *pp = calculate(p, n, &count_p);
	printf("\n");
	output_xy(pp, count_p);

	free(p);
	return 0;
}