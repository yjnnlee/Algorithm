#include <stdio.h>
int x, y, res = 0;
char *date[10] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int main() {
	scanf("%d %d", &x, &y);
	for (int i = 1; i < x; i++) {
		if (x == 1) break;
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			res += 31;
		}
		else if (i == 2) res += 28;
		else res += 30;
	}
	res += y;
	printf("%s", date[res%7]);
}
