#include <stdio.h>
int k, s,n,q, sum = 0;
int main() {
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &q);
			sum += q;
		}
		printf("%d\n", sum);
		sum = 0;
	}
}
