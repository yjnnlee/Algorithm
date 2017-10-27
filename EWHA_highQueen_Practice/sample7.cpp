#include <stdio.h>
#include <string.h>
int n, a[9999999], c=0, i=0;

int main() {
	scanf("%d", &n);

	while (n > 0) {
		if (n % 2) {
			a[c] = i;
			c++;
		}
		n /= 2;
		i++;
	}
	for (int i = 0; i < c; i++) {
		printf("%d ", a[i]);
	}
}
