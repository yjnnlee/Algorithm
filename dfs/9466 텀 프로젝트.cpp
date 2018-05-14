#include <stdio.h>
#include <memory.h>
#include <algorithm>

int t, n, s[100010], cnt, S;
int chk[100010], finished[100010];

void dfs(int now) {
	printf("e");
	chk[now] = 1;
	int next = s[now];

	if (chk[now]) {
		if (!finished[next]) {
			for (int i = next; i != now; i = s[i]) {
				cnt++; //지금 정점이 시작한 정점으로 돌아오기 전(=사이클)까지 계속 탐색한다
			}
			cnt++; //다 탐색하고 자기 자신도 더한다
		}
	}
	else dfs(next); //체크 되어 있으면 넘어간다

	finished[now] = 1; //끝난 정점을 체크해준다
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		
		cnt = 0;
		memset(chk, 0, sizeof(chk));
		memset(finished, 0, sizeof(finished));

		for (int i = 0; i < n; i++) {
			scanf("%d", s+i);
			s[i]--;
		}
		for (int i = 0; i < n; i++) if (!chk[i]) dfs(i);
		printf("%d\n", n - cnt);
	}

}
