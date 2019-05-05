#include <stdio.h>
#include <math.h>
int a, b, c, cnt=0, flag = 1;
double res;
int main() {
	while (1) {
		++cnt;
		flag = 1;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) return 0;
		if (c == -1) {
			res = a*a + b*b;
		}
		if (a == -1) {
			if (b < c) {
				res = c*c - b*b;
				res += b*b;
			}
			else {
				flag = 0;
			}
		}
		if (b == -1) {
			if (a < c) {
				res = c*c - a*a;
				res += a*a;
			}
			else {
				flag = 0;
			}
		}
		printf("Triangle #%d\n", cnt);
		if ((sqrt(res) < c) || flag == 0) {
			printf("Impossible.\n");
		}
		else  {
			if (c == -1) printf("c = %.3lf\n", sqrt(res));
			if (a == -1) printf("a = %.3lf\n", sqrt(res-b*b));
			if (b == -1) printf("b = %.3lf\n", sqrt(res-a*a));
		}
		printf("\n");
	}
}
