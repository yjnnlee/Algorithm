#include<iostream>

#define endl "\n"
#define MODULER 15746
#define MAX 1000000 + 1
using namespace std;

int N, int dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] = dp[i] % MODULER;
    }
    cout << dp[N] << endl;
}
