//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//
//int n, k, c[10000000];
//struct jew {
//	int m, v;
//};
//jew a[100000];
//int res = 0;
//
//bool cmp(jew a, jew b) { return a.v > b.v; }
//
//int main() {
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++) {
//		scanf("%d %d", &a[i].m, &a[i].v);
//	}
//	for (int i = 0; i < k; i++) {
//		scanf("%d", &c[i]);
//	}
//	sort(a, a + n, cmp); //내림차순
//	sort(c, c + k); //오름차순
//
//					
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (a[i].m <= c[j]) {
//				res += a[i].v;
//				a[i].m = 0;
//				c[j] = 0;
//				break;
//			}
//		}
//	}
//	printf("%d", res);
//}

//#include <stdio.h>
//#include <algorithm>
//#include <set>
//#include <vector>
//using namespace std;
//
//int n, k;
//struct jew {
//	int m, v;
//};
//jew a[100000];
//int res = 0;
//
//bool cmp(jew a, jew b) { return a.v > b.v; }
//
//int main() {
//	multiset<int> c;
//
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++) {
//		scanf("%d %d", &a[i].m, &a[i].v);
//	}
//	int tmp;
//	for (int i = 0; i < k; i++) {
//		scanf("%d", &tmp);
//		c.insert(tmp); //오름차순 정렬
//	}
//	sort(a, a + n, cmp); //내림차순
//
//	for (int i = 0; i < n; i++) {
//		if (c.empty()) break;
//		if (c.upper_bound(a[i].m) != c.end()) {
//			auto up = c.upper_bound(a[i].m);
//			res += a[i].v;
//			c.erase(up);
//		}
//	}
//	printf("%d", res);
//}

#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n, k;
struct jew {
	int m, v;
};
jew a[1000000];
long long int res = 0;

bool cmp(jew a, jew b) { 
	if (a.v != b.v)
		return a.v > b.v;
	else
		return a.m < b.m;
}

int main() {
	multiset<int> c;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].m, &a[i].v);
	}
	int tmp;
	for (int i = 0; i < k; i++) {
		scanf("%d", &tmp);
		c.insert(tmp); //오름차순 정렬
	}
	sort(a, a + n, cmp); //내림차순

	for (int i = 0; i < n; i++) {
		if (c.empty()) break;
		auto up = c.lower_bound(a[i].m);
		if (up != c.end()) {
			res += a[i].v;
			c.erase(up);
		}
	}
	printf("%lld", res);
}