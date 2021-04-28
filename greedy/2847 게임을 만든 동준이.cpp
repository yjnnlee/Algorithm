#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int a[101];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	int cnt = 0;
	cin >> n;
	if (n == 1) cout << 1;
	else {
		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = n - 1; i > 0; i--) {
			if (a[i] <= a[i - 1]) { //뒤에서부터 시작해서 앞이 더 크면 깎는다
				while (a[i] <= a[i - 1]) {
					a[i - 1]--;
					cnt++;
				}
			}
		}
	}
	cout << cnt;

}
