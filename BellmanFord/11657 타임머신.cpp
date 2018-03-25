#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int v, e, dist[505];
vector<pair<int, int>> p[505];

void bellmanFord() {
	vector<int> dist(v, INF);
	dist[0] = 0;
	bool minuschk = false;

	//v번 반복하고 마지막 반복에서도 갱신되면 음의 사이클 있음
	for (int i = 0; i < v; i++) {
		for (int now = 0; now < v; now++) {
			for (int k = 0; k < p[now].size(); k++) {
				int there = p[now][k].first;
				int cost = p[now][k].second;

				if (dist[there] > dist[now] + cost) {
					dist[there] = dist[now] + cost;

					if (i == (v - 1)) minuschk = true; //n번째에서 갱신되면 사이클
				}
			}
		}
	}
	if (minuschk) printf("-1\n");
	else {
		for (int i = 1; i < v; i++) {
			if (dist[i] != INF) printf("%d\n", dist[i]);
			else printf("-1\n");
		}
	}
}

int main() {
	scanf("%d%d", &v, &e);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		p[a - 1].push_back(make_pair(b - 1, c));
	}
	bellmanFord();
}
