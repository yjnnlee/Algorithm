#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, m;;
	cin >> n >> m;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	long long l = 1, r = *max_element(v.begin(), v.end()) * m, res = r;
	//입력이 1 10^9 와 10^9 로 주어지면 right값은 10^18이어야 한다
	//res도 마찬가지라서 1e9로 하면 다른 값이 나오는 테케가 있음
	long long total = 0;
	while(l <= r) {
		long long mid = l + r >> 1, total = 0;
		//전체 시간 X동안 1명당 시간 Y가 걸리는 심사관은 총 X//Y 명 처리 가능
		for (int i = 0; i < n; i++) total += mid / v[i]; //mid=정답을 가정한 시간X, 각 심사관이 처리 가능한 사람 수 합계
		if (total < m) {
			l = mid + 1;
		}
		else {
			if (res > mid) res = mid;
			r = mid - 1;
		}
	}
	cout << res;
}3079
