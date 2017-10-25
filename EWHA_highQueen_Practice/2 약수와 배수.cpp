#include <stdio.h>
int n, num[45], m, sum1=0, sum2=0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	scanf("%d", &m);

	for (int i = 0; i < n; i++) {
		if (num[i] <= m) { 
			if (m % num[i] == 0) {
				sum1 += num[i];
			}
		}

		if (num[i] >= m) {
			if (num[i] % m == 0) {
				sum2 += num[i];
			}
		}
	}

	printf("%d\n%d", sum1, sum2);
}
