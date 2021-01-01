#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;
int n;
struct Node {
	int index, len;
};
vector<Node> tree[100001];
int parent[100001], visit[100001];
int maxLen = 0, maxNode = 0;

void dfs(int now, int nowLen) {
	if (visit[now]) return;
	if (maxLen < nowLen) { //최대 거리, 최대 정점 갱신
		maxLen = nowLen;
		maxNode = now;
	}
	visit[now] = 1;
	for (int i = 0; i < tree[now].size(); i++) { //연결된 모든 노드 확인
		int next = tree[now][i].index;
		int nextLen = tree[now][i].len;
		dfs(next, nowLen + nextLen);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		while (1) {
			int b;
			cin >> b;
			if (b == -1) break;
			int c;
			cin >> c;

			tree[a].push_back({ b,c });
			tree[b].push_back({ a,c });
		}
	}
	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	maxLen = 0;
	dfs(maxNode, 0); //정점1에서 가장 먼 정점을 기준으로 최대 거리 정점 구하기
	cout << maxLen;
}
