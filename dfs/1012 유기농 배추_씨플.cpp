#include <iostream>
#include <memory.h>
using namespace std;
int n, m, k, map[55][55];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int cnt = 0;

void dfs(int y, int x) {
	map[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];

		if (map[yy][xx] == 1 && yy >= 0 && xx >= 0 && yy < n && xx < m) {
			dfs(yy, xx);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	
	while (t--) {
		memset(map, 0, sizeof(map));
		cin >> n >> m >> k;
		for (int i = 0, a, b; i < k; i++) {
			cin >> a >> b;
			map[a][b] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}
}
