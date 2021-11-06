#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
수 이어 쓰기
N이 너무 크기 때문에 실제로 수를 만들 수는 없고, 자릿수를 센다
예: N=356
1~9까지는 1자릿수: +1 -> (9-1+1)[한자릿수의개수] * 1 [자릿수]
10~99까지는 2자릿수: +2 -> (99-10+1) [두자릿수의개수] * 2 [자릿수]
100~999까지는 3자릿수: +3 -> (356-100+1) * 3

100000000 9자리가 최대 N이니까 최대 9번 계산한다
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	int n;
	cin >> n;
	long long res = 0;
	//len: 자릿수 1,2,3.. , len=start-end임
	//start는 1, 10, 100.. 으로 커짐
	//자릿수는 1자리씩 증가하니까 +1
	//end는 다음start - 1
	for (int start = 1, len = 1;start <= n;start *= 10, len++) {
		int end = start * 10 - 1;
		if (end > n) end = n; //end가 n을 넘어가면 마지막 수는 n이 됨

		res += (long long)(end - start + 1) * len;
	}
	cout << res;

}
