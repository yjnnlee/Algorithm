#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
(n m)은 n! / (n-m)!m!

0의 개수=2와 5의 개수를 센다

이전에 풀었던 이항 계수 문제에서
f(n-1, m-1) + f(n-1, m)
1 -> n==m or m==0
이런 점화식을 썼으니까, 이번에도 이걸 사용해서 구하면서
2,5를 계산하나.. 그렇게 접근했는데
답이 안 나와서 살짝 검색하니 아무도 이렇게 하지 않았다..

더 쉬운 방법이 있더라
n!과 (n-m)!와 m!의 2의 배수의 개수, 5의 배수의 개수를 구하고
분모와 분자에 둘 다 같은 수가 있으면 사라지므로
n!에서 나온 개수에서 (n-m)!과 m!에서 나온 개수를 빼주면 된다
이걸 2와 5에 대해서 한다
그리고 둘 중 더 작은 값이 정답
왜 min이냐면 10이 만들어져야 하는데 2나 5 중 한 쪽이 아무리 많더라도
적은 쪽 개수만큼밖에 못 만들기 때문이다

범위가 크므로 long long을 사용한다
*/
long long n, m;
long long div5(long long n) {
	long long cnt = 0;
	for (long long i = 5; i <= n; i *= 5) {
		cnt += n / i;
	}
	return cnt;
}

long long div2(long long n) {
	long long cnt = 0;
	for (long long i = 2; i <= n; i *= 2) {
		cnt += n / i;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	long long a = div5(n) - div5(n - m) - div5(m);
	long long b = div2(n) - div2(n - m) - div2(m);
	cout << min(a, b);
}
