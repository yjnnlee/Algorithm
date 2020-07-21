#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 1000000;

int init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

//노드 구간 start~end, 찾는 값 k
int find(vector<int>& tree, vector<int>& a, int node, int start, int end, int k) {
	if (start == end) return start;
	else {
		if (k <= tree[node * 2]) {
			return find(tree, a, node * 2, start, (start + end) / 2, k);
		}
		else return find(tree, a, node * 2 + 1, (start + end) / 2 + 1, end, k-tree[node*2]);
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
	vector<int>a(MAX + 1);
	int h = (int)ceil(log2(MAX + 1));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	int n, what, b, c;
	cin >> n;
//	init(a, tree, 1, 0, n - 1);
	while (n--) {
		cin >> what;
		if (what == 1) {
			cin >> b;
			int candy = find(tree, a, 1, 1, MAX, b);
			cout << candy << '\n';
			a[candy]--;
			update(tree, 1, 1, MAX, candy, -1);
		}
		else {
			cin >> b >> c;
			a[b] += c;
			update(tree, 1, 1, MAX, b, c);
		}
	}
}
