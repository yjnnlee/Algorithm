#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
그대, 그머가 되어
최단 경로(양수) -> 다익스트라
가중치가 없지만, 1로 두고 풀면 된다

가중치가 없으므로, bfs로 풀 수도 있다 (bfs최단거리)
*/
struct Edge {
	int to, cost;
};
vector<Edge> g[10001];

vector<int> go(int v, int e, int s) {
	vector<int> dist(1001, 1e9); //v만큼을 1e9로 초기화
	dist[s] = 0; //시작은 0
	
	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii>> q; //값이 작을수록 우선순위 큐
	//이렇게 하지 않으면, cost에 마이너스를 붙여서 음수화 해야 한다
	//https://yabmoons.tistory.com/364

	q.push({ 0, s }); //출발, 거리는 0
	dist[s] = 0; //처음 문자에서 동일한 문제 거리 0

	while (!q.empty()) {
		int cost = q.top().first; //우선순위를 위해 음수로
		int now = q.top().second; //현재 위치
		q.pop();

		if (dist[now] < cost) continue; //원래 경로가 더 짧다면 패스(원래 방문 경로)

		for (int i = 0;i < g[now].size();i++) {
			int next = g[now][i].to;
			int nextdist = g[now][i].cost + cost;

			if(dist[next]>nextdist){ //더 짧은 경로를 발견했다면
				dist[next] = nextdist;
				q.push({ nextdist, next });
			}
		}
	}
	//cout << dist.size();
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	int a, b;
	cin >> a >> b;
	int n, m;
	cin >> n >> m; //n개의 문자와 치환 가능한 문자쌍 m개
	
	for (int i = 0;i < m;i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back({ y,1 }); // x->y로 가는 가중치는 전부 1로
		g[y].push_back({ x,1 }); //양방향이다
	}

	vector<int> res = go(n, m, a); //정점의 개수, 간선의 개수, 시작 위치

	if (res[b] != 1e9) {
		cout << res[b];
	}
	else cout << -1;

	//for (auto x : res) {
	//	cout << x << " ";
	//}
}
