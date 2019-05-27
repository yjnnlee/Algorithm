#include <stdio.h>
int m, res = 0;
int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d", &m);
		res += m;
	}
	printf("%d\n%d", res/60, res%60);
}
