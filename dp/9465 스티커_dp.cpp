#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;
long long dp[100001][3]; //0안뗌 1위뗌 2아래뗌
int a[2][100001];
int main() {
	int x;
	cin >> x;
	while (x--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) { //0윗줄, 1아랫줄
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		for (int i = 1; i<= n; i++) {
			dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] }); //안뜯->그 전도 안뜯/위뜯/아래뜯
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[0][i]; //위뜯->그 전 아래뜯/안뜯
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + a[1][i]; //아래뜯->그 전 위뜯/안뜯
		}
	
		cout << max({ dp[n][0], dp[n][1], dp[n][2] }) << "\n";
	}
}
