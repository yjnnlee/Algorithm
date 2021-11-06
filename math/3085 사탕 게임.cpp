#include <iostream> //1번 코드
#include <vector>
#include <algorithm>
using namespace std;
int check(vector<string> &a) {
    int n = a.size();
    int ans = 1;
    for (int i=0; i<n; i++) {
        int cnt = 1;
        for (int j=1; j<n; j++) {
            if (a[i][j] == a[i][j-1]) {
                cnt += 1;
            } else {
                cnt = 1;
            }
            if (ans < cnt) ans = cnt;
        }
        cnt = 1;
        for (int j=1; j<n; j++) {
            if (a[j][i] == a[j-1][i]) {
                cnt += 1;
            } else {
                cnt = 1;
            }
            if (ans < cnt) ans = cnt;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j+1 < n) {
                swap(a[i][j], a[i][j+1]);
                int temp = check(a);
                if (ans < temp) ans = temp;
                swap(a[i][j], a[i][j+1]);
            }
            if (i+1 < n) {
                swap(a[i][j], a[i+1][j]);
                int temp = check(a);
                if (ans < temp) ans = temp;
                swap(a[i][j], a[i+1][j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
