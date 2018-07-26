#include <stdio.h>
int n, m;
char a[15][15], b[15][15];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", &b[i]);
		for (int j = 0; j < m * 2; j++) {
			if (b[i][j] != a[i][j / 2]) {
				printf("Not Eyfa");
				return 0;
			}
		}
	}
	printf("Eyfa");
}
