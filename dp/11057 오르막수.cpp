#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;
int dp[1001][1001]; //i자릿수이면서 마지막 수가 j인 오르막 수
int main() {
	int x;
	cin >> x;
	if (x == 1) cout << 10;
	else {
		for (int i = 0; i <= 9; i++) dp[1][i] = 1;
		for (int i = 2; i <= x; i++) {
			//참고로 0으로 시작하는 수 09, 009, 0009 같은 것도 다 다른 수로 취급하는 듯
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= j; k++) {
					dp[i][j] += dp[i - 1][k]; //숫자 n이 있으면 그 전 자리는 0~n-1의 수가 가능
					dp[i][j] %= 10007; //합 계산이라 초과될 가능성 있음 mod연산을 중간에 넣음
				}
			}
		}
		long long sum = 0;
		for (int i = 0; i <= 9; i++) {
			//cout << dp[x][i] << endl;
			sum += dp[x][i];
		}
		cout << sum % 10007;
	}
}
