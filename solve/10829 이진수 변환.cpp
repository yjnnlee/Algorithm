#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n;
	cin >> n;
	string s;
	while (n > 1) {
		if (n % 2) s += '1';
		else s += '0';
		n /= 2;
	}
	s += '1';
	reverse(s.begin(), s.end());
	cout << s;
}
