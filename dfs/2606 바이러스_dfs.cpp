#include <iostream>
using namespace std;

int n, m, com[101][101], chk[101], res = 0;

void dfs(int now) {
	res++;
	chk[now] = 1;
	for (int i = 1; i <= n; i++) {
		if (!chk[i] && com[now][i]) {
			chk[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	cin>> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		com[a][b] = 1;
		com[b][a] = 1;
	}
	dfs(1);
	cout << res-1;
}
