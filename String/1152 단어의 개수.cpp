#include <iostream>
#include <string>
using namespace std;
string a;
int res = 0;

int main() {
	getline(cin, a);
	if (a.length() == 0) {
		cout << 0; 
		return 0;
	}

	for (int i = 0; i < a.length(); i++) {
		if (a.at(i) == ' ') {
			res++;
		}
	}
	if (a.at(0) == ' ') res--;
	if (a.at(a.length() - 1) == ' ') res--;

	cout << res + 1;
}
