#include <stdio.h>
int n, num[2005], m, s, e, dp[2005][2005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < n; i++) dp[i][i] = 1; //자기 자신은 (i부터 i는) 항상 팰린드롬
	for (int i = 0; i < n; i++) { //자기랑 자기 앞이랑 같으면 팰린드롬
		if (num[i] == num[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}
	for (int k = 2; k < n; k++) { //자기랑 자기 앞앞 이상(k만큼 떨어진 수까지)이 팰린드롬인지 검사
		for (int i = 0; i < n - k; i++) { //k만큼 떨어지는거 검사할꺼니까 범위 안으로 넣어줌
			int j = i + k; //k만큼 떨어짐
			if (num[i] == num[j] && dp[i + 1][j - 1]) { //i랑 j가 같나? i~j가 펠린드롬인가?
				dp[i][j] = 1;
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");*/
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &s, &e);
		if(dp[s-1][e-1]) printf("1\n");
		else printf("0\n");
	}
}
