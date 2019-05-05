#include <stdio.h>
#include <algorithm>
int n, p[1005], res = 0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	std::sort(p, p + n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			res += p[j];
		}
	}
	printf("%d", res);
}
