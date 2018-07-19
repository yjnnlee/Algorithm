#include <stdio.h>
#include <vector>
using namespace std;

int n, m, k, what, q, w;
vector<long long> a(n + 1);
vector<long long> tree;

long long sum(vector<long long> &tree, int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
void update(vector<long long> &tree, int i, int num) {
	while (i < tree.size()) {
		tree[i] += num;
		i += (i & -i);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}

	for (int i = 1; i <= k + m; i++) {
		scanf("%d", &what);
		if (what == 1) {
			scanf("%d %d", &q, &w);
			update(a, i, )
		}
	}
}