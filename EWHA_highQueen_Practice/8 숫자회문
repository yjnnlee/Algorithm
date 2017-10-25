#include <stdio.h>
#include <string.h>
int a, n;
char aa[1000];

int main() {
	scanf("%d", &a);
	sprintf(aa, "%d", a);
	n = strlen(aa);
	for (int i = 0; i <n; i++) {
		if (aa[i] != aa[n - 1 - i]) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}
