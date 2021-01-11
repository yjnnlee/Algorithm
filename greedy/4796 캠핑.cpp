#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i = 1;
	while (1) {
		int p, l, v;
		cin >> l >> p >> v;
		if (p + l + v == 0) return 0;

		int res = 0;
		res += (v / p) * l;

		if (v % p > l) res += l; //남은 날이 L일이 넘으면 L일만큼만 사용 가능하다
		else res += v % p;

		cout << "Case " << i << ": " << res << "\n";
		i++;
	}
}
