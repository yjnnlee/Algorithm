#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
경우1: 100부터 시작해서 완전 +,-하나씩만 눌러서 가는 경우
경우2: 버튼과 +,-를 눌러서 가는 경우
셋 중 적은 수를 출력한다

주의: 테스트 케이스는 500000이지만 채널은 500000이상 갔다가 돌아오는 경우가 있을 수 있음
반례
10
9
1 2 3 4 5 6 7 8 9
11
0번 채널로 가서 +10하면 11번에 가능하다
*/

int n, m;
int v[] = { 0,1,2,3,4,5,6,7,8,9 };

int go_remote(int now) {
	int ch = 0;
	if (now == 0) { //채널0이면 0번으로만 갈 수 있음
		if (v[0] == -1) return 0; //0번 고장남->불가능
		else return 1;
	}
	while (now > 0) {
		if (v[now % 10] == -1) return 0; //맨 뒷자리 수의 버튼 고장남->불가능
		else {
			now /= 10; ch++; //누를 수 있음->버튼 누르는 횟수 증가 후 다음 자리 봄
		}
	}
	return ch;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		v[tmp] = -1;
	}
	int res = abs(n - 100); //경우1: 완전 +, -로만 가는 경우
	for (int i = 0; i <= 999999; i++) { //주의: 채널이 최대 채널을 넘었다 돌아올 수 있음(넉넉하게 잡음)
		int go = go_remote(i); //i번째 수를 버튼만 눌러서 갈 수 있음?
		int res2 = 999999; //경우2: 버튼과 +,-를 눌러서 가는 경우(+버튼만도 포함)
		if (go) res2 = go + abs(n - i); //버튼 누르는 횟수+가려는 채널과의 차이(+,-누르는 횟수)
		res = min(res, res2);
	}
	cout << res;
}
