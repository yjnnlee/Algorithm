#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n, m, a, b, c, d, res = 0;
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
			if (e == 'O') break;
			if (e == 'E') {
				scanf("%d", &c);
				f.find(c);
				printf("%d\n", f.len[c]);
			}
			else if (e == 'I') {
				scanf("%d%d", &c, &d);
				f.merge(c, d);
			}
		}
	}
}

// --------------------------------------------

//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//int n, m, a, b, c, d, res = 0;
//char e;
//
//struct F {
//	vector<int> parent, rank, len;
//	F(int n) :parent(20005), len(20005, 0) {
//		for (int i = 0; i <= n; i++) {
//			parent[i] = i;
//		}
//	}
//
//	int find(int u) {
//		if (parent[u] == u) {
//			return u;
//		}
//		else {
//			int t = find(parent[u]);
//			len[u] += len[parent[u]];
//			parent[u] = t;
//			return find(parent[u]); //find(parent[u])가 리턴됨
//
//			/*
//			(1)
//			int t = find(parent[u]);
//			len[u] += len[parent[u]];
//			parent[u] = t;
//			return find(parent[u]);
//
//			(2)
//			len[u] += len[parent[u]];
//			return parent[u] = find(parent[u]);
//
//			(3)
//			len[u] += len[parent[u]];
//			parent[u] = find(parent[u]);
//			return find(parent[u]);
//			
//			아니ㄱㄹㄴㅀㅁ 이거 세개 왜 다름 ???
//			1번만 맞는데 왣릳ㄹㄴㅇㄹㄹ 뭐지
//			진짜 모르겠음 에바쌈치 일단 포기
//			*/
//		}
//	}
//	void merge(int u, int v) {
//		len[u] = abs(u - v) % 1000;
//		//		u = find(u);
//		//		v = find(v);
//		if (u == v) return;
//		//		if (rank[u] > rank[v]) swap(rank[u], rank[v]);
//		//		if (rank[u] == rank[v]) rank[v]++;
//		//		rank[] += rank[];
//		parent[u] = v;
//	}
//};
//int main() {
//	scanf("%d", &a);
//	for (int i = 0; i < a; i++) {
//		scanf("%d", &b);
//		F f(b);
//		while (1) {
//			scanf(" %c", &e);
//			if (e == 'O') break;
//			if (e == 'E') {
//				scanf("%d", &c);
//				f.find(c);
//				printf("%d\n", f.len[c]);
//			}
//			if (e == 'I') {
//				scanf("%d %d", &c, &d);
//				f.merge(c, d);
//			}
//		}
//	}
//}
