#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
struct b {
	int p, d;
};
vector<b> a;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int maxd = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a.push_back({ x, y });
		if (maxd < y) maxd = y;
	}

	sort(a.begin(), a.end(), [](b u, b d) {
		return u.d > d.d; //d값 내림차순 정렬
	});
	//cout << maxd << " ";
	//for (int i = 0; i < n; i++) {
	//	cout << a[i].d << " ";
	//}
	int k = 0;
	priority_queue<int> q;
	long long res = 0;
	for (int i = maxd; i >= 1; i--) {
		while (k < n && a[k].d == i) { //i일까지 할 수 있는 강연 후보들 선발(i일 가능 강연을 누적)
			q.push(a[k].p);
			k++;
		}
		if (!q.empty()) { //i일에 할 강연을 선택
			res += q.top(); //가장 강연료가 높은 강연 선택
			q.pop();
		}
	}
	cout << res;
}
