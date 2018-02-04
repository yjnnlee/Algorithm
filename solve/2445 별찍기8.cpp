#include <stdio.h>

int n;
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		for (int k = i; k < n * 2 - i; k++) {
			printf(" ");
		}
		for (int j = i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n-1; i > 0; i--) {
		for (int j = i; j > 0; j--) {
			printf("*");
		}
		for (int k = 0; k < n * 2 -i * 2; k++) {
			printf(" ");
		}
		for (int j = i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
}
