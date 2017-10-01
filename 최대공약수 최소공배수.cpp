#include <iostream>
using namespace std;
int a, b, res = 0, max;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	gcd(b, a%b);
}//최대공약수

int lcm(int a, int b) {
	return (a*b) / gcd(a, b);
}//최소공배수

int main() {
	cin >> a >> b;

	cout << gcd(a, b);
}
