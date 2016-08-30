#include <stdio.h>
#include <algorithm>
using namespace std;

const int max_m = 500001;

int n, m, k[max_m], kk[max_m];

int bin_search(int l, int r, int n) {
	int res, p = (l + r) / 2;

	if (l > r) {
		return 0;
	}
	else {
		if (k[p] == n) {
			res = bin_search(l, p - 1, n);
			res += bin_search(p + 1, r, n);
			res += 1;
		}
		else if (k[p] < n) res = bin_search(p + 1, r, n);
		else res = bin_search(l, p - 1, n);
	}

	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k[i]);
	}
	sort(k, k + n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &kk[i]);
	}

	for (int i = 0; i < m; i++) {
		int l = 0, r = n - 1;
		printf("%d ", bin_search(l, r, kk[i]));
	}

	return 0;
}