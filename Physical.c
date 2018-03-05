//2018.3.5
//Peter
//The difference between mac and linux(or windows)
//在mac和linux下会有相反的显示 这时由于其系统的物理层不同而造成的

#include <stdio.h>
int main(int argc, char const *argv[])
{
	unsigned int a = 256;
	printf("%p\n", &a);

	printf("-------------\n");

	char *p = (char*)&a;
	printf("%p %d\n", p,  *p);
	printf("%p %d\n", p + 1 * sizeof(char), *(p + 1 * sizeof(char)));
	printf("%p %d\n", p + 2 * sizeof(char), *(p + 2 * sizeof(char)));
	printf("%p %d\n", p + 3 * sizeof(char), *(p + 3 * sizeof(char)));

	printf("--------------\n");

	printf("%p %d\n", &a, a);
	// char c = 'c';
	// printf("%d\n", c);

	return 0;
}
