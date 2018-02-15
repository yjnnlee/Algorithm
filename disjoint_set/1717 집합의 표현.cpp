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
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0) f.merge(b, c);
		else {
			b = f.find(b);
			c = f.find(c);
			if (b == c) printf("YES\n");
			else printf("NO\n");
		}
	}
}
