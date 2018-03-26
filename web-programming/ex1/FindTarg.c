#include <stdio.h>
#include <stdlib.h>
int isBegin(char ch, FILE *fp) {
	if (ch == '<') {
		ch = fgetc(fp);
		if (ch != '/') {
			fseek(fp, -1, SEEK_CUR);
			return 1;
		}
	}
	return 0;
}
void getStr(FILE *fp, char *p, int *i) {
	char ch = fgetc(fp);
	*p = ch;
	while (!isEnd(fp)) {
		ch = fgetc(fp);
		if (ch == ';' || ch == '\"') {
			*i -= 1;
			break;
		}
		p++;
		*p = ch;
	}
	*i += 1;
}
int isEnd(FILE *fp) {
	char ch;
	ch = fgetc(fp);
	if (ch == ' ' || ch == '>') {
		return 1;
	}
	fseek(fp, -1, SEEK_CUR);
	return 0;
}
int main(int argc, char const *argv[])
{
	FILE*fp;
	FILE *fpp = fopen("output.csv", "a");
	fp = fopen("taobao.html", "r");
	char ch;
	char *str[100000];
	int i = 0, j;
	while ((ch = fgetc(fp)) != EOF) {
		if (isBegin(ch, fp)) {
			str[i] = (char*)malloc(10);
			getStr(fp, str[i], &i);
		}

	}
	for (j = 0; j < i; ++j) {
		fprintf(fpp, "%s\n", str[j]);
	}

	fclose(fp);
	fclose(fpp);
	return 0;
}