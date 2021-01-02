#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int n;
struct A {
	int s, e;
};
vector<A> a;

bool cmp(const A& first, const A& second) {
	if (first.e == second.e) return first.s < second.s;
	else return first.e < second.e;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a.push_back({ x,y });
	}
	sort(a.begin(), a.end(), cmp);

	int last = 0, res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].s >= last) {
			last = a[i].e;
			res++;
		}
	}
	cout << res;
}
