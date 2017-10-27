#include <stdio.h>
int n, a[105][105], x = -1, y = 0, num = 1, z=1;

int main() {
	scanf("%d", &n);
	int max = n;

	while (max > 0) {
		for (int i = 0; i < max; i++) {
			x += z;
			a[y][x] = num;
			num++;
		}
		max--;

		for (int i = 0; i < max; i++) {
			y += z;
			a[y][x] = num;
			num++;
		}
		z *= -1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
}
