#include <stdio.h>
#include <algorithm>
using namespace std;
int n, k, w[101], v[101], dp[101][100001];

int main(void) {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &w[i], &v[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= k; j++) {
			if (j < w[i]) dp[i][j] = dp[i + 1][j];
			else dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
		}
	}
	printf("%d", dp[0][k]);
}
