#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
/*
* 설명: https://foxtrotin.tistory.com/547
*/
int main() {
	ios_base::sync_with_stdio(false); cin.tie();
	cin >> n;
	long long res = 0;
	for (int i = 1;i <= n;i++) {
		res += (n / i) * i;
	}
	cout << res;
}
