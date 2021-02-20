#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[10000001];
int f(int n) {
	//cout << n << " "<<cnt<<endl;
	if (n == 1) return 0;
	else if (dp[n]) return dp[n];
	else {
		dp[n] = f(n - 1) + 1;
		if (n % 3 == 0) dp[n] = min(f(n / 3) + 1, dp[n]);
		if (n % 2 == 0) dp[n] = min(f(n / 2) + 1, dp[n]);
	}
	return dp[n];
}

int main() {
	int x;
	cin >> x;
	cout << f(x);
}
