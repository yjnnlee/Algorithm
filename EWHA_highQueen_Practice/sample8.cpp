#include <stdio.h>
#include <string.h>
int n, cnt=0;
char a[60];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", a);
		for (int j = 0; j < strlen(a); j++) {
			if (a[j] == '(') {
				cnt++;
			}
			else {
				cnt--;
			}
			if (cnt < 0) break;
		}

		if (cnt == 0) {
			printf("YES");
		}
		else printf("NO");

		cnt = 0;
	}
}
