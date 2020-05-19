#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> tree[100001];
int parent[100001], visit[100001];

void solve(int now) {
	visit[now] = 1;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (!visit[next]) {
			parent[next] = now;
			solve(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	solve(1);
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

}
