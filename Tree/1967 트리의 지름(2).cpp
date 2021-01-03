#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int n, visit[10001];
struct Node {
	int index, dist;
};
vector<Node> tree[10001];

int maxDist = 0, maxIndex = 0;
void dfs(int now, int nowDist) {
	if (visit[now] != 0) return;
	if (nowDist > maxDist) {
		maxDist = nowDist;
		maxIndex = now;
	}
	visit[now] = 1;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i].index;
		dfs(next, nowDist + tree[now][i].dist);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}
	dfs(1, 0); //가장 멀리 있는 정점 구하기
	maxDist = 0;
	memset(visit, 0, sizeof(visit));
	dfs(maxIndex, 0); //가장 맨 끝 노드부터 가장 먼 노드 찾기

	cout << maxDist;
}
