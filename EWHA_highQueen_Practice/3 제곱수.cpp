#include <stdio.h>
int n, m;
bool is = false;

int main() {
	scanf("%d %d", &n, &m);
	for (int j = 1; j <= m; j++) {
		if (j*j >= n && j*j <= m) {
			printf("%d ", j*j);
			is = true;
		}
	}
	if (!is) printf("0");
}
