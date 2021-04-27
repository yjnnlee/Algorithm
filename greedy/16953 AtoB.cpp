#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long a, b;
	cin >> a >> b;
	long long cnt = 0;
	while (b >= a) {
		if (a == b) {
			cout << cnt + 1; return 0;
		}
		if (b % 2 == 0) b /= 2;
		else if (b % 10 == 1)b /= 10; //이렇게 조건 안 걸어주면 중간에 틀림
		else {
			cout << -1; //이렇게 b>a가 아님에도 중간에 -1 포인트 있어야 함
			return 0;
		}
		cnt++;
	}
	cout << -1;
}
