#include <stdio.h>
int n, m, cnt = 0, a[1005], i;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	while (cnt != k) {
		for (i = 2; i <= n; i++) if (a[i] == 0) break;
		if (i == 1000) break;

		for (int j = 1; j * i <= n; j++) {
			if (a[i*j] == 0) {
				a[i * j] = i*j;
				++cnt;
			}

if (cnt == k) {
				printf("%d", i*j);
				return 0;
			}
		}
	}
}
