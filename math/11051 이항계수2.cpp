#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int dp[1001][1001];

/*
이항계수 (n k) = nCk = n!/(n-k)!k! (0<=k<=n) 이다
점화식으로는
(n k) = (n-1, k) + (n-1, k-1)   | 0<k<n
      =  1                      | n==k or k=0

이유:
원소가 {1,2,3,4}가 있을 때 3개 뽑는 상황은 4C3
원소 1을 기준으로 보면
-원소 1을 선택: 나머지 3개 중 2개 선택 3C2
-원소 1을 선택 안 함: 나머지 3개 중 3개 선택 3C3
각 경우를 더한 결과가 4C3의 모든 경우
4C3=3C2+3C3 점화식과 같음

DP로 구현한다
중복 부분문제-중복되는 함수 호출
최적 부분구조-각 부분문제의 최적값이 전체 문제의 최적값
둘 다 만족하므로 DP 문제
*/

int go(int n, int k) {
	if (n == k || k == 0) return 1;

	if (dp[n][k] == 0) dp[n][k] = go(n - 1, k) % 10007 + go(n - 1, k - 1) % 10007;
	return dp[n][k];
}
//메모이제이션 안 쓰면 시간 초과

//int go(int n, int k) {
//	for (int i = 0;i < n;i++) {
//		for (int j = 0;j <= min(k, i);j++) {
//			if (i == j || j == 0) {
//				dp[i][j] = 1;
//			}
//			else dp[i][j] = dp[i - 1][j]%10007 + dp[i - 1][j - 1]%10007;
//		}
//	}
//	return dp[n][k];
//}
//이건 왠지 안 된다 확인 필요

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, k;
	cin >> x >> k;
	cout << go(x, k)%10007;
}
