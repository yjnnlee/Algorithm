#include <stdio.h>
int n, m, k, q = 0;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (q == k) {
				printf("%d %d", i, j);
				return 0;
			}
			q++;
		}
	}
}
