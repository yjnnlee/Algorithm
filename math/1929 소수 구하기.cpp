#include <stdio.h>
int n, m, cnt = 0, a[1000001];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 2; i <= 1000001; i++) a[i] = i;

	for (int i = 2; i * i <= 1000001; i++) {
		if (a[i]) {
			for (int j = i * 2; j <= 1000001; j += i) a[j] = 0;
		}
	}

	for (int i = n; i <= m; i++) {
		if (a[i]) printf("%d\n", a[i]);
	}
}
