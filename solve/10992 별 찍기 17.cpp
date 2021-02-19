#include <iostream>
#include <string>
using namespace std;
int main() {
	int x;
	cin >> x;
	for (int i = 0; i < x - 1; i++) cout << " ";
	cout << "*"<<"\n";
	if (x == 1) return 0;
	for (int i = 2; i < x; i++) {
		for (int j = 0; j < x - i; j++) cout << " ";
		cout << "*";
		for (int j = 0; j < 2*(i-1)-1; j++) cout << " ";
		cout << "*";
		cout << "\n";
	}
	for (int i = 0; i < x * 2 - 1; i++) cout << "*";
}
