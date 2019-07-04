#include <stdio.h>
#include <algorithm>
#define INF 1e9
using namespace std;
int n, k, coin[101], dp[10001];

int f(int v) {
	if (v < 0) return INF;
	if (v == 0) return 0;
	int res = 1e9;
	for (int i = 0; i < n; i++) {
		res = min(res, f(v - coin[i])+1);
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	int res = f(k);
	if (res == INF) printf("-1");
	else printf("%d", res);
}
