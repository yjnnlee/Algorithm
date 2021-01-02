#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int n, visit[10005], maxdiameter = 0, endpoint; //지름, 가장 끝 노드
vector<pair<int, int>> map[50005];

void dfs(int now, int len) {
	if (visit[now]) return;
	visit[now] = 1;
	if (maxdiameter < len) {
		maxdiameter = len;
		endpoint = now;
	}
	for (int i = 0; i < map[now].size(); i++) {
		dfs(map[now][i].first, len + map[now][i].second);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	dfs(1, 0); //가장 멀리 있는 정점 구하기
	maxdiameter = 0;
	memset(visit, 0, sizeof(visit));

	dfs(endpoint, 0); //가장 맨 끝 노드부터 가장 먼 노드 찾기
	cout << maxdiameter;
}
