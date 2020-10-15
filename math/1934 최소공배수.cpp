#include <iostream>
using namespace std;
int t, a, b;
int gcd(int a, int b) { //그냥 재귀 돌리면 0%0인 경우가 있는 것 같음;;
	while (b > 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}
}
