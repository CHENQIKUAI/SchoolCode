#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int transfer(char ch) {
	return ch - '0';
}

int getSignSymbol(char * chNum) {
	if (chNum[0] == '-') return -1;
	else {
		return +1;
	}
}

int indexAfterSign(char *num) {
	if (num[0] == '+' || num[0] == '-') {
		return 1;
	} else {
		return 0;
	}
}

int whichOneAbsLarger(char* chNum1, char* chNum2) {
	int len1 = strlen(chNum1);
	int len2 = strlen(chNum2);
	int lenOfNum1 = len1;
	int lenOfNum2 = len2;

	int index1 = 0;
	int index2 = 0;

	if (chNum1[0] == '-' || chNum1[0] == '+') {
		index1 = 1;
		lenOfNum1--;
	}

	if (chNum2[0] == '-' || chNum2[0] == '+') {
		index2 = 1;
		lenOfNum2--;
	}

	if (lenOfNum1 > lenOfNum2) {
		return 1;
	}

	if (lenOfNum1 < lenOfNum2) {
		return -1;
	}

	while (index1 < len1 && index2 < len2) {
		if (chNum1[index1] != chNum2[index2]) {
			return (chNum1[index1] - chNum2[index2] < 0) ? -1 : 1;
		}
		index1++;
		index2++;
	}

}


void reverse(int* num, int length) {
	for (int index = 0; index < length / 2; ++index) {
		int temp = num[index];
		num[index] = num[length - index - 1];
		num[length - index - 1] = temp;
	}
}

int removeZero(int* num, int length) {
	int index = 0;
	while (index < length && num[index] == 0) {
		index++;
	}

	if (index < length) {
		int lenOfReal = length - index;
		for (int i = 0; i < lenOfReal; ++i) {
			num[i] = num[index + i];
		}
		return lenOfReal;
	} else {
		num[0] = 0;
		return 1;
	}
}

int main(int argc, char const * argv[])
{
	char chNum1[20], chNum2[20];
	int num3[21];
	scanf("%s", chNum1);
	scanf("%s", chNum2);
	char* num1 = chNum1;
	char* num2 = chNum2;

	int whichOne = whichOneAbsLarger(chNum1, chNum2);
	if (whichOne == -1) {
		num1 = chNum2;
		num2 = chNum1;
	}

	int valueOfSign1 = getSignSymbol(num1);
	int valueOfSign2 = getSignSymbol(num2);
	int multi1 = 1;
	int multi2 = 1;

	if (valueOfSign1 != valueOfSign2) {
		multi1 = 1;
		multi2 = -1;
	} else {
		multi1 = 1;
		multi2 = 1;
	}

	int index1 = strlen(num1) - 1;
	int index2 = strlen(num2) - 1;
	int index3 = 0;

	int numStartIndex1 = indexAfterSign(num1);
	int numStartIndex2 = indexAfterSign(num2);

	int carry = 0;
	while (index1 >= numStartIndex1 && index2 >= numStartIndex2) {
		int n1 = multi1 * transfer(num1[index1]);
		int n2 = multi2 * transfer(num2[index2]);
		int n3 = (n1 + n2 + carry + 10) % 10;
		carry = (n1 + n2 + carry < 0) ? -1 : (n1 + n2 + carry) / 10;
		num3[index3] = n3;
		index3++;
		index1--;
		index2--;
	}

	while (index1 >= numStartIndex1) {
		int n = transfer(num1[index1]);
		int n3 = (n + carry + 10) % 10;
		carry = (n + carry < 0) ? -1 : (n + carry) / 10;
		num3[index3] = n3;
		index1--;
		index3++;
	}

	while (index2 >= numStartIndex2) {
		int n = transfer(num2[index2]);
		int n3 = (n + carry + 10) % 10;
		carry = (n + carry < 0) ? -1 : (n + carry) / 10;
		num3[index3] = n3;
		index2--;
		index3++;
	}

	if (carry != 0) {
		num3[index3] = carry;
		index3++;
	}

	reverse(num3, index3);
	int lenOfNum3 = removeZero(num3, index3);

	if (valueOfSign1 == valueOfSign2) {
		valueOfSign1 == 1 ? printf("") : printf("-");
	} else {
		valueOfSign1 == 1 ? printf("") : printf("-");
	}

	for (int i = 0; i < lenOfNum3; ++i) {
		printf("%d", num3[i]);
	}

	return 0;
}