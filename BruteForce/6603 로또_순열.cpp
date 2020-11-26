#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while (1) {
		cin >> n;
		vector<int> a(n), d;
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n - 6; i++) d.push_back(0); //n개 중에 6개를 뽑는 모든 경우의 수는
		for (int i = 0; i < 6; i++) d.push_back(1); //1이 6개, 0이 n-6개인 모든 순열과 같다
		//이 때 0넣고 1넣는 부분 순서가 바뀌면 안 된다.. 0부터 넣어야 한다 어차피 섞일텐데 왜인진 모르겠다
		vector<vector<int>> res;
		//for (auto& x : d) cout << x << ' ';
		do {
			vector<int> now;
			for (int i = 0; i < n; i++) {
				if (d[i] == 1) now.push_back(a[i]);
			}
			res.push_back(now); //왜 굳이 이렇게 하냐면 테케 사이에 줄 하나 띄어야 해서
		} while (next_permutation(d.begin(), d.end()));

		sort(res.begin(), res.end());
		for (auto& x : res) {
			for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}
