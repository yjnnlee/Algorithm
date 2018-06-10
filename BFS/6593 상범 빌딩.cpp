#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;

struct point {
	int h, x, y;
	point() {}
	point(int a, int b, int c) {
		h = a;
		y = b;
		x = c;
	}
};

int h, x, y, visit[40][40][40];
char map[40][40][40];
point start, finish;
int dx[] = { 1,-1,0,0,0,0};
int dy[] = { 0,0,1,-1,0,0};
int dh[] = { 0,0,0,0,1,-1 };

void bfs() {
	queue<point> q;
	q.push(start);

	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		int nowh = now.h;
		int nowx = now.x;
		int nowy = now.y;

		for (int i = 0; i < 6; i++) {
			int nh = nowh + dh[i];
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];

			if (map[nh][ny][nx] == '.' && nh >= 0 && ny >= 0 && nx >= 0 && nh < h&&ny < y&&nx < x && !visit[nh][ny][nx]) {
				visit[nh][ny][nx] = visit[nowh][nowy][nowx] + 1;
				q.push(point(nh, ny, nx));
			}
		}
	}
	if (visit[finish.h][finish.y][finish.x] > 0) {
		printf("Escaped in %d minute(s).\n", visit[finish.h][finish.y][finish.x]);
	}
	else {
		printf("Trapped!\n");
	}
}

int main() {
	while (1) {
		scanf("%d %d %d", &h, &y, &x);
		if (h == 0 && x == 0 && y == 0) return 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < y; j++) {
				for (int k = 0; k < x; k++) {
					map[i][j][k] = NULL;
					visit[i][j][k] = 0;
				}
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < y; j++) {
				scanf("%s", map[i][j]);
				for (int k = 0; k < x; k++) {
					if (map[i][j][k] == 'S') start = point(i, j, k);
					if (map[i][j][k] == 'E') finish = point(i, j, k);
				}
			}
		}

		/*for (int i = 0; i < h; i++) {
			for (int j = 0; j < y; j++) {
				for (int k = 0; k < x; k++) {
					printf("%c", map[i][j][k]);
				}
				printf("\n");
			}
			printf("\n");
		}*/

		bfs();
	}
}
