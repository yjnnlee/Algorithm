#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int v, e, start, from, to, cost;
vector<pair<int, int>> map[20005]; 
//2차원 배열


vector<int> dijkstra(int v, int e, int s) {
	vector<int> dist(v, 1e9); //v만큼 초기화
	dist[s] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, s));

	while (!q.empty()){
		int cost = -q.top().first; //우선순위를 위해서 음수로 했으니까. 3 2 1 -> -1 -2 -3
		int now = q.top().second;

		q.pop();
		if (dist[now] < cost) continue; //원래 경로가 더 짧다면 무시한다
		for (int i = 0; i < map[now].size(); i++){
			int next = map[now][i].first;
			int nextdist = map[now][i].second + cost;

			if (dist[next] > nextdist){ //더 짧은 경로 발견
				dist[next] = nextdist;
				q.push(make_pair(-nextdist, next));
			}

		}
	}
	return dist;
}

int main(){
	scanf("%d %d %d", &v, &e, &start);
	v++;
	for (int i = 0; i < e;i++){
		scanf("%d%d%d", &from, &to, &cost);
		map[from].push_back(make_pair(to, cost));
	}
	vector<int> res = dijkstra(v, e, start);
	for (int i = 1; i < v; i++){
		if (res[i] == 1e9) printf("INF\n");
		else printf("%d\n", res[i]);
	}
}
