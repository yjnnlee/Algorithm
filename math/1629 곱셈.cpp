#include <iostream>
using namespace std;

long long go(long long a, long long b, long long c) {
	//a^b는= a^(b/2) * a^(b/2)임을 이용한다
	//n이 홀수라면 a^(b/2) * a^(b/2) * a 로 a를 한 번 더 곱해주어야 알맞다

	if (b == 0) return 1; //0제곱
	long long tmp = go(a, b / 2, c);
	long long res = tmp * tmp % c;
	if (b % 2 == 1) return res * a % c; //b가 홀수면 a를 한 번 더 곱해서 값을 맞춤
	else {	//b가 짝수면 그냥 그대로 b의 승수를 줄임
		return res;
	}
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << go(a, b, c);
}
//분할정복이라고 하드라
