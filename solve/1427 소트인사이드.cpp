#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(char s1, char s2) {
	return s1 > s2;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	vector<char> v;
	for (int i = 0; i < s.size(); i++) v.push_back(s[i]);
	sort(v.begin(), v.end(), cmp);
	for (auto a : v) cout << a;
}
