#include <stdio.h>
int month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
char *day[] = { "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday" };
//char *day[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
int d, m;
int main() {
	scanf("%d%d", &d, &m);
	for (int i = 0; i < m - 1; i++) {
		d += month[i];
	}
	printf("%s", day[d % 7]);
}
