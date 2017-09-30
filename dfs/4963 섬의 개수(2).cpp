#include <stdio.h>
#include <string.h>
int w, h, map[55][55], res = 0, chk[55][55] = { 0, };
int gox[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int goy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void find(int a, int b) {
	chk[a][b] = 1;
	int x, y;
	
	for (int i = 0; i < 9; i++) {
		y = gox[i] + a;
		x = goy[i] + b;
		if (0 <= x && x < h && 0 <= y && y < w) {
			if (chk[x][y] == 0 && map[x][y] == 1) {
				find(x, y);
			}
		}
	}
}

int main() {
	while (1) {
		res = 0;
		memset(map, 0, sizeof(map));
		memset(chk, 0, sizeof(chk));

		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			return 0;
		}
		else {
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					scanf("%d", &map[i][j]);
				}
			}

			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (chk[i][j] == 0 && map[i][j] == 1) {
						res++;
						find(i, j);
					}
				}
			}
			
			printf("%d\n", res);
		}
	}
}
