#include <iostream>
#include <vector>
using namespace std;
int n, m, cnt = 0;
vector<int> map[101];
bool visit[101];

void solve(int now) {
	visit[now] = 1;

	for (int i = 0; i < map[now].size(); i++) {
		int next = map[now][i];

		if (!visit[next]){
			solve(next);
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	solve(1);
	cout << cnt;
}
