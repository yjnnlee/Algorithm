#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
vector<pair<string, string>> a;
vector<string> b;

int n, f;
char p[30], q[30];

/*
아래 struct는
for (int i = 0; i < n * 2; i++) {
	parent[i] = i;
	rank[i] = 1;
}
과 같은 의미임
*/

struct OptimizedDisjointSet { //트리
	vector<int> parent, rank;
	
	OptimizedDisjointSet() {}
	/*OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}*/
	void ff(int n) {
		for (int i = 0; i < n; i++) {
			//parent[i] = i;
			//rank[i] = 1;
			parent.push_back(i);
			rank.push_back(1);

		//	printf("> %d ", parent[i]);
		}
	}

	int find(int u) { //u가 속한 트리의 루트 번호 반환
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	int merge(int u, int v) { //u가 속한 트리와 v가 속한 트리를 합침
//		if (u == -1 || v == -1) return max(u, v); //u나 v가 공집합이면 하나를 반환

		u = find(u);
		v = find(v);
//		printf("u: %d v: %d\n", u, v);
		//		if (u == v) return u; //u와 v가 이미 같은 집합에 속하는 경우 걸러냄
		if (u != v) { //혹은 이렇게
			if (rank[u] > rank[v]) swap(u, v);

			//스왑하면 rank[v]가 항상 rank[u] 이상이기 때문에 u를 v의 자식으로 넣는다
			parent[u] = v;
			rank[v] += rank[u];
			rank[u] = 1;
			//		printf(">%d\n", rank[v]);
		}
		return rank[v];
	}
};
struct OptimizedDisjointSet js;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a.clear();
		b.clear();
		js.parent.clear();
		js.rank.clear();

		scanf("%d", &f);
		js.ff(f*2);
		for (int j = 0; j < f; j++) {
			scanf("%s %s", &p, &q);
			a.push_back({ p,q });
			b.push_back(p);
			b.push_back(q);			
		}
		//for (int j = 0; j < a.size(); j++) {
		//	cout << a[j].first << '\n';
		//}
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());

		for (int j = 0; j < f; j++) {
			int u = lower_bound(b.begin(), b.end(), a[j].first) - b.begin();
			int v = lower_bound(b.begin(), b.end(), a[j].second) - b.begin();
//			printf("x: %d y: %d\n", u, v);
			printf("%d\n", js.merge(u, v));
		}
	}
}
