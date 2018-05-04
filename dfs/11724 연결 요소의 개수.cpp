#include <stdio.h>
#include <vector>
using namespace std;
int n, m, u, v, index, chk[1010], total = 0;
//vector<int> map[30000];
int map[1010][1010];

void dfs(int now){
	chk[now] = 1;
	for (int i = 1; i <= n; i++) {
		if (!chk[i] && map[now][i]) dfs(i);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &u, &v);
		map[u][v] = map[v][u] = 1;
		//map[u].push_back(v);
		//map[v].push_back(u);
	}

	//for (int i = 1; i <= n; i++) {
	//	printf("%d : ", i);
	//	for (int j = 0; j < map[i].size(); j++) {
	//		printf("%d ", map[i][j]);
	//	}
	//	printf("\n");
	//}

	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			total++;
			dfs(i);
		}
	}

	printf("%d", total);
}
