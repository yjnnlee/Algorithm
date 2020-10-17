#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, totalsum = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) { cin >> v[i]; totalsum += v[i]; }
	long long l = 0, r = *max_element(v.begin(), v.end()), res = 0;
	long long totalhave;
	cin >> totalhave;

	while(l <= r) {
		long long mid = l + r >> 1, sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < v[i]) sum += mid; //상한액 이상이면 상한액만
			else sum += v[i]; //상한액 이하면 금액 전체
		}
		if (sum <= totalhave) { //상한액 기준 예산합이 전체 예산보다 작으면
			res = mid;
			l = mid + 1; //상한액을 높게 잡아서 더 잡는다
		}
		else {
			r = mid - 1; //예산보다 크면 상한액을 낮게 잡아서 덜 잡는다
		}
	}
	cout << res;
}
