#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int a, b, c, d, sum = 0;
	cin >> a >> b >> c >> d;
	int x = b + c;
	int y = a + d;
	cout << min(x, y);

}
