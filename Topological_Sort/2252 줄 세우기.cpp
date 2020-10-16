#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int cnt[32001]; //자신으로 들어오는 엣지의 개수

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	vector<int> g[32001];
	queue<int> q;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		cnt[b]++;
	}
	for (int i = 1; i <= n; i++) { //in-degree가 0인 정점 찾기
		if (cnt[i] == 0) q.push(i);
	}

	while(q.size()){
		int now = q.front();
		q.pop();
		cout << now << " ";

		//in-degree가 0인 정점과 연결된 모든 정점 cnt감소(간선 제거)
		for (int j = 0; j < g[now].size(); j++) {
			int next = g[now][j];
			cnt[next]--;
			if (cnt[next] == 0) q.push(next);
		}
		//for (int next : g[now]) {
		//	cnt[next]--;
		//	if (cnt[next] == 0) q.push(next);
		//}
	}
}
