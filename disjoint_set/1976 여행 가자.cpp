#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a,b,c;

struct F {
	vector<int> parent, rank;
	F(int n) :parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return; //같은 트리
		if (rank[u] > rank[v]) swap(u, v);
		if (rank[u] == rank[v]) rank[v]++; //같은 높이면 1더함
		parent[u] = v; //자식으로 넣음
	}
};

int main() {
	scanf("%d%d", &n, &m);
	F f(n*2);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a);
			if (a) f.merge(i,j);
		}
	}
	scanf("%d", &a);
	a = f.find(a);

	for (int i = 1; i < m; i++) {
		scanf("%d", &b);
		if (a != f.find(b)) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}
