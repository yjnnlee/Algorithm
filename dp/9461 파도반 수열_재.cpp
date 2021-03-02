#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
long long dp[101];

int main() {
    int n;
    cin >> n;
    dp[0] = dp[1] = dp[2] = 1;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 3; i <= x; i++) {
            dp[i] = dp[i - 2] + dp[i - 3];
        }
        cout << dp[x - 1] << "\n";
    }
}
