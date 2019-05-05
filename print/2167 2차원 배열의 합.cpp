#include <stdio.h>
int n, m, sum = 0, arr[305][305], k, a,b,c,d;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		--a, --b, --c, --d;
		for (int i = a; i <= c; i++) {
			for (int j = b; j <= d; j++) {
				sum += arr[i][j];
			}
		}
		printf("%d\n", sum);
		sum = 0;
	}
}
