#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string a, b, res;
	cin >> a>>b;
	int sum = 0;

	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) sum += a.back() - '0', a.pop_back();
		if (!b.empty()) sum += b.back() - '0', b.pop_back();
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	cout << res;
}
