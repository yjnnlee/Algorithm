#include <stdio.h>
#include <algorithm>
using namespace std;
//반도체 설계

int n, a[40001],dp[40001], res=0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	dp[0] = a[0];
	int now = 0;

	for (int i = 1; i < n; i++) {
		if (dp[now] < a[i]) { //나보다 작은 수를 발견하면
			now++;
			dp[now] = a[i]; //그 다음수에다가 값을 넣어줌
		}
		else { //아니면 넣을만한 곳을 찾음
			int tmp = lower_bound(dp, dp + now, a[i]) - dp;
			dp[tmp] = a[i];
		}
	}

	printf("%d", now + 1);
}
