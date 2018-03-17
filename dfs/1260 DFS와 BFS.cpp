#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;

int n, m, v, a, b;
bool map[1010][1010], chk[1010];
queue<int> q;

void dfs(int now){
	printf("%d ", now);
	chk[now] = 1;
	for (int i = 1; i <= n; i++) {
		if (!chk[i] && map[now][i]) {
			chk[i] = 1;
			dfs(i);
		}
	}
}

void bfs() {
	memset(chk, false, sizeof(chk));
	q.push(v);
	chk[v] = 1;

	while (!q.empty()) {
		for (int i = 1; i <= n; i++) {
			if (!chk[i] && map[q.front()][i]) {
				chk[i] = 1;
				q.push(i);
			}
		}
		printf("%d ", q.front());
		q.pop();
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &v);
//	freopen("input.txt", "r", stdin);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
	}

	dfs(v);
	puts("");
	bfs();
}
