#include <stdio.h>
int min(int a, int b) {
    return a < b ? a : b;
}
int changeMaking(int m, int D[], int n) {
    int F[n];
    F[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int temp = 100000;
        int j = 1;
        while (j <= m && i >= D[j - 1]) {
            temp = min(F[i - D[j - 1]], temp);
            ++j;
        }
        F[i] = temp + 1;
    }
    return F[n];
}
int main(int argc, char const *argv[])
{
    int D[3] = {1, 3, 4};
    int m = 3;
    int n;
    scanf("%d", &n);
    printf("%d \n", changeMaking(m, D, n));
    return 0;
}