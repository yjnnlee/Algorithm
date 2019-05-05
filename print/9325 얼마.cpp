#include <stdio.h>
int k, s,n,q,p, sum = 0;
int main() {
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &s, &n);
		while (n--) {
			scanf("%d %d", &q, &p);
			sum += q*p;
		}
		printf("%d\n", s+sum);
		sum = 0;
	}
}
