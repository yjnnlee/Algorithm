#include <stdio.h>
int n, k, now = 0, cost[15], res = 0;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cost[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (now + cost[i] <= k) {
			while (now + cost[i] <= k) {
				now += cost[i];
				res++;
				//printf("%d\n", now);
			}
		}
		if (now == k) break;
	}
	printf("%d", res);
}
