#include <stdio.h>
#define MAX 8
int queens[MAX];
int count = 0;
int judge() {
    int i, n;
    for (n = 1; n < 8; ++n) {
        for (i = 0; i < n; ++i) {
            if (queens[i] == queens[n] || queens[i] == queens[n] + i - n || queens[i] == queens[n] + n - i) {
                return 0;
            }
        }
    }
    return 1;
}
void fn(int n) {
    int i;
    for (i = 0; i < MAX; ++i) {
        queens[n] = i;
        if (n == MAX - 1) {
            if (judge()) {
                count++;
            }
        } else {
            fn(n + 1);
        }
    }
}
int main() {

    fn(0);

    // for (queens[0] = 0; queens[0] < MAX; ++queens[0]) {
    //     for (queens[1] = 0; queens[1] < MAX; ++queens[1]) {
    //         for (queens[2] = 0; queens[2] < MAX; ++queens[2]) {
    //             for (queens[3] = 0; queens[3] < MAX; ++queens[3]) {
    //                 for (queens[4] = 0; queens[4] < MAX; ++queens[4]) {
    //                     for (queens[5] = 0; queens[5] < MAX; ++queens[5]) {
    //                         for (queens[6] = 0; queens[6] < MAX; ++queens[6]) {
    //                             for (queens[7] = 0; queens[7] < MAX; ++queens[7]) {
    //                                 if (judge()) {
    //                                     count++;
    //                                 }
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    printf("%d\n", count);
    return 0;
}