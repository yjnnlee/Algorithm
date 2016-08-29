#include <stdio.h>

const int MAX_M = 50;

int main() {
	int n, m, k[MAX_M], l[MAX_M], f[MAX_M] = { 0 };

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k[i]);
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &l[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (k[i] == l[j]) f[j] = 1;
		}
	}

	for (int i = 0; i < m; i++) {
		printf("%d\n", f[i]);
	}

	return 0;
}