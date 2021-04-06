#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int n, m;
vector<int> v;
long long res = -1;

int bsrch(int big) {
	long long l = 0, r = big - 1, mid, sum = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			int tmp = v[i] - mid;
			if (tmp < 0) continue;
			else sum += tmp;
		}
		if (sum < m) r = mid - 1;
		else {
			if (res < mid) res = mid;
			l = mid + 1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	long long int big = -1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; v.push_back(x);
		if (x > big) big = x;
	}
	sort(v.begin(), v.end());
	cout << bsrch(big);
}
