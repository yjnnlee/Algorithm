#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int a, b, c, n, t, visit[50005], minCost = 0, maxLen = 0, endpoint, res; //maxLen=지름, 가장 끝 노드
vector<pair<int, int>> map[50005];

void dfs(int now, int len, int cost) {
	if (visit[now]) return;
	visit[now] = 1;

	if (maxLen < len) {
		maxLen = len;
		endpoint = now;
		minCost = cost;
	}
	else if (maxLen == len) {
		if (minCost > cost) {
			endpoint = now;
			minCost = cost;
		}
	}

	for (int i = 0; i < map[now].size(); i++) {
		if (!visit[map[now][i].first]) dfs(map[now][i].first, len + 1, map[now][i].second + cost);
	}
}

int main() {
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}

	dfs(1, 1, 0); //가장 멀리 있는 정점 구하기
	maxLen = 0; //가장 긴 지름이면서
	minCost = 0; //가장 적은 가중치
	memset(visit, 0, sizeof(visit));
	dfs(endpoint, 1, 0);

	int day = 1;
	if (minCost % t == 0) day = 0; //안 나눠떨어지면 하루 추가해줘야 함
	printf("%d", minCost/t+day);
}
