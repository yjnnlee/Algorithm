#include <stdio.h>
#include <algorithm>
int n, p[100005];
long long int res = 0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	std::sort(p, p + n);
	for (int i = n - 1; i >= 0; i--) {
		if (res < p[i] * (n - i)) res = p[i] * (n - i);
	}
	printf("%lld", res);
}
