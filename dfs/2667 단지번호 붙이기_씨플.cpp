#include <stdio.h>
#include <algorithm>
using namespace std;
int n, map[300][300], res[300];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int cnt = 1;

int dfs(int y, int x) {
	map[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];

		if (map[yy][xx] == 1 && yy >= 0 && xx >= 0 && yy < n && xx < n) {
			dfs(yy, xx);
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin>>tmp;
		for (int j = 0; j < n; j++) {
			map[i][j] = tmp[j] - '0';
		}
	}
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) {
				cnt = 1;
				res[index++] = dfs(i, j);
			}
		}
	}
	sort(res, res + index);
	cout << index << '\n';
	for (int i = 0; i < index; i++) {
		cout << res[i] << '\n';
	}
}
