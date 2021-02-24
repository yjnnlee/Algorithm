#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001]; //합이 i일 때의 최소 제곱수의 합
int a[100001];
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i; //합 구하는 dp특징: 자기 자신을 최소 합으로 가진다
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
			//전체 항이 n이고 마지막 항이 i면 i를 제외한 부분은 n-i*i
			//여기선 합이 i이고 마지막 항이 j일 때를 하나씩 봐 주니까 i, j로 사용
		}
	}
	//for (int j = 0; j <= n; j++) {
	//	cout << dp[j] << " ";
	//}

	cout << dp[n];
}
