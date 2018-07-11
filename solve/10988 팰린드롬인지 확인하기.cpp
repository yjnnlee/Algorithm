#include <stdio.h>
#include <string.h>
char a[200];
bool chk = true;

int main() {
	scanf("%s", &a);
	int n = strlen(a);

	for (int i = 0; i < n; i++) {
		if (a[i] != a[n - i - 1]) {
			chk = false;
			break;
		}
	}
	if (chk) printf("1");
	else printf("0");
}
