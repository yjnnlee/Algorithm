#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001]; //i가 마지막 수인 최대 수열의 합
int a[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + a[i], a[i]); //이전까지의 합+현재합vs현재부터 시작(연속끊기)
	}
	int res = -9999; //-1000까지 범위임을 주의
	for (int i = 0; i < n; i++) {
		//cout << dp[i] << " ";
		res = max(res, dp[i]);
	}
	cout << res;
}
