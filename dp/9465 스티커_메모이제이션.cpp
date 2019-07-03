#include <stdio.h>
#include <algorithm>
using namespace std;
int t, n, dp[100001][3], sticker[2][100001];
long long int sum = 0;

int f(int j, int status) {
	//stauts 0-둘 다X, 1왼쪽 위 선택, 2왼쪽 아래 선택
	if (j == n) return 0;
	if (dp[j][status] != 0) return dp[j][status];

	int tmp = f(j + 1, 0);
	if (status == 0) dp[j][status] = max(f(j + 1, 1) + sticker[1][j], f(j + 1, 2) + sticker[0][j]);
	if (status == 1) dp[j][status] = max(f(j + 1, 2) + sticker[0][j], tmp);
	if (status == 2) dp[j][status] = max(f(j + 1, 1) + sticker[1][j], tmp);
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
				dp[i][j] = 0;
			}
		}
		printf("%d\n", f(0,0));	
	}
}
