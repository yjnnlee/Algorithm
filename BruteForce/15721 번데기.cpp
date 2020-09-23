#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, t, want, n = 0, cnt = 0, res = 0;
	cin >> a >> t >> want;
	while (true) {
		n++;
		vector<int> what{ 0,1,0,1 }; //0뻔 1데기
		for (int i = 1; i <= n + 1; i++) what.push_back(0);
		for (int i = 1; i <= n + 1; i++) what.push_back(1);
		for (int i = 0; i < what.size(); i++) {
			if (what[i] == want) cnt++;
			if (cnt == t) {
				cout << res;
				return 0;
			}
			res++;
			res %= a;
		}
		what.clear();
	}
}
