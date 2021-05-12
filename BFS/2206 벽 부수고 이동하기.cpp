#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
using namespace std;
queue<pair<pair<int, int>,int>>q;
int map[1001][1001], visit[1001][1001][2];
int dx[] = { 0,0,-1,1}, dy[] = { -1,1,0,0 };
int n, m, res = 0;

void bfs(int y, int x, int k) { //k=0이면 벽을 부순 적 없음, k=1이면 있음
	q.push(make_pair(make_pair(y, x), k));
	visit[y][x][k] = 1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int destroy = q.front().second;
		q.pop();

		if (y == n - 1 && x == m - 1) {
			return;
		}

		//cout << y << " " << x << endl;
		for (int i = 0; i < 4; i++) {
			int xx = dx[i] + x;
			int yy = dy[i] + y;
			//벽 부순 거랑 안 부순 건 다른 케이스니까 따로 bfs를 보냄
			//안 부숨
			if (map[yy][xx] == 0 && visit[yy][xx][destroy] == 0 && yy >= 0 && yy < n && xx >= 0 && xx < m) {
				visit[yy][xx][destroy] = visit[y][x][destroy] + 1;
				q.push(make_pair(make_pair(yy, xx), destroy));
			}
			//벽을 부순 적 없음 -> 부숨
			if (destroy == 0 && map[yy][xx] == 1 && visit[yy][xx][destroy+1] == 0&& yy >= 0 && yy < n && xx >= 0 && xx < m) {
				visit[yy][xx][destroy+1] = visit[y][x][destroy] + 1;
				q.push(make_pair(make_pair(yy, xx), destroy+1));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			map[i][j] = a[j] - '0';
		}
	}

	bfs(0, 0, 0);

	if (visit[n - 1][m - 1][0] != 0 && visit[n - 1][m - 1][1] != 0) { //부수고 안 부수고 다 있으면 작은 값
		cout << min(visit[n - 1][m - 1][0], visit[n - 1][m - 1][1]);
	}
	else if (visit[n - 1][m - 1][0] != 0 && visit[n - 1][m - 1][1] == 0) { //안 부순 값만 있으면
		cout << visit[n - 1][m - 1][0];
	}
	else if (visit[n - 1][m - 1][1] != 0 && visit[n - 1][m - 1][0] == 0) { //부순 값만 있으면
		cout << visit[n - 1][m - 1][1];
	}
	else { //갈 수 없음
		cout << -1;
	}
}
