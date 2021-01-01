#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int n;
vector<int> tree[100001];
int parent[100001], visit[100001];

void dfs(int now) {
	visit[now] = 1;
	for (int i = 0; i < tree[now].size(); i++) { //연결된 모든 노드 확인
		int next = tree[now][i];
		if (!visit[next]) { //다음 노드 미방문이면
			parent[next] = now; //현재 노드가 다음 노드의 부모라고 저장
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}
}
