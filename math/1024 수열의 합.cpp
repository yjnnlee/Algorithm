#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n;
	int l, res = -1, index = 0;
	cin >> n >> l;
	for (int i = l; i <= 100; i++) { //100이하의 l중에 조건에 맞는 x를 찾는다
		int k = i * (i - 1) / 2;
		if ((n - k) % i == 0 && (n - k) / i >= 0) { //나눠 떨어지고, 길이가 맞으면 찾음
			res = (n - k) / i;
			index = i;
			break;
		}
	}
	if (res == -1) cout << -1;
	else for (int i = 0; i < index; i++) cout << res + i << " ";
}
