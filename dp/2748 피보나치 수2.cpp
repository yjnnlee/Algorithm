#include <iostream>
using namespace std;
int n, f[1000000] = { 0,1 };

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	cout << f[n - 1];
}
