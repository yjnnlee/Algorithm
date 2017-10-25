#include <stdio.h>
#include <algorithm>
using namespace std;
//bin search
int n, a[100001];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n);
	//-99 -2 -1 4 98

	int l = 0, r = n - 1, sum, lv = 0, rv = 0, min = 1e9;

	while (l < r) {
		sum = abs(a[l] + a[r]);
//		printf("sum: %d r: %d, l:%d\n", sum, r, l);
		if (sum < min) {
			min = sum;
			lv = l;
			rv = r;
//			printf("%d %d\n", lv, rv);
		}

		if (a[l] + a[r] > 0) {
			r -= 1;
		}
		else l += 1;
	}

	printf("%d %d", a[lv], a[rv]);
}
