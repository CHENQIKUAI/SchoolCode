#include <stdio.h>
#include <string.h>
int main() {
	char a[1000] = "你好";
	printf("%d\n", strlen(a));
	char b[1000];
	int i;
	for (i = 0 ; i < strlen(a); ++i) {
		printf("%d ", a[i]);
		b[i] = a[i];
	}
	b[i] = '\0';
	printf("%s\n", b);




	return 0;
}
