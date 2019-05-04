#include <stdio.h>
int a, b, n, visit[12];
void combination(int start, int cnt) {
	if (cnt == b) {
		++n;
		return;
	}
	for (int i = start; i < a; i++) {
		if (visit[i] == 1) continue;
		visit[i] = 1;
		combination(i, cnt + 1);
		visit[i] = 0;
	}
}
int main() {
	scanf("%d %d", &a, &b);
	combination(0,0);
	printf("%d", n);
}
