#include <stdio.h>
#include <string.h>
char a[5005];
int res = 0, cnt = 0;

int main() {
	scanf("%s", a);
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		if (a[i] == '1') {
			cnt++;
		}
		if (a[i] != '1' || i == (len - 1)) {
			if (res < cnt) {
				res = cnt;
			}
			cnt = 0;
		}
	}
	printf("%d", res);
}
