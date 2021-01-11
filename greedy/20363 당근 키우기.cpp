#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, y;
	cin >> x >> y;
	int res = 0;
	if (x > y) {
		res += x;
		res += y;
		res += y / 10;
	}
	else {
		res += y;
		res += x;
		res += x / 10;
	}
	cout << res;
}
