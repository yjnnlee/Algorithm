#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;
int dp[15];
int main() {
	int x;
	cin >> x;
	dp[4] = 7;
	dp[3] = 4;
	dp[2] = 2;
	dp[1] = 1;
	for (int i = 5; i <= 11; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]);
	}

	while (x--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}
