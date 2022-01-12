#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> //이거 없으면 백준에선 컴파일 에러
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n; cin >> n;
	
	long long s = 0, e = sqrt(n), mid = 0;
	while (s <= e) {
		mid = (s + e) / 2;
		if (mid >= sqrt(n)) e = mid - 1;
		else s = mid + 1;
	}
	if (mid * mid == n) cout << mid;
	else cout << mid + 1;
}
