#include <stdio.h>
int n, a, b;
long long int dp[100][100];
int main() {
	scanf("%d", &n);

	for (int k = 0; k < n; k++) {
		scanf("%d %d", &a, &b);
		for (int i = 0; i < b; i++) {
			dp[0][i] = i + 1;
		}
		/*for (int i = 0; i <= b; i++) {
			for (int j = 0; j <= b; j++) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}*/
		for (int i = 1; i < a; i++) {
			for (int j = i; j < b; j++) {
				/*dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];*/
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j-1];
			}
		}
		printf("%d\n", dp[a-1][b-1]);
	}
}
