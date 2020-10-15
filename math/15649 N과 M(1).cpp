#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

bool chk(int n) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == n) return true;
	}
	return false;
}

void go(int n, int m) { //순열
	if (v.size() == m) {
		for (auto a : v) cout << a << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (chk(i)) continue; //이미 들어있는 값인지 체크(중복제거)
		v.push_back(i);
		go(n, m);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	go(n, m);
}
