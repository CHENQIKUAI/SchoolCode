//Large number multiplication
//by Peter 2018.4.21
#include <stdio.h>
#include <stdlib.h>

void bigmul(int, int, int, int, int*);
int divide(int a, int na, int mark) {
    int t = 1;
    int i;
    for (i = 1; i <= na / 2; ++i) {
        t *= 10;
    }
    if (mark == 1) {
        return a / t;
    } else {
        return a % t;
    }
}
int base(int na) {
    int i;
    int t = 1;
    for (i = 1; i <= na; ++i)
        t *= 10;
    return t;
}
int main(int argc, char const *argv[])
{
    int x[] = {0, 0, 0, 0};
    int a, b;
    int na, nb;
    printf("please input two number of 8 digits\n");
    scanf("%d %d", &a, &b);

    bigmul(a, 8, b, 8, x);

    printf("%d%04d%04d%04d\n", x[0], x[1], x[2], x[3]);
    return 0;
}


//分成两半 计算里面的乘法
void bigmul(int a, int na, int b, int nb, int x[]) {
    int a2 = divide(a, na, 1);
    int a1 = divide(a, na, 2);
    int b2 = divide(b, nb, 1);
    int b1 = divide(b, nb, 2);

    if (na == 2 || nb == 2) {
        int m1 = a1 * b1;
        int m2 = a2 * b1;
        int m3 = a1 * b2;
        int m4 = a2 * b2;

        int r[4];

        r[0] = m4 / 10;
        r[1] = m4 % 10 + (m2 + m3) / 10;
        r[2] = (m2 + m3) % 10 + m1 / 10;
        r[3] = m1 % 10;

        x[3] = r[3];
        x[2] = r[2] % 10;
        x[1] = (r[1] + r[2] / 10) % 10;
        x[0] = (r[0] + r[1] / 10) % 10;

    } else {
        int n = na / 2;

        bigmul(a1, na / 2, b1, nb / 2, x);
        int m1 = x[0] * base(n + n / 2) + x[1] * base(n) + x[2] * base(n / 2) + x[3];
        bigmul(a2, na / 2, b1, nb / 2, x);
        int m2 = x[0] * base(n + n / 2) + x[1] * base(n) + x[2] * base(n / 2) + x[3];
        bigmul(a1, na / 2, b2, nb / 2, x);
        int m3 = x[0] * base(n + n / 2) + x[1] * base(n) + x[2] * base(n / 2) + x[3];
        bigmul(a2, na / 2, b2, nb / 2, x);
        int m4 = x[0] * base(n + n / 2) + x[1] * base(n) + x[2] * base(n / 2) + x[3];

        int r[4];

        r[0] = m4 / base(na / 2);
        r[1] = m4 % base(na / 2) + (m2 + m3) / base(na / 2);
        r[2] = (m2 + m3) % base(na / 2) + m1 / base(na / 2);
        r[3] = m1 % base(na / 2);

        x[3] = r[3];
        x[2] = r[2] % base(na / 2);
        x[1] = (r[1] + r[2] / base(na / 2)) % base(na / 2);
        x[0] = (r[0] + r[1] / base(na / 2)) % base(na / 2);
    }
}