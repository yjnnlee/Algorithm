#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, m;

/*
2와 5를 곱할 때만 0이 생긴다
5보다 2가 많으니까 5만 세면 된다

근데 5의 배수가 예외
5*2=10
5*5*2*2=100
5*5*5*2^3=1000
2는 충분히 많다고 칠 수 있으므로(소인수분해 하면 2가 잔뜩나온다)
5의 배수는 1개씩 늘 때마다 0의 개수가 1개씩 증가되며 추가된다고 볼 수 있다
5^4=625는 문제 범위인 500을 넘으므로 패스
*/

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n >= 2) {
		if (n % 5 == 0) m++;
		if (n % 25 == 0) m++;
		if (n % 125 == 0) m++;
		n--;
	}
	cout << m;
}
