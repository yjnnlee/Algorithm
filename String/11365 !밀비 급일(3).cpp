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
		for (int i = a.length()-1; i >= 0; i--) cout << a[i];
		cout << '\n';
	}
}
