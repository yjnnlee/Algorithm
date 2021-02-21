#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;
long long dp[100][2]; //i자릿수이면서 마지막 수가 j인 이친수
int main() {
	int x;
	cin >> x;
	dp[1][0] = 0;
	dp[1][1] = 1;
	if (x == 1) cout << 1;
	else {
		for (int i = 2; i <= x; i++) {
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
		}
		//for (int i = 1; i <= x; i++) {
		//	cout << dp[i][0] << " " << dp[i][1] << endl;
		//}
		cout << dp[x][0] + dp[x][1];
	}
	//long long으로 하지 않으면 합 구하다가 터지는 듯 하다
}
