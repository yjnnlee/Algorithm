#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
	if (b <= 0) return a;
	return gcd(b, a % b);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long a, b;
	cin >> a >> b;
	long long res;
	if (a > b) res = gcd(a, b);
	else res = gcd(b, a);
	for (long long i = 0; i < res; i++) cout << 1;
}
