#include <iostream>
#include <string>
using namespace std;
//char a[505];
string a;
int main() {
//	cin.getline(a, 500);
	while (1) {
		getline(cin, a);
		if (a == "END") return 0;

		int len = a.length();
		for (int i = 0; i < len/2; i++) {
			char b;
			b = a[i];
			a[i] = a[len - i - 1];
			a[len - i - 1] = b;
		}
		for (int i = 0; i < len; i++) cout << a[i];
		cout << '\n';
	}
}
