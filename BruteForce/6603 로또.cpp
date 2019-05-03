#include <stdio.h>
int k, s[15], new_s[15];

void dfs(int a, int len) {
	if (len == 6) {
		for (int i = 0; i < 6; i++) printf("%d ", new_s[i]);
		printf("\n");
		return;
	}

	for (int i = a; i < k; i++) {
		new_s[len] = s[i];
		dfs(i + 1, len + 1);
	}
}

int main() {
	while (1) {
		scanf("%d", &k);
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			scanf("%d", &s[i]);
		}

		dfs(0, 0);
		printf("\n");
	}
}
