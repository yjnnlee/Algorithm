#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int t;

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int k = 1; k <= t; k++) {
		int get = 1;
		string s;
		cin >> s;
		char now = 'I';
		char win = 'I';
		while (1) {
			if (s.size() == 0) {
				if (now == 'O') win = 'I';
				else win = 'O';
				break;
			}
			if (now == 'I') {
				if (s.size() == 1) {
					if (s[0] == 'I') {
						win = 'I';
					}
					else {
						win = 'O';
						get++;
					}
					break;
				}

				if (s[0] != 'I' && s[s.size() - 1] != 'I') {
					win = 'O';
					break;
				}

				if (s[0] == 'I' && s[1] == 'I') {
					string tmp = "";
					for (int i = 1; i < s.size(); i++) tmp += s[i];
					s = tmp;
				}
				else if (s[s.size() - 1] == 'I' && s[s.size() - 2] == 'I') {
					s.pop_back();
				}
				else {
					int tmp1 = 0, tmp2 = 0;
					if (s.size() % 2 == 0) {
						for (int i = 0; i < s.size() / 2; i++) {
							if (s[i] == 'I') tmp1++;
						}
						for (int i = s.size() / 2; i < s.size(); i++) {
							if (s[i] == 'I') tmp2++;
						}
					}
					else {
						for (int i = 0; i <= s.size() / 2; i++) {
							if (s[i] == 'I') tmp1++;
						}
						for (int i = s.size() / 2 + 1; i < s.size(); i++) {
							if (s[i] == 'I') tmp2++;
						}
					}

					if (tmp1 >= tmp2) {
						if (s[0] == 'I') {
							string tmp = "";
							for (int i = 1; i < s.size(); i++) tmp += s[i];
							s = tmp;
						}
						else if (s[s.size() - 1] == 'I') {
							s.pop_back();
						}
					}
					else {
						if (s[s.size() - 1] == 'I') {
							s.pop_back();
						}
						else if (s[0] == 'I') {
							string tmp = "";
							for (int i = 1; i < s.size(); i++) tmp += s[i];
							s = tmp;
						}
					}
				}
				now = 'O';
			}
			else {
				if (s.size() == 1) {
					if (s[0] == 'O') {
						win = 'O';
					}
					else {
						win = 'I';
						get++;
					}
					break;
				}
				if (s[0] != 'O' && s[s.size() - 1] != 'O') {
					win = 'I';
					break;
				}

				if (s[0] == 'O' && s[1] == 'O') {
					string tmp = "";
					for (int i = 1; i < s.size(); i++) tmp += s[i];
					s = tmp;
				}
				else if (s[s.size() - 1] == 'O' && s[s.size() - 2] == 'O') {
					s.pop_back();
				}
				else {
					int tmp1 = 0, tmp2 = 0;
					if (s.size() % 2 == 0) {
						for (int i = 0; i < s.size() / 2; i++) {
							if (s[i] == 'O') tmp1++;
						}
						for (int i = s.size() / 2; i < s.size(); i++) {
							if (s[i] == 'O') tmp2++;
						}
					}
					else {
						for (int i = 0; i <= s.size() / 2; i++) {
							if (s[i] == 'O') tmp1++;
						}
						for (int i = s.size() / 2 + 1; i < s.size(); i++) {
							if (s[i] == 'O') tmp2++;
						}
					}
					if (tmp1 >= tmp2) {
						if (s[0] == 'O') {
							string tmp = "";
							for (int i = 1; i < s.size(); i++) tmp += s[i];
							s = tmp;
						}
						else if (s[s.size() - 1] == 'O') {
							s.pop_back();
						}
					}
					else {
						if (s[s.size() - 1] == 'O') {
							s.pop_back();
						}
						else if (s[0] == 'O') {
							string tmp = "";
							for (int i = 1; i < s.size(); i++) tmp += s[i];
							s = tmp;
						}
					}
				}
				now = 'I';
			}
		}
		if (s.size() != 0 && s.size() != 1) {
			get += s.size();
		}
		cout << "Case #" << k << ": " << win << " " << get << "\n";
	}
}

//4
