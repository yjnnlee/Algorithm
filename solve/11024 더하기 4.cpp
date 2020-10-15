#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	cin.ignore(); //cin의 입력버퍼에 \n을 비운다
	while (n--) {
		string s;
		getline(cin, s);
		int sum = 0;
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			tmp += s[i];
			if (s[i] == ' ' || i == s.size() - 1) {
				sum += stoi(tmp);
				tmp = "";
			}
		}
		cout << sum << "\n";
	}
}
