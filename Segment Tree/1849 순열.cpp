#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int init(vector<int>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = 1;
	}
	else {
		return tree[node] = init(tree, node * 2, start, (start + end) / 2) + init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

//노드 구간 start~end, 찾는 값 k
int findk(vector<int>& tree, int node, int start, int end, int k) {
	if (start == end) return start;
	else {
		if (k <= tree[node * 2]) {
			return findk(tree, node * 2, start, (start + end) / 2, k);
		}
		else return findk(tree, node * 2 + 1, (start + end) / 2 + 1, end, k-tree[node*2]);
	}
}

void update(vector<int>& tree, int node, int start, int end, int index, int diff) {
	if (index<start || index>end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>a(n + 1);
	vector<int>res(n + 1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);

	init(tree, 1, 1, n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int num = findk(tree, 1, 1, n, a[i] + 1);
		res[num] = i;
		update(tree, 1, 1, n, num, -1);
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i]<<'\n';
	}
}
