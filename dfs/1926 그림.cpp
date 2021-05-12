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
using namespace std;
int map[501][501], visit[501][501];
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
int n, m;
int cnt = 0, sum = 1;
int ressum = 1;
void dfs(int y, int x) {
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = dx[i] + x;
		int yy = dy[i] + y;
		if (!visit[yy][xx] && yy >= 0 && y < n && xx >= 0 && x < m && map[yy][xx] == 1) {
			sum++;
			dfs(yy, xx);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visit[i][j] != 1) {
				cnt++;
				dfs(i, j);

				if (ressum < sum) ressum = sum;
				sum = 1;
			}
		}
	}
	if (cnt == 0) ressum = 0;
	cout << cnt << "\n" << ressum;
}
