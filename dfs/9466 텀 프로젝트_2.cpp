#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
//2차원 배열 쓰면 size오버 - 1차원 배열로 사이클 탐지 필요
int visit[100001], done[100001];
int n;
vector<int> v;
void dfs(int now, vector<int> &cycle) {
	int next = v[now]; //가리키는 거
	cycle.push_back(now); //방문한 애들 저장
	if (visit[next]) { //방문을 했던 노드인데 또 탐색하러 오게 되면 사이클이다
		if (cycle.size() == 0) return; //암것도 없으면 패스

		int i;
		for (i = 0; i < cycle.size(); i++) { //방문한 애들 중에 사이클이 시작되는 인덱스를 찾음
			if (cycle[i] == v[now]) break;
		}

		for (int j = i; j < cycle.size(); j++) {
			done[cycle[j]] = 1; //사이클에 소속된 사람들 체크. 시작 인덱스부터 끝까지는 다 사이클임
		}
		return;
	}

	visit[now] = 1;
	dfs(next, cycle); //다음 경로
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		v.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				vector<int> cycle;
				dfs(i, cycle); //사이클 세기
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (done[i] == 0) cnt++;
		}
		cout << cnt << "\n";

		cnt = 0;
		v.clear();
		memset(visit, 0, sizeof(visit));
		memset(done, 0, sizeof(done));
	}
}
