#include <iostream>
#include <string>
using namespace std;
int n, res = 99;
string tmp;
int main() {
	cin >> n;
	if (n <= 99) res = n; //99까지는 다 한수
	else {
		for (int i = 100; i <= n; i++) {
			tmp = to_string(i);
			if (abs((tmp[2] - '0') - (tmp[1] - '0')) ==
				abs((tmp[1] - '0') - (tmp[0] - '0'))) { //등차수열
				if ((tmp[0] == tmp[1] && tmp[0] != tmp[2]) || //두 수만 같다면 아님 101같은 거
					(tmp[0] == tmp[2] && tmp[0] != tmp[1]) ||
					(tmp[1] == tmp[2] && tmp[0] != tmp[1])) {
					continue;
				}
				res++;
			}
		}
	}
	cout << res;
}

/*
https://www.acmicpc.net/board/view/22414

99까지의 한수는 총 99개
1000까지의 한수는 총 144개
*/
