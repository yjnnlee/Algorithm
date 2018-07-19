#include <stdio.h>
int n, a[105][105], x = -1, y = 0, num = 1, z = 1, n2;
int cnt = 0;

int main() {
	scanf("%d%d", &n, &n2); //n줄 n2칸 //5 3
	int max = n, max2 = n2;

	while (max > 0 || max2 > 0) {
		for (int i = 0; i < max2; i++) {
			x += z;
			a[y][x] = num;
			num++;
		}
		max2--;
		cnt++;

		for (int i = 0; i < max; i++) {
			y += z;
			a[y][x] = num;
			num++;
		}
		max--;
		z *= -1;
		cnt++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n2; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}

	printf("%d", cnt);
}
