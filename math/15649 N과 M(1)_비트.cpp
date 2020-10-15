#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n, m;
void go(int status, int cnt) { //순열
	if (cnt == m) {
		for (auto a : v) cout << a << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!(status & (1 << i))) { //방문이 0이면
			status |= (1 << i); //1로
			v.push_back(i + 1);
			go(status, cnt + 1);
			v.pop_back();
			status &= ~(1 << i); //0으로
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	go(0, 0);
}
