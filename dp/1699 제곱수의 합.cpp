#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n, dp[100001];
	cin >> n;
	for (int i = 0; i <= n; i++) dp[i] = i;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n];
}
