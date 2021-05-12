//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <memory.h>
//using namespace std;
//int n, m;
//long long a[102];
//long long dp[102][15]; //위치, 초
//long long ans = 0;
//long long go(long long i, long long cnt) {
//	long long res;
//	if (dp[i][cnt] > 0) return dp[i][cnt];
//	if (cnt == m || i == n) {
//		res = a[i];
//	}
//	else {
//		//현재값+1위치값+cnt그대로 vs 현재값/2+2위치값+cnt+1
//		res = max(a[i] + go(i + 1, cnt + 1), a[i] / 2 + go(i + 2, cnt + 1));
//		//cout << "i: " << i << " " << "res: " << res << endl;
//	}
//	return dp[i][cnt] = res;
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	a[0] = 1;
//	//dp[0][0] = 1; //위치0의 0초에는 크기 1로 시작
//	//dp[1][1] = 1 + a[1]; //1위치는 0에서 1움직으로밖에 못 감
//	
//	cout << go(0, 0); //0위치에서 0초로 시작
//}

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
