#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;

int main() {
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int s;
		cin >> s;
		vector<int> v;
		for (int i = 0; i < s; i++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		int now = v[0];
		int price = 1;
		int res = 0;
		for (int i = 0; i < s; i++) {
			if (v[i] > now) {
				price++;
				now = v[i];
				res += price;
			}
			else res += price;
		}
		cout << "Case #" << k << ": " << res << "\n";
	}
}
