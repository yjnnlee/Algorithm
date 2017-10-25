#include <stdio.h>
int n, a[1005], k;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			a[i] = i;
		}
	}

	printf("%d", a[k]);
}
