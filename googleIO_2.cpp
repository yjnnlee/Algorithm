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
		vector<string> res;
		int q;
		cin >> q;
		vector<int> v;
		for (int i = 0; i < q; i++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		string s = "A";
		for (int i = 0; i < v.size(); i++) {
			string tmp = "";
			if ((i+1) % 2 == 1) {
				char now = 'B';
				for (int j = 0; j < v[i]; j++) {
					tmp += now;
					now++;
				}
				if (i+1 < v.size() && v[i + 1] > v[i]) {
					tmp.pop_back();
					tmp += v[i + 1] + 'A';
				}
			}
			//else if ((i + 1) % 2 == 1) {
			//	char now = 'A';
			//	for (int j = 0; j < v[i]; j++) {
			//		tmp += now;
			//		now++;
			//	}
			//	if (i +1< v.size() && v[i + 1] > v[i]) {
			//		tmp.pop_back();
			//		tmp += v[i + 1] + 'A';
			//	}
			//}
			else {
				char now = 'A';
				for (int j = 0; j < v[i]; j++) {
					tmp += now;
					now++;
				}
				reverse(tmp.begin(), tmp.end());
			}
			s += tmp;
		}

		cout << "Case #" << k << ": " << s << "\n";
	}
}
