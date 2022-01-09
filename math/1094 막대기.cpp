#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, m;

/*
문제가 잘 이해가 안 되는데..
64, 32, 16, 8, 4, 2, 1, 1을 가지고 X를 만든다는 이야기 같다
*/

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x;
	cin >> x;
	int num[] = { 64, 32, 16, 8, 4, 2, 1, 1 };
	int sum = 0, res = 0;

	for (int i = 0;i < 8;i++) {
		if (sum + num[i] <= x) {
			sum += num[i];
			res++;
		}
	}
	if (sum == x) {
		cout << res;		
	}
}
