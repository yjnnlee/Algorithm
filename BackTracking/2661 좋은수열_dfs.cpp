#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;

/*
1,2,3 중에 하나씩 고르면서 좋은 수열인지 판별->백트래킹 문제
종료조건: 좋은 순열 찾음, 나쁜 순열, 순열의 길이가 n일 경우


*/
bool chk(string s) {
	int len = s.length();
	int end = len - 1; //뒤에서부터 비교(뒤=변동 많은 부분)
	for (int i = 1;i <= len/2;i++) {
		string a = s.substr(end - i, i); //end-i에서 i개 자름
		string b = s.substr(end, i); //end에서 i개 자름
		cout << a << " " << b << endl;
		if (a.compare(b) == 0) return false; //같으면 나쁜 수열
		end--;
	}
	return true; //좋은 수열
}
bool finish = false;
void go(int len, string s) {
	if (finish) return;
	if (!chk(s)) return; //종료조건2: 나쁜 순열이면 바로 종료

	//종료조건1: 제일 빨리 찾은 좋은 수열은 길이가 n이다
	//종료조건3: 나쁜 순열이라도 n이면 무조건 종료
 	if (len == n) { 	
		finish = true; //이후 모든 백트래킹 종료
		cout << s;
		return;
	}

	go(len + 1, s + "1");
	go(len + 1, s + "2");
	go(len + 1, s + "3");
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie();
	cin >> n;
	go(1, "1");
}
