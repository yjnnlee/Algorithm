#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void update(vector<int> &tree, int i, int diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int sum(vector<int> &tree, int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int sum(vector<int>& tree, int l, int r) {
	if (l > r) return 0;
	return sum(tree, r) - sum(tree, l - 1);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n + 1);
	vector<int> tree(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] % 2 == 0) update(tree, i, 1); //짝수는 1이다
	}

	int m;
	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) { //홀짝 바뀔 때만 update할 것
			if (c % 2 == 1 && arr[b] % 2 == 0) update(tree, b, -1); //짝수->홀수(1->0)
			if (c % 2 == 0 && arr[b] % 2 == 1) update(tree, b, 1); //홀수->짝수(0->1)
			arr[b] = c;
		}
		else {
			int res = sum(tree, b, c); //짝수출력이면 그냥 합 출력
			if (a == 3) {
				res = (c - b + 1) - res; //홀수출력이면 구간전체개수-합 출력
			}
			cout << res << '\n';
		}
	}
	return 0;
}
