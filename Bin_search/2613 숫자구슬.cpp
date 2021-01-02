#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, m;;
	cin >> n >> m;
	vector<int>v(n);
	int totallen = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		totallen += v[i];
	}
	long long l = totallen/m, r = totallen, res = r; //상한값: 그룹 안에 구슬 전체 합
	long long total = 0;
	vector<int>marblecnt(m + 1), final_res(m + 1);
	while(l <= r) {
		long long mid = l + r >> 1, total = 0;
		for (int i = 0; i < n; i++) { //구슬 합이 mid랑 비슷하게 구슬 넣기
			int tmp = v[i];
			total++;
			if (mid < tmp) {
				total = m + 1;
			}
			if (m < total) break;
			while (i + 1 < n - m + total && tmp + v[i + 1] <= mid) {
				tmp += v[++i];
			}
			marblecnt[total] = i + 1;
		}
		if (m == total) { //m개의 그룹이 만들어졌을 때만 최종 정답이다
			r = mid - 1;
			res = mid;
			for (int i = 1; i <= m; i++) final_res[i] = marblecnt[i];
		}
		else {
			l = mid + 1;
		}
	}
	cout << res << "\n";
	final_res[0] = 0;
	for (int i = 1; i <= m; i++) cout << final_res[i] - final_res[i - 1] << " ";
}
