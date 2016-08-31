#include <stdio.h>
#include <algorithm>
using namespace std;

int len[10000], k, n;

long long bin_search(int a, int k) {
	long long res = 0;
	for (int i = 0; i < k; i++) {
		res += len[i] / a;
	}
	return res;
}

int main() {
	scanf("%d %d", &k, &n);

	int rmax = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &len[i]);
		if (rmax < len[i]) {
			rmax = len[i];
		}
	}

	int l = 0, r = rmax, res = 0;

	while (l <= r) {
		int p = (l + r) / 2;
		long long a = bin_search(p, k);

		if (a < n) {
			r = p - 1;
		}
		else {
			if (res < p) {
				res = p;
			}
			l = p + 1;
		}
	}
	printf("%d\n", res);

	return 0;
}