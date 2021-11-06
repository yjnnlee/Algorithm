#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool broken[10];

int possible(int c) { //그 숫자로 이동할 수 있는지?
	if (c == 0) { //0번 채널 예외
		if (broken[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (c > 0) {
		if (broken[c % 10]) return 0; //고장났으면 못감

		len += 1;
		c /= 10; //뒤에서부터 한 자리씩 끊어보며 고장난 버튼인지 확인
	}
	return len; //누를 수 있으면 c의 숫자 자체의 길이 반환
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	int n;
	cin >> n;
	int m;
	cin >> m;

	for (int i = 0;i < m;i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	int res = n - 100; //시작은 100번 채널이므로, 100빼면 암것도 안 누른 상태
	if (res < 0) res = -res; //음수면 양수로

	for (int i = 0;i <= 1000000;i++) {
		int c = i;
		int len = possible(c); //고장나서 못누르면 0, 
		//누를 수 있으면, 100에서 채널 c로 가는데 누른 숫자의 길이(len)
		//여기서부터는 +/-버튼으로 n까지 이동해야 함

		if (len > 0) { //머라도 누를 수 있다면
			int press = c - n; //n과 c의 차이를 구하면 +/-버튼 눌러야 하는 횟수
			if (press < 0) press = -press;

			if (res > len + press) res = len + press; //숫자 버튼 누른 횟수+플마버튼 누른 횟수
		}
	}
	cout << res;
}
