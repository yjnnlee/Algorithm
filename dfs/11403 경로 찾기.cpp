#include <stdio.h>
#include <memory.h>
int n, map[105][105], chk[105][105];

void dfs(int now, int x, int y) {
	map[now][y] = 1, chk[now][y] = 1;
	for (int i = 1; i <= n; i++) {
		if (!chk[now][i] && map[y][i]) dfs(now, y, i);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!chk[i][i] && map[i][j]) dfs(i, i, j);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

//0 1, 1 2, 2,0
