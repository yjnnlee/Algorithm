#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	int len = s.length();
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] >= 65 && s[i] <= 67) res += 3;
		else if (s[i] >= 68 && s[i] <= 70) res += 4;
		else if (s[i] >= 71 && s[i] <= 73) res += 5;
		else if (s[i] >= 74 && s[i] <= 76) res += 6;
		else if (s[i] >= 77 && s[i] <= 79) res += 7;
		else if (s[i] >= 80 && s[i] <= 83) res += 8;
		else if (s[i] >= 84 && s[i] <= 86) res += 9;
		else if (s[i] >= 87 && s[i] <= 90) res += 10;
		else res += 11;
	}
	cout << res;
}
