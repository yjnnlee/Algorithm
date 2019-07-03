#include <stdio.h>

#define NM 1000
int n, dp[NM+1];

int f(int a /*i*/) {
	if (a == 0 || a == 1) return 1;
	if (a < NM && dp[a] != 0) return dp[a];

	return dp[a] = (f(a - 1) + f(a - 2)) % 10007;
}

int main() {
	scanf("%d", &n);
	printf("%d", f(n));
}
