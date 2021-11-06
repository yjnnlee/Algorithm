#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	int t; cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x -= 1; //나머지 연산을 사용하기 위해서 0기준으로 만든다
		y -= 1;
		bool ok = false;
		for (int k = x;k < (n * m);k += m) { //x(월)을 고정하고 월 주기인 m만큼씩 본다
			if (k % n == y) {
				cout << k + 1 << "\n"; //임의로 -1했으니까 +1해 줘야 한다
				ok = true;
				break;
			}
		}
		if (!ok) { //정답이 없음
			cout << -1 << "\n";
		}
	}
}
