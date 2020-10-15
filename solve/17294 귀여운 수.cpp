#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> v;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string n;
	cin >> n;
	if (n.size() == 1) {
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
		return 0;
	}
	int c = n[1] - n[0];

	for (int i = 2; i < n.size(); i++) {
		if (c != n[i]-n[i-1]) {
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
			return 0;
		}
	}
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
}
