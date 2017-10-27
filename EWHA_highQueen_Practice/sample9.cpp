#include <stdio.h>
int w, h, res = 0, map[55][55];

void dfs(int y, int x) {
	map[y][x] = 0;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int a = y + i;
			int b = x + j;

			if (map[a][b] == 1) {
				dfs(a, b);
			}
		}
	}
}

int main() {
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1) {
				dfs(i, j);
				res++;
			}
		}
	}

	printf("%d", res);
}
