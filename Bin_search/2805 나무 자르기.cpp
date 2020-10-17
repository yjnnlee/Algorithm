#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, m;
	cin >> n >> m;
	vector<int>tree(n);
	for (int i = 0; i < n; i++) cin >> tree[i];
	long long l = 0, r = *max_element(tree.begin(), tree.end()), res = 0;

	while(l <= r) {
		long long mid = l + r >> 1, sum = 0;
		for (int i = 0; i < n; i++) { //나무를 m만큼 잘라서 나오는 나무의 길이를 더함
			if (mid < tree[i]) sum += tree[i] - mid;
		}
		if (sum >= m) { //잘린 나무의 합이 필요한 값보다 크면
			res = max(res, mid); //최대 높이 갱신
			l = mid + 1; //높이를 높혀서 덜 자른다
		}
		else r = mid - 1; //필요한 값보다 작으면 높이를 낮춰서 더 자른다
	}
	cout << res;
}
