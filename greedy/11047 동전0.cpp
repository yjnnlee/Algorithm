#include <iostream>
#include <algorithm>
using namespace std;

int n, k, a[11], sum = 0, cnt = 0;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = n - 1;
	while (sum < k) {
		if (sum + a[i] <= k) {
			sum += a[i];
			cnt++;
		}
		else i--;
	}
	cout << cnt;
}
