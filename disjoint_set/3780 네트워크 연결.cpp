#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n, m, a, b, c,d, res = 0;
char e;
//int parent[20007], len[20007];

struct F {
	vector<int> parent, len;
	F(int n) : parent(20007), len(20007, 0) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (parent[u] == u) {
			return u;
		}
		else {
			len[u] += len[parent[u]];
			return parent[u] = find(parent[u]); //find(parent[u])가 리턴됨
//			return find(parent[u]);
		}
	}
	void merge(int u, int v) {
		len[u] = abs(u - v) % 1000;
		parent[u] = v;
	}
};
int main() {
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &b);
		F f(b);
		while (1) {
			scanf(" %c", &e);
//			if (e == 'O') break;
			if (e == 'E') {
				scanf("%d", &c);
				f.find(c);
				printf("%d\n", f.len[c]);
			}
			else if (e == 'I') {
				scanf("%d%d", &c, &d);
				f.merge(c, d);
			}
			else break;
		}
	}
}
