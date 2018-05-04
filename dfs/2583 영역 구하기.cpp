#include <stdio.h>
#include <algorithm>
using namespace std;

int m, n, k, map[500][500], total = 0, res[300], cnt = 1;
int x1, y11, x2, y2;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int y, int x) {
	map[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int yy = dy[i] + y;
		int xx = dx[i] + x;

		if (xx<0 || xx>=m || yy<0 || yy>=n) continue;
		if (map[yy][xx] == 0) {
			cnt++;
			dfs(yy, xx);
		}
	}
	return cnt;
}

int main() {
	scanf("%d%d%d", &m, &n, &k); //m이 세로 n이 가로
	while (k--) {
		scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
		for (int i = x1; i < x2; i++) {
			for (int j = y11; j < y2; j++) {
//				printf("%d %d\n", i, j);
				if (map[i][j] == 0) {
					map[i][j] = 1;
				}
			}
		}
	}
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		printf("%d ", map[i][j]);
	//	}
	//	puts("\n");
	//}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cnt = 1;
				res[total++] = dfs(i, j);
//				printf(">%d\n", total);
			}
		}
	}

	sort(res, res + total);
	printf("%d\n", total);
	for (int i = 0; i < total; i++) {
		printf("%d ", res[i]);
	}
}
