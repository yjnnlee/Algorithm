#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n; cin >> n;

	long long sum = 0;
	int num = 1;
	int res = 0;
	
	while (sum <= n) {
		sum += num;
		res++;
		num++;
	}
	cout << res - 1; 

	//-1하는 이유. 합이 S를 넘기면 마지막 숫자를 뺀다
}
