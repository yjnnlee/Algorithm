#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int chk[100], res = 0;
void f(string s) {
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (chk[s[i] - 'a']) return;
		else {
			chk[s[i] - 'a'] = 1;
			char tmp = s[i];
			while (1) {
				if (s[++i] != tmp) {
					i--;
					break;
				}
			}
		}
	}
	res++;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		memset(chk, 0, sizeof(chk));
		string s;
		cin >> s;
		f(s);
	}
	cout << res;
}
