#include <stdio.h>
#include <string.h>
int n, tmp, stack[10001], i = 0;
char what[10];

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s", what);
		if (strcmp(what, "push") == 0) {
			scanf("%d", &tmp);
			stack[i++] = tmp;
		}
		else if (strcmp(what, "top") == 0) {
			if (i <= 0) printf("-1\n");
			else printf("%d\n", stack[i-1]);
		}
		else if (strcmp(what, "size") == 0) {
			printf("%d\n", i);
		}
		else if (strcmp(what, "empty") == 0) {
			if (i <= 0) printf("1\n");
			else printf("0\n");
		}
		else if (strcmp(what, "pop") == 0) {
			if (i <= 0) printf("-1\n");
			else printf("%d\n", stack[--i]);
		}
	}
}
