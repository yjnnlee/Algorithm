#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int calc(vector<int>& a, vector<int>& d) {
	int len = a.size(), sum = a[0];
	for (int i = 1; i < len; i++) {
		if (d[i - 1] == 0) sum += a[i]; //더하기
		if (d[i - 1] == 1) sum -= a[i]; //빼기
		if (d[i - 1] == 2) sum *= a[i]; //곱셈
		if (d[i - 1] == 3) sum /= a[i]; //나눗셈
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;

	cin >> n;
	vector<int> a(n), d;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0, t; i < 4; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) d.push_back(i);
	}
	sort(d.begin(), d.end());
	vector<int> res;
	do {
		//			for (auto& x : d) cout << x << ' '; cout << endl;
		int sum = calc(a, d);
		res.push_back(sum);
	} while (next_permutation(d.begin(), d.end()));
	auto ans = minmax_element(res.begin(), res.end()); //최소, 최대
	cout << *ans.second << '\n' << *ans.first; //최대, 최소

}
