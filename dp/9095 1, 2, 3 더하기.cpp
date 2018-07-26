#include <stdio.h>
int n, dp[20] = { 0, 1,2,4 }, m;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		for (int j = 4; j <= m; j++) {
			if (dp[j] != 0) continue;
			else {
				dp[j] += dp[j - 3] + dp[j - 2] + dp[j - 1];
				//printf("dp[%d] = %d\n", j, dp[j]);
			}
		}
//		printf("%d %d\n\n", dp[1], dp[2]);
		printf("%d\n", dp[m]);
	}
}
