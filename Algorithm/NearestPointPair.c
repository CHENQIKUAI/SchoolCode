//Nearest point pair
//by Peter 2018.4.27


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct pair POINT;
struct pair
{
    int x;
    int y;
};
POINT *copy(POINT * P, int n, int mark) {
    if (mark == 1) {
        POINT* P1 = malloc(sizeof(POINT) * n / 2);
        int i;
        for (i = 0; i < n / 2; ++i) {
            P1[i].x = P[i].x;
            P1[i].y = P[i].y;
        }
        return P1;
    }
    else if (mark == 2) {
        POINT*P2 =  malloc(sizeof(POINT) * (n - n / 2));
        int i;
        for (i = 0; i < n - n / 2; ++i) {
            P2[i].x = P[n / 2 + i].x;
            P2[i].y = P[n / 2 + i].y;
        }
        return P2;
    } else if (mark == 3) {
        POINT *new = malloc(sizeof(POINT) * n);
        int i;
        for (i = 0; i < n; ++i) {
            new[i].x = P[i].x;
            new[i].y = P[i].y;
        }
        return new;
    }
}

float min(float a, float b) {
    return a < b ? a : b;
}

POINT *searchPoint(POINT * Q, int n, int m, int d, int *num) {
    //It can be more fast;

    int i;
    POINT * S = (POINT*)malloc(sizeof(POINT));

    for (i = 0; i < n; ++i) {
        if (fabs(Q[i].x - m) < d) {
            S[*num].x = Q[i].x;
            S[*num].y = Q[i].y;
            *num += 1;
            POINT *t = realloc(S, sizeof(POINT) * (*num + 2));
            if (t == NULL) {
                printf("ERROR\n");
                return NULL;
            }
        }
    }
    return S;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

POINT *sort(POINT *P, int n) {
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (P[i].y > P[j].y) {
                swap(&P[i].y, &P[j].y);
                swap(&P[i].x, &P[j].x);
            }
        }
    }

}
float EfficientClosesPair(POINT * P, POINT * Q, int n) {

    if (n <= 3) {
        int d = 100000;
        int i, j;
        for (i = 0 ; i < n - 1; ++i) {
            for (j = i + 1; j < n; ++j) {
                int dd = (P[i].x - P[j].x) * (P[i].x - P[j].x) + (P[i].y - P[j].y) * (P[i].y - P[j].y);
                d = min(dd, d);
            }
        }
        return sqrt(d);
    }
    else {

        POINT *P1 = copy(P, n, 1);
        POINT *Q1 = copy(P1, n, 3);
        sort(Q1, n / 2);

        POINT *P2 = copy(P, n, 2);
        POINT *Q2 = copy(P2, n, 3);
        sort(Q2, n - n / 2);

        float d1 = EfficientClosesPair(P1, Q1, n / 2);
        float d2 = EfficientClosesPair(P2, Q2, n - n / 2);


        float d = min(d1, d2);
        int m = P[n / 2 - 1].x;
        int num = 0;
        POINT *S = searchPoint(Q, n, m, d, &num);

        float dminsq = d * d;

        int i;
        for (i = 0; i <= num - 2; ++i) {
            int k = i + 1;
            while (k <= num - 1 && (S[k].y - S[i].y) * (S[k].y - S[i].y) < dminsq) {
                dminsq = min((S[k].x - S[i].x) * (S[k].x - S[i].x) + (S[k].y - S[i].y) * (S[k].y - S[i].y), dminsq);
                k += 1;
            }
        }
        free(P1);
        free(P2);
        free(Q1);
        free(Q2);

        return sqrt(dminsq);
    }

}
int main() {
    int n;
    scanf("%d", &n);

    POINT *a = malloc(sizeof(POINT) * n);

    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i].x);
        scanf("%d", &a[i].y);
    }
    printf("-----\n");
    POINT *b = copy(a, n, 3);
    sort(b, n);


    float d = EfficientClosesPair(a, b, n);
    printf("The result is:%f\n", d);

    free(a);
    free(b);
    return 0;
}