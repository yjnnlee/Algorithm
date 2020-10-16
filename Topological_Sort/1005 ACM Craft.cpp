#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
vector<int> order[1001];
int time[1001], cnt[1001], res[1001]; //자신으로 들어오는 간선의 개수
int s = 0; //sum
queue<int> q;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, k, goal;
	cin >> t;
	while (t--) {
		cin >> n >> k;

		memset(time, 0, sizeof(time));
		memset(cnt, 0, sizeof(cnt));
		memset(res, 0, sizeof(res));
		for (int i = 0; i < 1001; i++) order[i].clear();

		for (int i = 1; i <= n; i++) cin >> time[i];

		for (int i = 0, a, b; i < k; i++) {
			cin >> a >> b;
			order[a].push_back(b);
			cnt[b]++;
		}
		cin >> goal;

		for (int i = 1; i <= n; i++) { //in-degree가 0인 정점 찾기
			if (cnt[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int next : order[now]) {
				res[next] = max(res[next], res[now] + time[now]);
				cnt[next]--; //간선 제거
				if (cnt[next] == 0) q.push(next);
			}
		}

		cout << res[goal] + time[goal] << '\n';
	}

}
