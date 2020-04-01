#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
long long int tree[4000001], arr[1000001];

long long sum(int L, int R, int nodeNum, int nodeL, int nodeR) { //s~e까지 부분합ㅜ
	if (R < nodeL || nodeR < L) return 0; //겹치는 구간이 없으면 0 리턴
	if (L <= nodeL && nodeR <= R) return tree[nodeNum]; //완전히 포함하면 자신의 값 리턴
	int mid = (nodeL + nodeR) / 2;
	return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

void update(int node, int s, int e, int index, int val) { //i번째 원소를 val로 갱신
	if (index < s || index > e) return; //[start, end]에 index가 포함되지 않는 경우
	tree[node] += val;

	int mid = (s + e) / 2;
	if (s != e) { //포함되는 경우 val만큼 증가시켜 합을 변경
		update(node * 2, s, mid, index, val);
		update(node * 2 + 1, mid + 1, e, index, val);
	}
}

long long makeTree(int node, int s, int e) {
	if (s == e) { //node가 리프 노드인 경우
		return tree[node] = arr[s];
	}
	else {
		int mid = (s + e) / 2;
		return tree[node] = makeTree(node * 2, s, mid) + makeTree(node * 2 + 1, mid + 1, e);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	makeTree(1, 1, n);

	for (int i = 0, a, b, c; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			int val = c - arr[b];
			arr[b] = c;
			update(1, 1, n, b, val);
		}
		if (a == 2) cout << sum(b, c, 1, 1, n) << '\n';
	}
}
