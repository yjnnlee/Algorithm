#include <stdio.h>
#include <vector>
using namespace std;
int k, n, f, rel[5603][5603], chk[5603];
bool done = false;
vector<int> friends(5063); //친구를 이어준 목록

void dfs(int now) {
	chk[now] = 1;
	friends.push_back(now); //이어진 친구 목록에 추가
	if (friends.size()== k) {
		done = true;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (chk[i] == 0) {
			bool isallfriend = true;
			for (int j = 0; j < friends.size(); j++) {
				if (rel[friends[j]][i] == 0) { //하나라도 친구가 아니면 이놈은 아님
					isallfriend = false;
					break;
				}
			}
			if (isallfriend) dfs(i); //전부 친구면 계속 따라감
		}
	}
	return;
}
int main() {
	scanf("%d %d %d", &k, &n, &f);
	for (int i = 1; i <= f; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		rel[tmp1][tmp2] = 1;
		rel[tmp2][tmp1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			chk[j] = 0; //dfs돌 때마다 초기화
		}
		friends.clear();
		dfs(i);
		if (done) break;
	}
	if (done) {
		for (int i = 0; i < k; i++) {
			printf("%d\n", friends[i]);
		}
	}
	else printf("-1");
}
