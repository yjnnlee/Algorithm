#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dp[10001] = { "0","1","1" };
string sum(string x, string y) {
	//string덧셈-각 숫자를 더하고 올림이 생기면 다음 자리수에 같이 더함
	int sum = 0; //올림수
	string res; //계산 결과
	while (!x.empty() || !y.empty() || sum) {
		if (!x.empty()) {
			sum += x.back() - '0';
			x.pop_back();
		}
		if (!y.empty()) {
			sum += y.back() - '0';
			y.pop_back();
		}
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) { //13+21=34
		dp[i] = sum(dp[i - 2], dp[i - 1]);
	}
	cout << dp[n];
}
