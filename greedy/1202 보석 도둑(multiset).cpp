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
