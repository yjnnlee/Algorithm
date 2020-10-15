#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
bool chk[10];
int n, m;
void go(int status, int cnt) {
	if (cnt == m) { //다 뽑음
		for (auto a : v) cout << a << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		//if (chk[i] == true) continue;
		//chk[i] = true;
		v.push_back(i+1);
		go(status, cnt + 1);
		v.pop_back();
		//chk[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	go(0, 0);
}
