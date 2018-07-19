//인접행렬->메모리 많이 먹음
/*#include <stdio.h>
const int n_ = 100;

int n, m;
bool gph[100][100];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		gph[u][v] = 1;
	}

	for (int i = 0; i < n; i++) gph[i][i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", gph[i][j]);
		}
	}
}*/

//벡터 사용
/*#include <stdio.h>
#include <vector>
using namespace std;

const int n_ =100;
vector<int> gph[n_];

int main() {
	int n, m, u, v;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		gph[u].push_back(v);
		//u부터 v까지 
	}

}*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

const int n_ = 1e5;

int n, m, s;
bool chk[n_];
vector<int> gph[n _];

void bfs() {
	queue<int> que;
	que.push(s); //시작
	chk[s] = true;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		chk[now] = true;
		printf("%d ", now);
		//for (int i = 0; i < gph[now].size(); i++) {
		for (auto nxt : gph[now]) {
			if (!chk[nxt]) que.push(nxt);
		}
	}
}

void dfs(int now) {
	if (chk[now]) return;
	chk[now] = true;
	printf("%d ", now);
	for (int i = 0; i < gph[now].size(); i++) {
		dfs(gph[now][i]);
	}

	/*for (auto nxt : gph[now]) {
		dfs(nxt);
	}같음*/
}

int main() {
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		gph[u].push_back(v);
	}
	dfs(s);
	memset;
}