#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <queue>
using namespace std;
queue<pair<pair<int, int>,int>>q;
int visit[201][201];
int dx[] = { -2,-2,0,0,2,2 }, dy[] = { -1,1,-2,2,-1,1 };
int n;
int r, c, rr, cc; //r=y, c=x

void bfs(int r, int c) {
	q.push(make_pair(make_pair(r, c), 0));
	visit[r][c] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (y == cc && x == rr) {
			cout << cnt; return;
		}
		//cout << y << " " << x << endl;
		for (int i = 0; i < 6; i++) {
			int xx = dx[i] + x;
			int yy = dy[i] + y;
			if (!visit[yy][xx] && yy >= 0 && yy < n && xx >= 0 && xx < n) {
				visit[yy][xx] = 1;
				q.push(make_pair(make_pair(xx, yy), cnt + 1));
			}
		}
	}
	cout << -1;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> r >> c >> rr >> cc;

	bfs(r, c); //y,x
}
