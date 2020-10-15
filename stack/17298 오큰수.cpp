#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int n;
vector<int> v;
stack<int> s;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	vector<int> res(n, -1);
	for (int i = 0; i < n; i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			//cout << v[i] << " ";
			res[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
	for (auto i : res) cout << i << " ";
}
