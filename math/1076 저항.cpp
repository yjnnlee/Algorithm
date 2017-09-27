#include <iostream>
#include <string>
using namespace std;

string color[] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
string a, b, c;
long long int sum = 0;

int main() {
	cin >> a >> b >> c;

	for (int j = 0; j < 10; j++) {
		if (a == color[j]) {
			sum = j * 10;
		}
	}

	for (int j = 0; j < 10; j++) {
		if (b == color[j]) {
			sum += j;
		}
	}

	for (int j = 0; j < 10; j++) {
		if (c == color[j]) {
			for (int i = 0; i < j; i++) {
				sum *= 10;
			}
		}
	}
	cout << sum;
}
//black black white 0
//black blue while 600000000
//brown black brown 100

