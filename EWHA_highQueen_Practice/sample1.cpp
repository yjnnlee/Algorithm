#include <stdio.h>
int n, a, b, k[10001];
int main() {
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
	}
	int min = k[a], max = k[a];

	for (int i = a + 1; i <= a+b;i++) {
		if (k[i] > max) {
			max = k[i];
		}
		if (k[i] < min) {
			min = k[i];

		}
	}
	printf("%d %d", min, max);
}
