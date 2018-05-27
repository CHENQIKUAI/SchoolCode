#include <stdio.h>
int length[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int price[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int income(int n) {
	int profit[n];

	for (int i = 1; i <= n; ++i) {
		int money = 0;
		int cut;
		if (i <= 10) {
			cut = i;
		} else {
			cut = 10;
		}
		while (cut >= 1) {
			int temp;
			if (i - cut - 1 == -1) {
				temp = price[cut - 1];
			} else {
				temp = profit[i - cut - 1] + price[cut - 1];
			}
			money = money > temp ? money : temp;
			cut--;
		}
		profit[i - 1] = money;
	}
	return profit[n - 1];
}
int main(int argc, char const *argv[])
{
	int n;
	for(int i = 0; i < 10; ++i){
		printf("When the length is %d, the price is %d\n", i+1, price[i]);
	}
	printf("Please input a number that we can calculate the max benifit.\n");
		scanf("%d", &n);
		printf("%d\n", income(n));

	return 0;
}