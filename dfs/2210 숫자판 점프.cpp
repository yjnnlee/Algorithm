#include <iostream>
#include <set>
using namespace std;
int map[5][5];
set<int> st;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1, 0, 0 };

void dfs(int y, int x, int cnt, int num) {
	if (cnt ==  5) {
		st.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nexty = y + dy[i];
		int nextx = x + dx[i];

		if (nexty < 5 && 0 <= nexty && 0 <= nextx && nextx < 5) {
			dfs(nexty, nextx, cnt + 1, num * 10 + map[nexty][nextx]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0, map[i][j]);
		}
	}

	cout << st.size()<<'\n';
}
