#include <stdio.h>
#include <math.h>
int n, a[105], sum = 0, averprice = 0;
long double res = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	averprice = sum / n;

	for (int i = 0; i < n; i++) {
		res += pow(a[i] - averprice, 2);
	}

	printf("%d\n%d\n%.1lf", sum, averprice, sqrt(res/n));
}
