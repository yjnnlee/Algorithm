#include <stdio.h>

int n;
long long int sum = 0;

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &n);
		sum += (n * n);
	}
	printf("%d", sum % 10);
}
