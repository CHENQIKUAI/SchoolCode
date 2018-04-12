#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXtaken 6
#define MINtaken 1

int randNum(void);
void mesg(int n);
void choose(int *first);
void game(int n, int state, char *result);
void show(char * result);
int main(int argc, char const *argv[])
{
    int first = -1000;
    char *result = (char *)malloc(sizeof(char) * 10);
    srand((unsigned)time(NULL));
    int n = randNum();
    mesg(n);
    choose(&first);
    game(n, first, result);
    show(result);
    free(result);
    return 0;
}
int randNum(void) {
    return rand() % 100 + MINtaken;
}

void mesg(int n) {
    printf("Hi, welcome to 'SMART MAN GAME'\n");
    printf("\n");
    printf("There are %d matches\n", n);
    printf("You can fetch %d most, and %d least\n", MAXtaken, MINtaken);
    printf("The one who fetches the last match is WINNER\n");
    printf("\n");
}

void choose(int *first) {
    printf("What do you perfer? First not later?\n");
    printf("\n");
    printf("Please input your choice with 1(first) or 0(later):  ");
    scanf("%d", first);
    printf("\n");
    while (*first != 1 && *first != 0) {
        printf("Error input. Please input again:  ");
        scanf("%d", first);
    }
}

void game(int n, int state, char *result) {
    int manfetch;
    if (state == 1) { //man first;
        printf("How many will you fetch:  ");
        scanf("%d", &manfetch);
        while (manfetch > MAXtaken || manfetch < MINtaken || manfetch > n) {
            printf("Error input.Please input again:  ");
            scanf("%d", &manfetch);
        }
        n -= manfetch;
        if (n == 0) {
            strcpy(result, "YOU WIN! Congratulations!");
            return;
        }
    }

    while (1) {

        //computer choose;
        if (n <= MAXtaken) {
            printf("\ncomputer's choice: %d\n", n);
            printf("\n");
            strcpy(result, "YOU LOSE! So sadness!");
            return;
        } else {
            int temp;
            if (n % (MINtaken + MAXtaken) != 0) {
                temp = n % (MINtaken + MAXtaken);
            } else {
                temp = (rand() % MAXtaken + MINtaken);
            }
            printf("\ncomputer's choice: %d\n", temp);
            n -= temp;
        }


        //show the n;
        printf("----n is : %d----\n", n);
        if (n <= MAXtaken) {
            printf("\n");
            strcpy(result, "YOU WIN! Congratulations!");
            return;
        }

        //your turn
        printf("\n");
        printf("How many will you fetch:  ");
        scanf("%d", &manfetch);
        while (manfetch > MAXtaken || manfetch < MINtaken || manfetch > n) {
            printf("Error input. Please input again:  ");
            scanf("%d", &manfetch);
        }
        n -= manfetch;
        if (n == 0) {
            printf("\n");
            strcpy(result, "YOU WIN! Congratulations!");
            return;
        }
    }
}

void show(char * result) {
    printf("%s\n", result);
}