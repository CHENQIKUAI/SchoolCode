#include <stdio.h>
typedef struct event EVENT;
struct event
{
	int s;
	int f;
};

void arangeEvents(EVENT events[], int n) {
	//sort
	// for (int j = 0; j < n - 1; j++)
	// {
	// 	for (int i = 0; i < n - 1 - j; i++)
	// 	{
	// 		if (events[i].f > events[i + 1].f)
	// 		{
	// 			int f = events[i].f;
	// 			int s = events[i].s;

	// 			events[i].f = events[i + 1].f;
	// 			events[i].s = events[i + 1].s;
	// 			events[i + 1].f = f;
	// 			events[i + 1].s = s;
	// 		}
	// 	}
	// }

	EVENT a[n];
	a[0].s = events[0].s;
	a[0].f = events[0].f;

	int count = 1;

	for (int i = 1; i < n; ++i) {
		if (a[count - 1].f < events[i].s) {
			a[count].s = events[i].s;
			a[count].f = events[i].f;
			count++;
		}
	}

	for(int i = 0 ; i < count; ++i){
		printf("%d %d\n", a[i].s, a[i].f);
	}
}

int main(int argc, char const *argv[])
{
	EVENT events[11];
	events[0].s = 1;
	events[0].f = 4;
	events[1].s = 3;
	events[1].f = 5;
	events[2].s = 0;
	events[2].f = 6;
	events[3].s = 5;
	events[3].f = 7;
	events[4].s = 3;
	events[4].f = 8;
	events[5].s = 5;
	events[5].f = 9;
	events[6].s = 6;
	events[6].f = 10;
	events[7].s = 8;
	events[7].f = 11;
	events[8].s = 8;
	events[8].f = 12;
	events[9].s = 2;
	events[9].f = 13;
	events[10].s = 12;
	events[10].f = 14;

	arangeEvents(events, 11);
	return 0;
}