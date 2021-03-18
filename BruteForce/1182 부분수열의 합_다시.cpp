#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int res = 0;
int n, s;
vector<int> v;
void go(int now, int sum) {
	if (now >= n) return; //범위 초과
	if (sum + v[now] == s) res++; //(현재 수를 더해서)찾음
	go(now + 1, sum + v[now]); //현재 수를 더하는 경우
	go(now + 1, sum); //현재 수를 더하지 않는 경우
}

int main() {
	cin >> n >> s;
	v.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	go(0, 0);
	cout << res;
}
