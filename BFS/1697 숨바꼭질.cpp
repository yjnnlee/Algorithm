#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, k, chk[100005];
queue<pair<int,int>> q;

int bfs(int start) {
	q.push(make_pair(start, 0));
	chk[start] = 1;
	int res, now;

	if (n == k) return 0;
	else {
		while (!q.empty()) {
			now = q.front().first; //현재
			res = q.front().second; //누적 거리
			q.pop();
			
			if (now + 1 <= 100000 && !chk[now + 1] && now < k) {
				q.push(make_pair(now + 1, res + 1));
				chk[now + 1] = 1;
			}
			if (now - 1 >= 0 && !chk[now - 1]) {
				q.push(make_pair(now - 1, res + 1));
				chk[now - 1] = 1;
			}
			if (now * 2 <= 100000 && !chk[now * 2] && now < k) {
				q.push(make_pair(now * 2, res + 1));
				chk[now * 2] = 1;
			}

			if (now - 1 == k || now + 1 == k || now * 2 == k) {
				break;
			}
		}
	}
	return ++res;
}

int main() {
	scanf("%d %d", &n, &k);
	printf("%d", bfs(n));
}
