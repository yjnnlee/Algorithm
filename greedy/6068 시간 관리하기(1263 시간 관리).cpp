#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
struct A {
	int t, s;
};
vector<A> a;
bool cmp(const A& T, const A& S) {
	if (T.s == S.s) return T.t > S.t;
	else return T.s > S.s;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a.push_back({ x, y });
	}
	sort(a.begin(), a.end(), cmp); //끝나는 시간s 기준 내림차순
	int res = a[0].s - a[1].t; //일 시작 시간
	for (int i = 1; i < n; i++) {
		if (a[i].s > res) { //어떤 일을 끝내야 하는 시간이, 현재 일 시작 시간보다 뒤라면
			a[i].s = res; //어떤 일을 끝내야 하는 시간은 현재 일 시작 시간이다
			//5 20은 15에는 시작해야 하니까 1 16은 1 15내로 해야 한다는 의미이다
		}
		res = a[i].s - a[i].t; //1 16은 14에는 시작해야 하게 된다
	}
	if (res < 0) cout << -1;
	else cout << res;
}
