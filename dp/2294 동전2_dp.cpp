#include <stdio.h>
#include <algorithm>
#define INF 1e9
using namespace std;
int n, k, coin[101], dp[10001];

int f(int v) {
	if (v < 0) return INF;
	if (v == 0) return 0;
	if (dp[v] > 0) return dp[v];
	int res = INF;
	for (int i = 0; i < n; i++) {
		res = min(res, f(v - coin[i])+1);
		dp[v] = res;
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		dp[i] = 1e9;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
		for (int j = 1; j <= n; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
			//min(원래 만들 수 있는 동전조합의 경우의 수, 가치가 coin[i]인 동전 1개 더함)
		}
	}
	



	int res = f(k);
	if (res == INF) printf("-1");
	else printf("%d", res);
}
//https://jaemin8852.tistory.com/163
//https://mygumi.tistory.com/129
