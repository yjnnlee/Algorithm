#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int num1, num2;
	string b;
	cin >> num1 >> num2;
	b = to_string(num2);

	cout << num1 * (b.back() - '0') << '\n', b.pop_back();
	cout << num1 * (b.back() - '0') << '\n', b.pop_back();
	cout << num1 * (b.back() - '0') << '\n';
	cout << num1 * num2;
}
