#include <stdio.h>
#include <algorithm>

int n, map[105][105], cnt = 0, res = -1, chk[105][105], max = -1, min = 1e9;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int y, int x, int height) {
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	chk[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];

//		if (yy < 0 || yy >= n || xx < 0 || xx >= n) return;
		if (map[yy][xx] > height && chk[yy][xx] == 0) {
			dfs(yy, xx, height);
//			printf(">%d\n", height);
		}
	}
}

//void chkarr(int height) {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if(map[i][j] > height) chk[i][j] = 1;
//		}
//	}
//}
//
void chkclear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			chk[i][j] = 0;
		}
	}
}

//void f() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("%d ", chk[i][j]);
//		}
//		puts("");
//	}
//}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (max < map[i][j]) max = map[i][j];
			if (min > map[i][j]) min = map[i][j];
		}
	}
	
	for (int k = min; k <= max; k++) {
		//chkarr(k);
		cnt = 0;
		chkclear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > k && chk[i][j] == 0) {
					cnt++;
					dfs(i, j, k);
				}
			}
		}
		if (cnt > res) res = cnt;
	}
	if (res == 0) printf("1");
	else printf("%d", res);
}
