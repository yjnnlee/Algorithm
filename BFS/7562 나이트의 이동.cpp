#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;

int n, l, visit[305][305], goalx, goaly, a, b;

int dx[] = { 2, 2,1,1,-1,-1,-2,-2 };
int dy[] = { 1,-1,2,-2,2,-2,1,-1 };

int bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();

		if (nowx == goalx && nowy == goaly) break;

		for (int i = 0; i < 8; i++) {
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];			

			if (nextx >= 0 && nextx < l && nexty >= 0 && nexty < l && visit[nexty][nextx] == 0) {
//				printf("next: %d %d\n", nextx, nexty);
				q.push(make_pair(nextx, nexty));
				visit[nexty][nextx] = visit[nowy][nowx] + 1;
			}
		}
	}
	return visit[goaly][goalx];
}

int main() {
	scanf("%d", &n);
	while (n--) {
		memset(visit, 0, sizeof(visit));
		scanf("%d%d%d%d%d", &l, &a, &b, &goalx, &goaly);
		printf("%d\n", bfs(a, b));
	}
}
