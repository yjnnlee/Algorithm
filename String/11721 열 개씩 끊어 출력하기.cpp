#include <stdio.h>
#include <string.h>
char a[105];
int b = 0, len;
int main() {
	scanf("%s", a);
	len = strlen(a);
	for (int i = 0; i < len; i++) {
		if (b == 10) {
			printf("\n");
			b = 0;
		}
		printf("%c", a[i]);
		++b;
	}
}
