#include <stdio.h>

int n, m, pic[501][501], res = 0, res2;
int gox[4] = { 0, 1, 0, -1 };
int goy[4] = { 1, 0, -1, 0 };
int chk[501][501];

int s(int x, int y) {
	int cnt = 1;

	if (x<0 || x>=n || y<0 || y>=m) return 0;
	if (pic[x][y] == 0 || chk[x][y]==1) return 0;

	chk[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		cnt += s(x + goy[i], y + gox[i]);
	}
	return cnt;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &pic[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pic[i][j] == 0 || chk[i][j] == 1) continue;
			int t = s(i, j);
			res++;

			if (res2 < t) {
				res2 = t;
			}
		}
	}

	printf("%d\n%d", res, res2);
}
