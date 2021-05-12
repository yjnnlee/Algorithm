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
