#include <iostream>
using namespace std;
int main() {
	int a, b, c, sum = 0;
	cin >> a >> b >> c;
	a++;
	while (a--) {
		sum += b * a + a * a * c;
	}
	cout << sum;
}
