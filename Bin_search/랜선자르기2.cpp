#include <stdio.h>
#include <algorithm>
using namespace std;

int k, n, len[100000];

int main() {
	scanf("%d %d", &k, &n);

	for (int i = 0; i < k; i++) {
		scanf("%d", &len[i]);
	}

	long long l = 0, r = 0x7fffffff, p;
	int num = 0;

	while (l <= r) {
		p = (l + r) / 2;
		long long res = 0;

		for (int i = 0; i<k; i++) {
			res += len[i] / p;
		}
		if (res >= n) {
			num = p;
			l = p + 1;
		}
		else r = p - 1;
	}
	printf("%d\n", num);
	return 0;
}