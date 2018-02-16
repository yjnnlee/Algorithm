#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a,b,c;
int drawer[300005];

struct F {
	vector<int> parent, rank;
	F(int n) :parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int len(int a) {
		a = find(a);
		return rank[a];
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
	F f(m * 2);
	for (int i = 0; i < n; i++) {
		bool res = false;
		scanf("%d%d", &a, &b);
		if (f.find(a) == a) {
			f.merge(a, b);
			res = true;
		}
		else if(f.find(b) == b){
			f.merge(a, b);
			res = true;
		}
		//f.merge(a, b);
		//if (f.len(a) + f.len(b) - 1 < 0) {
		//	printf("SMECE\n");
		//}
		//else {
		//	f.len(a) += f.len(b) - 1;
		//	printf("LADICA\n");
		//}
		if (res) printf("LADICA\n");
		else printf("SMECE\n");
	}
}

