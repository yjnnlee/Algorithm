#include <iostream>
#include <algorithm>
using namespace std;

int n, p[1001], sum = 0, res = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		sum += p[i];
		res += sum;
	}
	cout << res;
}
