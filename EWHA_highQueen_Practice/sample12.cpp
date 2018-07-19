#include <stdio.h>
#include <algorithm>
using namespace std;

int n, dp[10000], a[10000];
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	dp[0] = a[0];
	dp[1] = max(a[0]+a[1], a[1]);
	dp[2] = max(a[0]+a[2], a[1]+a[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + a[i], dp[i - 3] + a[i] + a[i - 1]);
	}

	printf("%d", dp[n - 1]);
}
