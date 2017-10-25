#include <stdio.h>
int n;
int main() {
	scanf("%d", &n);

	for (int i = 2; i < n; i++) {
		for (int j = 2; j <= i; j++) {
			if (i%j == 0) {
				if (i > j) break;
				else printf("%d ", i);
			}
		}
	}
}
