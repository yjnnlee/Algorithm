#include<iostream>
using namespace std;
int dp[1000005] = { 1,1,2,3, 5 };
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 5; i <= n; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1])%15746;
    }
    cout << dp[n]%15746;
}
