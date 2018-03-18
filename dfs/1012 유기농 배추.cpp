#include <stdio.h>
#include <memory.h>

int map[55][55], t, a, b, k, cnt = 0, x, y;
int w[4] = { -1,1,0,0 };
int h[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	map[x][y] = 0;
	for (int i = 0; i < 4; i++)	
		if (map[x + w[i]][y + h[i]]) dfs(x + w[i], y + h[i]);

	//		if (p < 0 || q < 0 || p >= x || q >= y) continue;
	//	if (map[x - 1][y] || map[x + 1][y] || map[x][y - 1] || map[x][y + 1]) {}
}

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) { // while(t--) {
		cnt = 0, memset(map, 0, sizeof(map));
		scanf("%d%d%d", &x, &y, &k);
		for (int j = 0; j < k; j++) { //while(k--){ 로 하면 가독성 좋아짐
			scanf("%d%d", &a, &b);
			map[++a][++b] = 1;
		}

		for (int j = 1; j <= x; j++)
			for (int jj = 1; jj <= y; jj++)
				if (map[j][jj]) dfs(j, jj), cnt++;

		printf("%d\n", cnt);
	}
}
