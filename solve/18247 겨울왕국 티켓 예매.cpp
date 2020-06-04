#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (n<12 || m<4) cout << -1 << '\n';
		else cout << m * 11 + 4 << '\n'; 
	}
}
