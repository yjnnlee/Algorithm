#include <stdio.h>
int x1, x2, y1, y2, a[105][105], res = 0;
int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int j = x1; j < x2; j++) {
			for (int t = y1; t < y2; t++) {
				a[j][t]++;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (a[i][j]) res++;
		}
	}
	printf("%d", res);
}
