#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cal(vector<int>& a) {
	int sum = 0;
	for (int i = 1; i < a.size(); i++) {
		sum += abs(a[i] - a[i - 1]);
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int res = 0;
	do {
		int tmp = cal(a);
		res = max(res, tmp);
	} while (next_permutation(a.begin(), a.end()));
	cout << res;
}
