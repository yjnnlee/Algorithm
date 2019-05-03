#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
int height[10], visit[10], res[10];

void solve() {
	int p = 0, sum = 0;
	for (int j = 0; j < 9; j++) {
		if (visit[j]) {
			sum += height[j];
			res[p++] = height[j];
		}
	}
	if (sum == 100) {
		std::sort(res, res + p);
		for (int j = 0; j < p; j++) printf("%d\n", res[j]);
		exit(0);
	}
}

void Combination(int start, int cnt) {
	if (cnt == 7) {
		solve();
		return;
	}
	for (int i = start; i < 9; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		Combination(i, cnt + 1);
		visit[i] = 0;
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
	}
	Combination(0, 0);
}
