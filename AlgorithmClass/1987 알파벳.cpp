//#include <stdio.h>
//
//int r, c, res = 0;
//char map[21][21], visited[100];
//
//void solve(int y, int x, int tmpres) {
//	if (tmpres > res) res = tmpres;
//
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			if (visited[map[i][j] - 'a'] == 1 || i < 0 || j < 0 || i >= r || j >= c) {
//				continue;
//			}
//			else {
//				visited[map[i][j] - 'a'] = 1;
//				solve(i, j, tmpres + 1);
//				visited[map[i][j] - 'a'] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	scanf("%d %d", &r, &c); //세로 r 가로 c
//	for (int i = 0; i < r; i++) {
//		scanf("%s", &map[i]);
//	}
//	visited[map[0][0] - 'a'] = 1;
//	solve(r, c, 0);
//
//	printf("%d", res);
//}


#include <stdio.h>

const int dir[4][2] = { {1, 0},
						{0, 1},
						{0,-1},
						{-1,0} };
int r, c, res = 0;
char map[21][21], visited[100];

void solve(int y, int x, int tmpRes) {
	if (tmpRes > res) res = tmpRes;

	for (int k = 0; k < 4; k++) {
		int i = y + dir[k][0];
		int j = x + dir[k][1];

		if (visited[map[i][j] - 'A'] == 1 || i < 0 || j < 0 || i >= r || j >= c) {
			continue;
		}
		else {
			visited[map[i][j] - 'A'] = 1;
			solve(i, j, tmpRes + 1);
			visited[map[i][j] - 'A'] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &r, &c); //세로 r 가로 c
	for (int i = 0; i < r; i++) {
		scanf("%s", &map[i]);
	}
	visited[map[0][0] - 'A'] = 1;
	solve(0, 0, 1);

	printf("%d", res);
}
