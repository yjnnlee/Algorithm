#include <stdio.h>
int n, x, y, map[105][105];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		for (int p = y; p < y + 10; p++) {
			for (int q = x; q < x + 10; q++) {
				map[p][q] = 1;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j]) res++;
		}
	}
	printf("%d", res);
}
