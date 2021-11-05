#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
/*
A의 진짜 약수들은
중앙을 기준으로 대칭인 두 수를 곱하면 항상 A가 나온다
맨 앞, 맨 뒤 두 개만 구해서 곱하면 A를 구할 수 있다
*/
int main() {
	ios_base::sync_with_stdio(false); cin.tie();
	cin >> n;
	int res_2 = 0;
	int res_1 = 1e9;
	for (int i = 0;i < n;i++) {
		int tmp;
		cin >> tmp;
		if (tmp > res_2) res_2 = tmp;
		if (tmp < res_1) res_1 = tmp;
	}
	cout << res_2 * res_1;
}
