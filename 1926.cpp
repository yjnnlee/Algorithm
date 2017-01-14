#include <stdio.h>

int n, m, pic[501][501], res = 0, res2 = 0;
int cnt = 1, chk[501][501];

int abs(int h) {
	if (h < 0) return -h;
	else return h;
}

void s(int x, int y) {

	if (x<0 || x >= n || y<0 || y >= m) return ;
	if (pic[x][y] == 0 || chk[x][y] == 1) return ;

	chk[x][y] == 1;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (abs(i) + abs(j) == 2) continue;

			int p = x + i;
			int q = y + j;

			if (pic[p][q] == 1) {
				s(p, q);
			}
		}
	}

	if (res2 < cnt) {
		res2 = cnt;
	}
	cnt = 0;
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

			res++;
			s(i, j);

		}
	}

	printf("%d\n%d", res, res2);
}