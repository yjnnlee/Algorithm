#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n, goal;
/*
지름길
1. 그냥 가는 것이 지름길보다 같거나 짧으면 그냥 간다 -> 입력 받을 때 처리
2. 가능한 지름길이 여러 개면 더 짧은 거리로 간다
3. 지름길의 목적지가 도착지점을 넘으면 지름길을 이용할 수 없다 -> 입력 받을 때 처리

*/
struct Edge {
	int to, cost;
};
vector<Edge> g[10001];
int dist[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	cin >> n >> goal;
	dist[goal] = goal;
	for (int i = 0;i <= goal;i++) dist[i] = 1e9; //꼭 초기화 해 주어야 함

	for (int i = 0;i < n;i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		if (e - s <= cost) continue; //1번 예외
		if (e > goal) continue;; //3번 예외
		g[s].push_back({ e, cost });
	}
	int prev;
	for (int i = 0;i <= goal;i++) {
		if (i == 0) prev = -1;
		else prev = dist[i - 1];

		dist[i] = min(dist[i], prev + 1); //min(현재, 이전+1)

		for (auto next : g[i]) {//현재 시점에서 갈 수 있는 모든 지름길
			if (dist[next.to] > dist[i] + next.cost) { //이전 길에서 그냥 운전vs지름길을 탔을 때
				dist[next.to] = dist[i] + next.cost; //지름길이 이득이면 지름길로
			}
		}
	}
	cout << dist[goal];
}
