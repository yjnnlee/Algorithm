#include <stdio.h>
#include <string.h>
char a[50];
int dp[100][100], res[100];

int main() {
	scanf("%s", a);
	int n = strlen(a);

	for (int i = 0; i < n; i++) {
		dp[i][i] = 1; //a -> a
		if (a[i] == a[i + 1]) dp[i][i + 1] = 3; //aa -> a, a, aa
		else dp[i][i + 1] = 2; //ab -> a, b
	}

	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n - k; i++) {
			int j = k + i;
			if (i > j) break;
			dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
			
			if (a[i] == a[j]) {
				dp[i][j] += dp[i + 1][j - 1] + 1;
			}
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		printf("%d ", dp[i][j]);
	//	}
	//	printf("\n");
	//}
	printf("%d", dp[0][n-1]);
}
