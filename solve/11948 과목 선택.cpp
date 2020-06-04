#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c, d, e, f, sum = 0;
	cin >> a >> b >> c >> d >> e >> f;
	sum = a + b + c + d + e + f;
	sum -= min(a, min(b, min(c, d)));
	sum -= min(e, f);
	cout << sum;
}
