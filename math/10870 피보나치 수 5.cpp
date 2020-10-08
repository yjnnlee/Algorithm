#include <iostream>
using namespace std;
int fibo[25] = { 0,1,1 };
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 2; i <= 20; i++) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}
	cout << fibo[n];
}
