#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;
long long dp[10001][3]; //0안먹음 1한번먹음 2두번먹음
int a[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] }); //안 먹으면 연속이 끝남. 셋 중에 큰값 선택
		dp[i][1] = dp[i - 1][0] + a[i]; //안 먹은 상태+지금꺼 한 잔
		dp[i][2] = dp[i - 1][1] + a[i]; //한번먹은 상태+지금꺼 한 잔
	}

	cout << max({ dp[n][0], dp[n][1], dp[n][2] }) << "\n";
}
