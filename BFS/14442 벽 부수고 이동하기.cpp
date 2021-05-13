#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
#include <tuple>
using namespace std;
//queue<pair<pair<int, int>,int>>q;
queue<tuple<int, int, int>>q;
int map[1001][1001], visit[1001][1001][11];
int dx[] = { 0,0,-1,1}, dy[] = { -1,1,0,0 };
int n, m, k, res = 0;

int bfs(int yy, int xx, int kk) { //kk=벽을 부순 횟수
	visit[0][0][0] = 1;
	q.push({ 0,0,0 });
	while (!q.empty()) {
		int y, x, smash;
		tie(y, x, smash) = q.front(); q.pop();

		if (y == n - 1 && x == m - 1) {
			return visit[y][x][smash];
		}

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (map[ny][nx] == 1 && smash < k && visit[ny][nx][smash+1] == 0) { //이동하려는 칸이 벽이고, 벽을 부술 횟수가 남은 경우->부순다
				q.push({ ny,nx,smash + 1 });
				visit[ny][nx][smash + 1] = visit[y][x][smash] + 1;
			}
			else if (map[ny][nx] == 0 && visit[ny][nx][smash] == 0) { //벽이 없고, 방문하지 않은 곳->그냥 간다
				q.push({ ny,nx,smash });
				visit[ny][nx][smash] = visit[y][x][smash] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			map[i][j] = a[j] - '0';
		}
	}

	int res = bfs(0, 0, 0);
	cout << res;
}
