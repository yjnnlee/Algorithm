#include <iostream>
using namespace std;
int n, d[10000], a;

int main() {
	cin >> n;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int j = 1; j <= n; j++) {
		cin >> a;

		if (a > 3) {
			for (int i = 4; i <= a; i++) {
				if (d[i] != 0) continue;
				else d[i] += d[i - 1] + d[i - 2] + d[i - 3];
			}
		}
		cout << d[a] << '\n';
	}
}
