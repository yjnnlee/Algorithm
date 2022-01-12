#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, p; cin >> n >> p;
	long long res = 1;
	for (int i = 1; i <= n; i++) {
		res = (res * i )% p;
	}
	cout << res;
}
