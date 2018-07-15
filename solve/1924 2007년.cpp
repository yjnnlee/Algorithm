#include <stdio.h>
int month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
char *day[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int a, b;
int main(){
	scanf("%d%d", &a, &b);
	for (int i = 0; i < a - 1; i++) {
		b += month[i];
	}
	printf("%s", day[b % 7]);
}
