#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int t;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	if (t % 10) cout << -1;
	else {
		int a = t / 300;
		t %= 300;
		int b = t / 60;
		t %= 60;
		int c = t / 10;
		t %= 10;
		cout << a << " " << b << " " << c;
	}
}
