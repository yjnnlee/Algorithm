#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b, c, res = 0;

struct F {
	vector<int> parent, rank;
	F(int n) :parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (parent[u] == u) return u;
		else return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(rank[u], rank[v]);
		if (rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
	}
};
int main() {
	scanf("%d%d", &a, &b);
	F f(a * 2);
	for (int i = 0; i < b; i++) {
		scanf("%d", &c);
		if (!f.find(c)) break; //게이트를 모두 사용 중
		else {
			f.parent[f.find(c)] = f.find(c) - 1;
			res++;
		}
	}
	printf("%d", res);
}
