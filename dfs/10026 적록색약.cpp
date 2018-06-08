#include <stdio.h>
#include <string.h>
using namespace std;

int n, res1 = 0, res2 = 0, visit[105][105];
char map[105][105];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int y, int x, char c){
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int xx = dx[i] + x;
		int yy = dy[i] + y;

		if (map[yy][xx] == c && !visit[yy][xx]) {
			dfs(yy, xx, c);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
			scanf("%s", &map[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				//printf("%c\n", map[i][j]);
				dfs(i, j, map[i][j]);
				res1++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'R') {
				map[i][j] = 'G';
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				dfs(i, j, map[i][j]);
				res2++;
			}
		}
	}
	printf("%d %d", res1, res2);
}
