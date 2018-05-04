#include <stdio.h>
#include <algorithm>
using namespace std;

int n, map[300][300], total = 0, res[3000], cnt = 1;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	map[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];

		if (yy < 0 || yy >= n || xx < 0 || xx >= n) continue;
		if (map[xx][yy] == 1) {
			dfs(xx, yy);
			cnt++;
		} 
	}
	return cnt;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		scanf("%1d", &map[i][j]);
		}
//		scanf("%s", map[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				cnt = 1;
				res[total++] = dfs(i, j);
			}
		}
	}
	sort(res, res + total);
	printf("%d\n", total);
	for (int i = 0; i < total; i++) {
		printf("%d\n", res[i]);
	}
}
