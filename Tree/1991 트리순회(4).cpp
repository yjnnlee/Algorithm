#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
struct A {
	char left, right;
};
vector<A> v(100);

void go(int now, int what) {
	if (what == 1) cout << (char)now;
	if (v[now].left != '.') go(v[now].left, what);
	if (what == 2) cout << (char)now;
	if (v[now].right != '.') go(v[now].right, what);
	if (what == 3) cout << (char)now;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		v[a].left = b;
		v[a].right = c;
	}
	go('A', 1); cout << "\n"; //전
	go('A', 2); cout << "\n"; //중
	go('A', 3); cout << "\n"; //후
}
