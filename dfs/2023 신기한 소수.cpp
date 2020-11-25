//2,3,5,7
//1,3,7,9
//1,3,9
//1,3,7,9
#include <iostream>
using namespace std;
bool isprime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
void dfs(int num, int n) {
	if (n == 0) cout << num << '\n';
	for (int i = 1; i <= 9; i += 2) { //짝수면 나눠지므로 홀수만
		if (isprime(num * 10 + i)) dfs(num * 10 + i, n - 1); //현재수+다음수가 소수면 그 다음자리 확인
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int first[4] = { 2,3,5,7 }; //맨 앞자리는 무조건 한자리 소수
	for (int i = 0; i < 4; i++) {
		dfs(first[i], n - 1);
	}
}
