#include <stdio.h>
int n, k, a[10001],c=1;
int main() {
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			a[c] = n / i;
			c++;
		}
	}

	//for (int i = 1; i < 10; i++) {
	//	printf("%d ", a[i]);
	//}
	printf("%d", a[c - k]);
}
