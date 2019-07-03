#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
long long dp[1000005] = { 1,1 };

int main() {
	scanf("%d", &n);
	if (n == 1 || n== 2) { printf("1"); return 0;}
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	}
	printf("%d", dp[n]);
}
