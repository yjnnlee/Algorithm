#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

void init(vector<int>& tree, vector<int>& num, int node, int start, int end) {
	if (start == end) { //리프 노드인 경우
		tree[node] = num[start]; //그 배열의 원소를 가진다
		return;
	}
	//왼쪽 오른쪽 나눠서 내려간다
	init(tree, num, node * 2, start, (start + end) / 2);
	init(tree, num, node * 2 + 1, (start + end) / 2 + 1, end);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int sum(vector<int> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1; //완전히 겹치지 않음, 곱이니까 1
	if (left <= start && right >= end) return tree[node]; //완전히 겹침
	return sum(tree, node * 2, start, (start + end) / 2, left, right) * sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<int> &tree, int node, int start, int end, int index, int value) {
	if (index < start || index > end) return; //범위 밖은 패스
	if (start == end) { //리프 노드인 경우 자기 자신만 업데이트
		tree[node] = value;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index, value);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k;
	while (cin >> n >> k) {
		vector<int> num(n);

		for (int i = 0; i < n; i++) {
			cin >> num[i];
			if (num[i] > 0) num[i] = 1;
			if (num[i] < 0) num[i] = -1;
		}

		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));
		vector<int> tree(tree_size);
		init(tree, num, 1, 0, n - 1); //1로 채워진 세그트리

		char what;
		int x, y;
		while (k--) {
			cin >> what >> x >> y; //index, value
			if (what == 'C') {
				if (y > 0) y = 1;
				if (y < 0) y = -1;
				update(tree, 1, 0, n - 1, x - 1, y);
			}
			else { //start, end
				int res = sum(tree, 1, 0, n - 1, x - 1, y - 1);
				if (res > 0) cout << '+';
				else if (res < 0) cout << '-';
				else cout << '0';
			}
		}
		cout << '\n';
	}
	return 0;
}
