#include <stdio.h>
int a, res = 0;
char s[1000];

int main() {
	scanf("%d %s", &a, s);
	while (a--) {
		res += (int)s[a] - 48;
//		printf("%d\n", (int)s[a]);
	}
	printf("%d", res);
}
