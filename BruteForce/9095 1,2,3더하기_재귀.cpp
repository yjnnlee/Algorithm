#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int go(int cnt, int sum, int goal) {
	if (sum > goal) return 0; //불가능한 경우
	if (sum == goal) return 1; //정답을 찾은 경우
	int now = 0;
	now += go(cnt + 1, sum + 1, goal);
	now += go(cnt + 1, sum + 2, goal);
	now += go(cnt + 1, sum + 3, goal);
	return now;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n), d;
	for (int i = 0, tmp; i < n; i++) {
		cin >> tmp;
		cout << go(0, 0, tmp)<<'\n';
	}
}
