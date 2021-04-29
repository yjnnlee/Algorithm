#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
struct INFO {
	long long gcd, s, t;
};
INFO euc(long long a, long long b) { //확장 유클리드
	if (b == 0) {
		INFO res = { a,1,0 };
		return res;
	}
	INFO res = euc(b, a % b);
	INFO resres = { res.gcd, res.t, res.s - (a / b) * res.t };
	return resres;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long n, a;
	cin >> n >> a;

	cout << n - a << " ";
	INFO num = euc(n ,a);
	if (num.gcd == 1) cout << (num.t + n) % n;
	else cout << -1;

}
