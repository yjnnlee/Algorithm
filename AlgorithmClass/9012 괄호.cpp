#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int n, check = 0;
vector<int> res;
string tmp;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;

		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[j] == '(') {
				check++;
			}
			if (tmp[j] == ')') {
				check--;
			}
			if (check < 0) break;
		}

		if (check == 0) {
			res.push_back(1);
		}
		else {
			res.push_back(0);
		}
		check = 0;
	}

	for (int i = 0; i < n; i++) {
		if (res[i] == 1) {
			cout << "YES" << "\n";
		}
		else cout << "NO" << "\n";
	}
}