#include <stdio.h>
#include <string.h>
char a[105][105], n;
int chk[100], res = 0;

void f(char str[]) {
	int nn = strlen(str);
	for (int i = 0; i < nn; i++) {
		if (chk[str[i] - 'a']) return;
		else {
			chk[str[i] - 'a'] = 1;
			char tmp = str[i];
			while (1) {
				if (str[++i] != tmp) {
					i--;
					break;
				}
			}
		}
	}
	res++;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for (int i = 0; i < n; i++) {
		memset(chk, 0, sizeof(chk));
		f(a[i]);
	}
	printf("%d", res);
}
