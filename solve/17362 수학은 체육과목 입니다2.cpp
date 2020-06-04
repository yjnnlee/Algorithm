#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	n %= 8;
	if (n == 6) cout << '4';
	else if (n == 7) cout << '3';
	else if (n == 0) cout << '2';
	else cout << n;
}
