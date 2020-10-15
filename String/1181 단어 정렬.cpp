#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(string s1, string s2) {
	if (s1.size() == s2.size()) return s1 < s2;
	else return s1.size() < s2.size();
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<string> v;
	while (n--) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end()); //중복제거는 sort이후에 해야 된다
	for (auto x : v) cout << x << "\n";
}
