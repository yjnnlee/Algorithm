#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	int n;
	cin >> n;
	cin.ignore(); //cin뒤에 버퍼에 남은 개행 문자 지움
	while (n--) {
		getline(cin, s); //마지막 NULL입력 안 받음(문자열의 끝은NULL)
		s += '\n'; //문자열의 끝을 개행으로 바꿔줌
		stack<char> a;
		for (char c : s) {
			if (c == ' ' || c=='\n') {
				while (!a.empty()) {
					cout << a.top();
					a.pop();
				}
				cout << " ";
			}
			else {
				a.push(c);
			}
		}
		
	}
}
