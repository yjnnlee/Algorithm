#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;

int bsrch(int want) {
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (v[mid] == want) return 1;
		else if (want < v[mid]) {
			right = mid - 1;
		}
		else if (want > v[mid]) {
			left = mid + 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; v.push_back(x);
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << bsrch(x) << "\n";
	}
}
