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
