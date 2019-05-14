#include <stdio.h>
int t, n, a[105];
long long sum = 0;
int gcd(int a, int b) {
	if (b == 0) return a;
	gcd(b, a%b);
}

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
		}
		for (int p = 0; p < n; p++) {
			for (int q = p; q < n; q++) {
				if (p == q) continue;
				if(a[p] > a[q]) sum += gcd(a[p], a[q]);
				else sum += gcd(a[q], a[p]);
			}
		}
		printf("%lld\n", sum);
		sum = 0;
	}
}
