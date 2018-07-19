#include <stdio.h>
int dice[1000], sum[1000];
int n, a, b, c;

int biggest(int a, int b, int c) {
	if (a > b) {
		if (a > c) {
			return a;
		}
		else if (b > c) {
			return b;
		}
		else return c;
	}
	else if (b > c) {
		return b;
	}
	else return c;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == b && a == c && b == c) {
			sum[i] = 10000 + a * 1000;
		}
		else if (a == b || a == c) {
			sum[i] = 1000 + a * 100;
		}
		else if (b == c) {
			sum[i] = 1000 + b * 100;
		}
		else {
			sum[i] = biggest(a, b, c) * 100;
		}
	}

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (tmp < sum[i]) {
			tmp = sum[i];
		}
	}
	printf("%d", tmp);
}