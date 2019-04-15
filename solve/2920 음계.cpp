#include <stdio.h>
int n[10], a[10] = { 0,8,7,6,5,4,3,2,1 };
int main() {
	for (int i = 1; i <= 8; i++) {
		scanf("%d", &n[i]);
	}

	for (int i = 1; i <= 8; i++) {
		if (n[i] != i) {
			for (int j = 1; j <= 8; j++) {
				if (n[j] != a[j]) {
					printf("mixed");
					return 0;
				}
			}
			printf("descending");
			return 0;
		}
	}
	printf("ascending");
	return 0;
}
