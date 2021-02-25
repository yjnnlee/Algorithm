#include <iostream>
#include <algorithm>
using namespace std;
int dp[31]; //3xn 직사각형 채우는 방법의 수

int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	int res = 0;
	if (n % 2 == 0) {
		for (int i = 4; i <= n; i += 2) {
			dp[i] = dp[i - 2] * dp[2];
			for (int j = i - 4; j >= 0; j -= 2) {
				dp[i] += dp[j] * 2;
			}
		}
		res = dp[n];
	}
	cout << res;
}

//https://foxtrotin.tistory.com/456
