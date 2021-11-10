#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
연산자 끼워넣기2
5*6 = 30 최대
5-6 = -1 최소
4C(n-1 길이)를 뽑는 모든 경우의 수를 돌아본다?
2 1 2 1 같은 경우는? -> 그 만큼 숫자를 채워 넣는다 (뽑기 확률 업)
2 1 2 1은 0 0 1 2 2 3이 되고, 아래 경우의 수가 전체
00 01 02 03 10 12 13 20 21 23 30 31 32

반례
2
1 3
0 1 0 1
답: 0, -2

제발 범위 확인
맨 앞의 n-1개만 뽑아도 정답이 되긴 하지만 -> 시간초과 난다
00, 00, 00, 00,...., 01, 01.. 이런 중복이 많이 발생하기 때문임
이런 중복 문제는, 10개의 연산자 중 첫번째 자리에 (+, -, * , /) 중 사용가능한 것 하나 넣어주고,
두번째 자리에 남은 (+, -, * / ) 중 사용가능한 것 하나 넣고.. 이렇게 해결

next_permutation으로는 구현할 수 없는 부분인 듯. 모든 순열에 해당되지 않음
재귀로..
*/
int n;
int maxx = -1e9, minn = 1e9;
void go(vector<int>& num, int plus, int minus, int multi, int div, int index, int sum) {
	if (index == n) { //필요 연산자의 개수는.. n개. 왜? n-1까지 계산하고 다시 들어와야 하니까..
		if (sum > maxx) maxx = sum;
		if (sum < minn) minn = sum;
		return;
	}

	// 연산자가 남아 있으면 재귀를 돌린다
	// 중요!! 연산 이전에 index를 먼저 +1해 주어야 한다. 왜? 맨 첫 숫자는 이미 sum에 들어가 있기 때문이다
	if (plus > 0) go(num, plus - 1, minus, multi, div, index + 1, sum + num[index]);
	if (minus > 0) go(num, plus, minus - 1, multi, div, index + 1, sum - num[index]);
	if (multi > 0) go(num, plus, minus, multi - 1, div, index + 1, sum * num[index]);
	if (div > 0) go(num, plus, minus, multi, div - 1, index + 1, sum / num[index]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	cin >> n;
	vector<int> num(n);
	for (int i = 0;i < n;i++) {
		cin >> num[i];
	}
	vector<int> cal(4);
	for (int i = 0;i < 4;i++) {
		cin >> cal[i];
	}

	go(num, cal[0], cal[1], cal[2], cal[3], 1, num[0]); //마지막->필요 연산자 개수
	
	cout << maxx << "\n" << minn;
}
