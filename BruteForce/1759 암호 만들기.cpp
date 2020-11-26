#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool chk(string pw) {
	int ja = 0, mo = 0;
	for (char x : pw) {
		if (x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o') mo += 1;
		else ja += 1;
	}
	return ja >= 2 && mo >= 1;
}

//만들어야 하는 암호 길이, 사용할 수 있는 알파벳, 현재까지 만든 암호, 사용할지 말지 결정하는 알파벳 인덱스
void go(int n, vector<char>& alpha, string pw, int i) {
	if (pw.length() == n) { //정답을 찾은 경우
		if (chk(pw)) cout << pw << '\n';
		return;
	}
	if (alpha.size() <= i) return;//불가능한 경우
	go(n, alpha, pw + alpha[i], i + 1); //i번째 알파벳 사용
	go(n, alpha, pw, i + 1); //i번째 알파벳 사용하지 않음
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<char> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end()); //정렬을 미리 하고 시작하면 자연스럽게 정렬됨
	go(n, a, "", 0);
}
