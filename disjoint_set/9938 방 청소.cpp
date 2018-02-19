#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b, c;
int drawer[300005];
bool res = false;
int parent[300005];

struct F {
//	vector<int> parent, rank;
	F(int n, int l){
		for (int i = 1; i <= l; i++) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if (u == parent[u]) return u; //루트 노드면 리턴
		return parent[u] = find(parent[u]); //아니면 루트를 찾으러
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		//if (u == v) return; //같은 트리면
		//if (rank[u] > rank[v]) swap(u, v);
		//if (rank[u] == rank[v]) rank[v]++; //같은 깊이면 깊이를 늘려준다
		parent[u] = v; //자식으로 넣음
		res = true;
		printf("LADICA\n");
	}
};

int main() {
	scanf("%d%d", &n, &m);
	F f(300005, m*2);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		if (!drawer[a]) {
			drawer[a] = true;
			f.merge(a, b);
		}
		else if (!drawer[b]) {
			drawer[b] = true;
			f.merge(b, a);
		}
		else if (!drawer[(f.find(a))]) {
			drawer[f.find(a)] = true;
			f.merge(a, b);
		}
		else if (!drawer[(f.find(b))]) {
			drawer[f.find(b)] = true;
			f.merge(b, a);
		}
		if (res) printf("LADICA\n");
		res = false;
	}
}
