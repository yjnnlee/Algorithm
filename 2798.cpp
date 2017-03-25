#include <stdio.h>
int n, a[101], m, sum = 0, res=0;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			for (int q = j+1; q < n; q++) {
				sum = a[i] + a[j] + a[q];

				if (sum <= m && sum > res) {
					res = sum;
				}
			}
		}
	}

	printf("%d", res);
}
