#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
queue<int> q;
//vector<int> order;
vector<vector<int>> map;
int n, a, b, m, x, y;
//int map[105][105];
bool chk[105];

int bfs(int start) {
	q.push(start);
	chk[start] = true;

	int distance[105];
	memset(distance, -1, sizeof(distance));
	distance[start] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
//		printf(">%d\n", map[now].size());
		for (int i = 0; i < map[now].size(); i++) {
			int next = map[now][i];
			if (!chk[next]) {
				chk[next] = true;
				q.push(next);
				distance[next] = distance[now] + 1;

				if (next == b) return distance[b];
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d %d %d %d", &n, &a, &b, &m);
	map.resize(n*n);
	while (m--) {
		scanf("%d %d", &x, &y);
//		map[x][y] = map[y][x] = 1;
		map[x].push_back(y);
		map[y].push_back(x);
	}

	printf("%d", bfs(a));
}
