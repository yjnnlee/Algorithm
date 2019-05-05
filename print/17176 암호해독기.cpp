#include <stdio.h>
#include <algorithm>
int n, a[100006], c[100006];
char b[100006];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d ", &a[i]);
	}
	scanf("%[^\n]s", b);

	for (int i = 0; i < n; i++) {
		if ((int)b[i] == 32) c[i] = 0;
		if ((int)b[i] >= 65 && (int)b[i] <= 90) c[i] = (int)b[i] - 64;
		if ((int)b[i] >= 97 && (int)b[i] <= 122) c[i] = (int)b[i] - 70;
	}
	std::sort(a, a + n);
	std::sort(c, c + n);
	for (int i = 0; i < n; i++) {
		if (a[i] != c[i]) {
			printf("n");
			return 0;
		}
	}
	printf("y");
}
