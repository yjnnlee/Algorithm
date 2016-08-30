#include <stdio.h>
#include <algorithm>
using namespace std;

const int max_m = 100000;
int n, m, k[max_m];

int bin_search(int x) {
	int l = 0, r = n - 1, p;

	//범위가 사라질 때까지 반복
	while (l <= r) {
		p = (l + r) / 2;
		if (k[p] == x) return 1; //발견
		else if (k[p] < x) l = p + 1;
		else r = p - 1;
	}
	return 0; //발견하지 못함
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k[i]);
	}
	sort(k, k + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		printf("%d\n", bin_search(a));
	}
	return 0;
}