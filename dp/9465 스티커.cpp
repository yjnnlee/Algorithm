#include <stdio.h>
#include <algorithm>
using namespace std;
int t, n, dp[100001][3], sticker[2][100001];
long long int sum = 0;

int f(int j, int status) {
	//stauts 0-둘 다X, 1왼쪽 위 선택, 2왼쪽 아래 선택
	if (j == n) return 0;
	if (dp[j][status] != -1) return dp[j][status]; //조건을 0으로 하면 스티커 값이 전부 0일 때 메모이제이션이 작동을 안 함->시간초과
  //메모이제이션의 초기값은 나올 수 없는 값으로 (-1같이) 설정해줘야 함 주의

	dp[j][status] = f(j + 1, 0);
	if (status == 0) dp[j][status] = max(f(j + 1, 1) + sticker[1][j], f(j + 1, 2) + sticker[0][j]);
	if (status == 1) dp[j][status] = max(f(j + 1, 2) + sticker[0][j], dp[j][status]);
	if (status == 2) dp[j][status] = max(f(j + 1, 1) + sticker[1][j], dp[j][status]);	
	return dp[j][status];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &sticker[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = -1;
			}
		}
		printf("%d\n", f(0,0));	
	}
}
