#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
//2차원 배열 쓰면 size오버 - 1차원 배열로 사이클 탐지 필요
int visit[1001], done[1001];
int n;
vector<int> v;
int res = 0;
void dfs(int now) {
	int next = v[now]; //가리키고 있는 쪽
	visit[now] = 1;
	if (visit[next]) { //방문을 했던 노드인데 또 탐색하러 오게 되면 사이클이다
		res++;
		return;
	}

	dfs(next); //다음 경로
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
				dfs(i); //사이클 세기
			}
		}

		cout << res << "\n";

		res = 0;
		v.clear();
		memset(visit, 0, sizeof(visit));
		memset(done, 0, sizeof(done));
	}
}
