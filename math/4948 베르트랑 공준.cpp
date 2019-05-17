#include <stdio.h>
int n, a[246915];
long long int cnt = 0;
int main() {
	for (int i = 2; i <= 246915; i++) a[i] = i;

	for (int i = 2; i * i <= 246915; i++) {
		if (a[i]) {
			for (int j = i * 2; j <= 246915; j += i) {
			
				a[j] = 0;
			}
		}
	}

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		for (int i = n + 1; i <= 2*n; i++) {
			if (a[i]) cnt++;
		}
		printf("%lld\n", cnt);
		cnt = 0;
	}
}
