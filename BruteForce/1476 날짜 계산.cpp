#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int e, s, m;
	cin >> e >> s >> m;
	e--, s--, m--;
	for (int i = 0;; i++) {
		if (i % 15 == e && i % 28 == s && i % 19 == m) {
			cout << i + 1 << '\n';
			break;
		}
	}
}
