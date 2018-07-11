#include <stdio.h>
#include <string.h>
char a[1000000];

int main() {
	while (1) {
		bool chk = true;
		scanf("%s", &a);
		if (a[0] == '0') break;

		int n = strlen(a);

		for (int i = 0; i < n; i++) {
			if (a[i] != a[n - i - 1]) {
				chk = false;
				break;
			}
		}
		if (chk) printf("yes\n");
		else printf("no\n");
	}
}
