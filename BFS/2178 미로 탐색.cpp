#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n, m,cnt =1, map[105][105], visit[105][105];
queue<pair<int,int>> q;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int bfs() {
	q.push(make_pair(0, 0));
	visit[0][0] = 1;

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();

		if (nowX == m && nowY == n) break;

		for (int i = 0; i < 4; i++) {
			int nextX = dx[i] + nowX;
			int nextY = dy[i] + nowY;

			if (map[nextY][nextX] == 1 && !visit[nextY][nextX] && nextY >= 0 && nextY < n && nextX >= 0 && nextX < m) {
				visit[nextY][nextX] = visit[nowY][nowX] + 1; //이전 방문값+1 = 다음 방문값
				q.push(make_pair(nextX, nextY));
//				printf("EE!!");
			}
		}
	}
	return visit[n - 1][m - 1];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	printf("%d", bfs());
}
