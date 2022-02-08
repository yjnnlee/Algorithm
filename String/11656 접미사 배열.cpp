#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string s;
vector<string> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		v.push_back(s.substr(i, s.length()));
	}

	sort(v.begin(), v.end());
	for (auto x : v) cout << x << "\n";
	return 0;
}
