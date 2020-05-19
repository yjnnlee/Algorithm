#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[501];
int n, m, res = 0;
bool friends[501];

void find(int now) {
	for (int i = 0; i < tree[now].size(); i++) { //now의 친구 파악
		int next = tree[now][i];
		friends[next] = true;
	}

	if (now == 1) { //1번의 친구 파악
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			find(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	//vector<vector<int>> tree(n);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	find(1);
	for (int i = 2; i <= n; i++) {
		if (friends[i]) res++;
	}
	cout << res;
} 
