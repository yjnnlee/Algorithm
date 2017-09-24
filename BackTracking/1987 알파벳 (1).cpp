#include <stdio.h>

int r, c, res = 0;
char map[21][21], visited[100];

void solve(int y, int x, int tmpres) {
	if (tmpres > res) res = tmpres;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[map[i][j] - 'a'] == 1 || i < 0 || j < 0 || i >= r || j >= c) {
				continue;
			}
			else {
				visited[map[i][j] - 'a'] = 1;
				solve(i, j, tmpres + 1);
				visited[map[i][j] - 'a'] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &r, &c); //세로 r 가로 c
	for (int i = 0; i < r; i++) {
		scanf("%s", &map[i]);
	}
	visited[map[0][0] - 'a'] = 1;
	solve(r, c, 0);

	printf("%d", res);
}
