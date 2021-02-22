#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;
long long dp[1001]; //i가 마지막 수인 증가하는 수열의 합
int a[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		dp[i] = a[i]; //만약 아래 for문에서 하나도 해당되는 수가 없어도, 자기 자신을 최소 합으로 가짐을 주의한다!!
		for (int j = i - 1; j >= 0; j--) { //본인보다 앞의 수를 보며 자기보다 작은(증가수열이 되는 수)수를 찾음
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + a[i]);
			}
		}
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		//cout << dp[i] << " ";
		res = max(res, dp[i]);
	}
	cout << res;
}
