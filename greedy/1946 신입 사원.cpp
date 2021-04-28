#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<pair<int, int>> v;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cnt = n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end(), cmp);
		int small = v[0].second;
		for (int i = 1; i < n; i++) {
			if (v[i].second > small) cnt--;
			small = min(v[i].second, small);
		}
		cout << cnt << "\n";
		v.clear();
	}	
}
