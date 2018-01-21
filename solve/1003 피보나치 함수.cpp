#include <stdio.h>
int n, a, sum1 = 0, sum2 = 0, dp1[10000];

int fibonacci(int n) {
	if (n == 0) {
		sum1++;
		return 0;
	}
	if (n == 1) {
		sum2++;
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		fibonacci(a);
		printf("%d %d\n", sum1, sum2);
		sum1 = 0, sum2 = 0;
	}

}
