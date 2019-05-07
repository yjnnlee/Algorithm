#include <stdio.h>
#include <algorithm>
using namespace std;
int k, n, m, tmp = 0, ant1 = 0, ant2 = 0;
int main() {
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &tmp);
			ant1 = max(ant1, min(tmp, n - tmp));
			//짧은 경우: 각 개미의 위치서부터 양쪽 끝 중에 가까운 곳으로, 제일 긴 개미
			ant2 = max(ant2, max(tmp, n - tmp));
			//긴 경우: 각 개미의 위치서부터 양쪽 끝 중에 먼 곳으로 갔을 때, 가장 긴 개미
		}
		printf("%d %d\n", ant1, ant2);
		ant1 = 0, ant2 = 0;
	}
}
