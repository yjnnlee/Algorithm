#include <stdio.h>
int n, a,b, sum, res = 0, newn;

int main() {
	scanf("%d", &n);
	newn = n;
	do {
		b = newn % 10;
		a = newn / 10;
		sum = a + b;
		newn = b * 10 + (sum%10);
		res++;
	} while (newn != n);
	printf("%d", res);
}
