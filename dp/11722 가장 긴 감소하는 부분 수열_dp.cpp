#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;
int dp[1001]; //i가 마지막 수인 증가하는 수열의 길이
int a[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		dp[i] = 1; //만약 아래 for문에서 하나도 해당되는 수가 없어도, 1을 최고 길이로 가진다!!
		for (int j = i - 1; j >= 0; j--) { //본인보다 앞의 수를 보며 자기보다 작은(증가수열이 되는 수)수를 찾음
			if (a[j] > a[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		//cout << dp[i] << " ";
		res = max(res, dp[i]);
	}
	cout << res;
}
