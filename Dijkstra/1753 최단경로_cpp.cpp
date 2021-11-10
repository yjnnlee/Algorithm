#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to, cost;
};
vector<Edge> map[20001];
typedef pair<int, int> pii;
vector<int> go(int v, int e, int s){
	vector<int> dist(v+1, 1e9); //정점v는 1부터 시작하기 때문임
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({ 0, s }); //cost, now
	dist[s] = 0;

	while(!q.empty()) {
		int cost = q.top().first;
		int now = q.top().second;
		q.pop();

		if (dist[now] < cost) continue;

		for (int i = 0;i < map[now].size();i++) {
			int next = map[now][i].to;
			int nextdist = map[now][i].cost + cost;

			if (nextdist < dist[next]) { //다음 거리<현재까지 발견한 거리
				dist[next] = nextdist;
				q.push({ nextdist, next });
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	int v, e, s;
	cin >> v >> e >> s;

	for (int i = 0;i < e;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
	}
	vector<int> res = go(v, e, s);
	for (int i = 1;i <= v;i++) {
		if (res[i] == 1e9) cout << "INF" << "\n";
		else cout << res[i] << "\n";
	}
}
